#include "stdafx.h"
#include "conn_module.h"
#include "conn_msg_handler.h"

#include "app/server_msg_handler.h"
#include "app/server_app.h"

#include "tconnd/inc/tconnapi/tframehead.h"

#include "define/server_def.h"
#include "define/error_def.h"
#include "define/conn_def.h"

#include "time/time_mgr.h"

#include "protocol/conn_message.h"
#include "protocol/proto_head.pb.h"

#include "tbus/tbus_wrapper.h"

BOOL broadcast_to_tconnd(int32_t nConnAddr, const char* pBuffer, uint32_t dwSize);

void on_conn_start(uint64_t qwConnID, TFRAMEHEAD* pFrameHead, const char* pBuff, int32_t nSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_SESSION* pSession = NULL;
    CONN_NTF_EVENT msg;
    const TFRAMECMDSTART& start = pFrameHead->stCmdData.stStart;

	INF("recv start conn, conn_id %llu buff_size %d", qwConnID, nSize);

	pFrameHead->iID = pFrameHead->iConnIdx;
	//conn = pFrameHead->iID;

    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    if (pModule->find_session(qwConnID))
    {
        pModule->kick_conn_by_session(qwConnID, errConnAlreadyExist, 0);
    }

    pSession = pModule->new_session(qwConnID);
    LOG_PROCESS_ERROR(pSession);

    pSession->nConnIndex = pFrameHead->iConnIdx;
    pSession->nConnAddr = GET_TCONND_ADDR(qwConnID);
    pSession->dwInterIP = start.stSIPInfo.ulIp;
    pSession->dwInterPort = start.stSIPInfo.wPort; 
    pSession->dwOuterIP = pFrameHead->stExtraInfo.stIPInfo.ulIp;
    pSession->dwOuterPort = pFrameHead->stExtraInfo.stIPInfo.wPort;
    pSession->nBackendAddr = 0;
    pSession->nClientType = start.iClientType;
    strxcpy(pSession->szUserStr, start.stUserAccount.stValue.szSTRING, sizeof(pSession->szUserStr));
    pSession->dwLastPingTime = CTimeMgr::instance().get_time_sec();

	nRetCode = send_conn_msg(GET_TCONND_ADDR(qwConnID), pFrameHead, NULL, 0);
    LOG_PROCESS_ERROR(nRetCode);

    //send to back end server
    msg.nEventType = cetStart;
    msg.qwConnID = qwConnID;
    strxcpy(msg.szOpenID, pSession->szUserStr, sizeof(msg.szOpenID));
    nRetCode = send_server_msg_by_routerid(hash_string(pSession->szUserStr), svrGS, conn_ntf_event, &msg, sizeof(msg));
    LOG_PROCESS_ERROR(nRetCode);

Exit0:
    return;
}

void on_conn_stop(uint64_t qwConnID, TFRAMEHEAD* pFrameHead, const char* pBuff, int32_t nSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_SESSION* pSession = NULL;
    CONN_NTF_EVENT msg;
	
    INF("recv stop conn, conn_id %llu buff_size %d", qwConnID, nSize);
    
    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    pSession = pModule->find_session(qwConnID);
    LOG_PROCESS_ERROR(pSession);

    //send to back end server
    msg.qwConnID = qwConnID;
    msg.nEventType = cetStop;

    if (pSession->nBackendAddr > 0)
    {
        nRetCode = send_server_msg_by_addr(pSession->nBackendAddr, conn_ntf_event, &msg, sizeof(msg));
        LOG_CHECK_ERROR(nRetCode);
    }
    
    nRetCode = pModule->del_session(pSession);
    LOG_CHECK_ERROR(nRetCode);


Exit0:
    return;
}

void on_conn_proc(uint64_t qwConnID, TFRAMEHEAD* pFrameHead, const char* pBuff, int32_t nSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_SESSION* pSession = NULL;
	uint32_t dwTotalSize = sizeof(CONN_TRANSFER_MSG) + nSize;
    CONN_TRANSFER_MSG* msg = (CONN_TRANSFER_MSG*)alloca(dwTotalSize);

    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    pSession = pModule->find_session(qwConnID);
    LOG_PROCESS_ERROR(pSession);
    LOG_PROCESS_ERROR(pSession->nBackendAddr > 0);

    pSession->dwLastPingTime = CTimeMgr::instance().get_time_sec();

    msg->qwConnID = qwConnID;
    msg->nMsgSize = nSize;
    memcpy(msg->szMsg, pBuff, nSize);

    nRetCode = send_server_msg_by_addr(pSession->nBackendAddr, conn_transfer_msg, msg, dwTotalSize);
    LOG_PROCESS_ERROR(nRetCode);

Exit0:
    return;
}

