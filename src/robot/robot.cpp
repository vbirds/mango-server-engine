#include "protocol/external_message.pb.h"
#include "protocol/proto_msgid.pb.h"

#include "robot_conn.h"
#include "robot_user.h"
#include "message/client_message_handler.h"

#include "tloghelp/tlogload.h"

LPTLOGCTX pLogCtx = NULL;

static BOOL do_init(void)
{
	int32_t nRetCode = 0;

#if defined(WIN32)
	WSADATA wsaData;
	nRetCode = WSAStartup(0x202, &wsaData);
	LOG_PROCESS_ERROR(nRetCode == 0);
#endif	// WIN32

	pLogCtx = tlog_init_from_file("./tlog.xml");
	LOG_PROCESS_ERROR(pLogCtx);

	g_pSvrLogCat = tlog_get_category(pLogCtx, "text");
	LOG_PROCESS_ERROR(g_pSvrLogCat);
	
	nRetCode = CRobotConnMgr::instance().init();
	LOG_PROCESS_ERROR(nRetCode);

	nRetCode = CRobotUserMgr::instance().init();
	LOG_PROCESS_ERROR(nRetCode);

	nRetCode = CClientMessageHandler::instance().init();
	LOG_PROCESS_ERROR(nRetCode);

	{
		CRobotUser* pUser = NULL;

		pUser = CRobotUserMgr::instance().create_user("test");
		LOG_PROCESS_ERROR(pUser);

		nRetCode = pUser->connect("tcp://127.0.0.1:8888");
		LOG_PROCESS_ERROR(nRetCode);
	}
	
	return TRUE;
Exit0:
	return FALSE;
}

BOOL do_fini()
{
	int32_t nRetCode = 0;

	nRetCode = CClientMessageHandler::instance().uninit();
	LOG_CHECK_ERROR(nRetCode);

	nRetCode = CRobotConnMgr::instance().fini();
	LOG_CHECK_ERROR(nRetCode);

	nRetCode = CRobotUserMgr::instance().fini();
	LOG_CHECK_ERROR(nRetCode);

	return TRUE;
Exit0:
	return FALSE;
}

static BOOL do_mainloop(int argc, char** argv)
{
	int32_t nRetCode = 0;

	while (true)
	{
		CRobotUserMgr::instance().mainloop();
	}

	return TRUE;
}

int32_t main(int argc, char** argv)
{
	int32_t nRetCode = 0;

	nRetCode = do_init();
	LOG_PROCESS_ERROR(nRetCode);

	nRetCode = do_mainloop(argc, argv);
	LOG_PROCESS_ERROR(nRetCode);

	nRetCode = do_fini();
	LOG_PROCESS_ERROR(nRetCode);
	
	return 0;

Exit0:
	return -1;
}