void on_conn_stop_notify(uint64_t qwConnID, TFRAMEHEAD* pFrameHead, const char* pBuff, int32_t nSize)
{
    INF("recv conn stop notify from conn %llu", qwConnID);
}

void on_gs_business_event(SSMSG_CONTEXT* pCtx, const char* pBuffer, size_t dwSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_BUSINESS_EVENT* msg = (CONN_BUSINESS_EVENT*)pBuffer;

    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    switch (msg->nEventType)
    {
    case cetStop:
    {
        nRetCode = pModule->kick_conn_by_session(msg->qwConnID, (int32_t)msg->qwEventParam0, msg->qwEventParam1);
        LOG_PROCESS_ERROR(nRetCode);
        break;
    }
    default:
        LOG_PROCESS_ERROR(FALSE);
        break;
    }

Exit0:
    return;
}

void on_gs_ntf_event_ack(SSMSG_CONTEXT* pCtx, const char* pBuffer, size_t dwSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_SESSION* pSession = NULL;
    CONN_NTF_EVENT_ACK* msg = (CONN_NTF_EVENT_ACK*)pBuffer;

    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    pSession = pModule->find_session(msg->qwConnID);
    LOG_PROCESS_ERROR(pSession);

    if(msg->nEventType == cetStart)
        pSession->nBackendAddr = pCtx->nRealSrcServerAddr;

    INF("recv conn event ack from %s, conn %lld event %d", tbus_get_str(pCtx->nRealSrcServerAddr), msg->qwConnID, msg->nEventType);

Exit0:
    return;
}

void on_gs_multicast_msg(SSMSG_CONTEXT* pCtx, const char* pBuffer, size_t dwSize)
{
	int32_t nRetCode = 0;
    CONN_SESSION* pSession = NULL;
    CConnModule* pModule = NULL;
	std::map<int32_t, TFRAMEHEAD> mFrameHeadMap;
	CONN_MULTICAST_MSG* msg = (CONN_MULTICAST_MSG*)pBuffer;
    
	pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

	for (int32_t i = 0; i < msg->nConnIDCount; i++)
	{
		pSession = pModule->find_session(msg->qwConnID[i]);
		LOG_CHECK_ERROR(pSession);

		if(pSession == NULL)
			continue;

		if (mFrameHeadMap.find(pSession->nConnAddr) == mFrameHeadMap.end())
		{
			TFRAMEHEAD stFrameHead = { 0 };
			stFrameHead.chCmd = TFRAMEHEAD_CMD_INPROC;
			stFrameHead.stCmdData.stInProc.chValid = 1;

			mFrameHeadMap[pSession->nConnAddr] = stFrameHead;
		}

		TFRAMEHEAD& stFrameHead = mFrameHeadMap[pSession->nConnAddr];
		int16_t rCount = stFrameHead.stCmdData.stInProc.nCount;

		stFrameHead.stCmdData.stInProc.astIdents[rCount].iConnIdx = pSession->nConnIndex;
		stFrameHead.stCmdData.stInProc.astIdents[rCount].iID = pSession->nConnIndex;
		rCount++;
	}

	for (std::map<int32_t, TFRAMEHEAD>::iterator it = mFrameHeadMap.begin(); it != mFrameHeadMap.end(); it++)
	{
		nRetCode = send_conn_msg(it->first, &(it->second), pBuffer, dwSize);
		LOG_CHECK_ERROR(nRetCode);
	}

Exit0:
	return;
}

void on_gs_broadcast_msg(SSMSG_CONTEXT* pCtx, const char* pBuffer, size_t dwSize)
{
	int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_BROADCAST_MSG* msg = (CONN_BROADCAST_MSG*)pBuffer;
    
	pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

	for (int32_t i = 0; i < pModule->get_tconnd_count(); i++)
	{
		nRetCode = broadcast_to_tconnd(pModule->get_tconnd_by_index(i), pBuffer, dwSize);
		LOG_CHECK_ERROR(nRetCode);
	}
Exit0:
	return;
}

void on_gs_transfer_msg(SSMSG_CONTEXT* pCtx, const char* pBuffer, size_t dwSize)
{
    int32_t nRetCode = 0;
    CConnModule* pModule = NULL;
    CONN_SESSION* pSession = NULL;
    CONN_TRANSFER_MSG* msg = (CONN_TRANSFER_MSG*)pBuffer;

    pModule = MG_GET_MODULE(CConnModule);
    LOG_PROCESS_ERROR(pModule);

    pSession = pModule->find_session(msg->qwConnID);
    LOG_PROCESS_ERROR(pSession);

    nRetCode = send_to_client(pSession, msg->szMsg, msg->nMsgSize);
    LOG_PROCESS_ERROR(nRetCode);

Exit0:
    return;
}

BOOL CConnModule::_init_msg_handler()
{
    int32_t nRetCode = 0;

	register_conn_msg_handler(TFRAMEHEAD_CMD_START, on_conn_start);
	register_conn_msg_handler(TFRAMEHEAD_CMD_STOP, on_conn_stop);
    register_conn_msg_handler(TFRAMEHEAD_CMD_INPROC, on_conn_proc);
    register_conn_msg_handler(TFRAMEHEAD_CMD_TCONND_STOP_NOTIFY, on_conn_stop_notify);

	register_server_msg_handler(conn_broadcast_msg, on_gs_broadcast_msg);
	register_server_msg_handler(conn_multicast_msg, on_gs_multicast_msg);

    register_server_msg_handler(conn_transfer_msg, on_gs_transfer_msg);
    register_server_msg_handler(conn_ntf_event_ack, on_gs_ntf_event_ack);
    register_server_msg_handler(conn_business_event, on_gs_business_event);

    return TRUE;
}

static BOOL send_to_tconnd(CONN_SESSION* pSession, int32_t nCmd, int32_t nMsgID, const google::protobuf::Message& msg)
{
	SC_HEAD Head;
    int32_t nRetCode = 0;
    TFRAMEHEAD FrameHead = {0};

	Head.set_msgid(nMsgID);
	Head.set_seqid(0);
	
    FrameHead.chCmd = TFRAMEHEAD_CMD_INPROC;
	FrameHead.stCmdData.stInProc.chValid = 0;
	FrameHead.iConnIdx = pSession->nConnIndex;
	FrameHead.iID = pSession->nConnIndex;

	nRetCode = send_conn_msg(pSession->nConnAddr, &FrameHead, &Head, &msg);
	LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}

BOOL send_to_tconnd(CONN_SESSION* pSession, int32_t nCmd, const char* pBuffer, uint32_t dwSize)
{
    int32_t nRetCode = 0;
    TFRAMEHEAD FrameHead = { 0 };

    FrameHead.chCmd = nCmd;
    FrameHead.iID = pSession->nConnIndex;
    FrameHead.iConnIdx = pSession->nConnIndex;

    nRetCode = send_conn_msg(pSession->nConnAddr, &FrameHead, pBuffer, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}

BOOL send_to_client(CONN_SESSION* pSession, int32_t nMsgID, const google::protobuf::Message& msg)
{
    int32_t nRetCode = 0;

    nRetCode = send_to_tconnd(pSession, TFRAMEHEAD_CMD_INPROC, nMsgID, msg);
    LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}

BOOL send_to_client(CONN_SESSION* pSession, const char* pBuffer, uint32_t dwSize)
{
    int32_t nRetCode = 0;

    nRetCode = send_to_tconnd(pSession, TFRAMEHEAD_CMD_INPROC, pBuffer, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}

BOOL broadcast_to_tconnd(int32_t nConnAddr, const char* pBuffer, uint32_t dwSize)
{
    int32_t nRetCode = 0;
    TFRAMEHEAD FrameHead = { 0 };

    FrameHead.chCmd = TFRAMEHEAD_CMD_BROADCAST;

    nRetCode = send_conn_msg(nConnAddr, &FrameHead, pBuffer, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}
