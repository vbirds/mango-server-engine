#include "stdafx.h"
#include "module/gs_user_module.h"

#include "config/global_config.h"
#include "db/user_db_data.pb.h"
#include "db/role_db_data.pb.h"

BOOL CUserModule::init(BOOL bResume)
{
    int32_t nRetCode = 0;

    nRetCode = m_UserPool.init(stdUser, g_ServerConfig.GS.nUserCount, bResume);
    LOG_PROCESS_ERROR(nRetCode);

    nRetCode = _init_msg_handler();
    LOG_PROCESS_ERROR(nRetCode);

    return TRUE;
Exit0:
    return FALSE;
}

BOOL CUserModule::uninit()
{
    int32_t nRetCode = 0;

    nRetCode = m_UserPool.uninit();
    LOG_CHECK_ERROR(nRetCode);

    return TRUE;
}

void CUserModule::on_frame()
{
    return;
}

BOOL CUserModule::kick_user(USER* pUser)
{
    LOG_PROCESS_ERROR(pUser);

    return TRUE;
Exit0:
    return FALSE;
}
    
BOOL USER::is_role(uint64_t qwRoleID)
{
    for (int32_t i = 0; i < nRoleCount; i++)
    {
        if (stRoleBase[i].qwRoleID == qwRoleID)
            return TRUE;
    }
    return FALSE;
}
    
BOOL USER::save_user(char* pData, uint32_t &dwSize)
{
    int32_t nRetCode = 0;
    USER_DB::USER_DATA UserData;

    LOG_PROCESS_ERROR(pData);
    LOG_PROCESS_ERROR(dwSize > 0);

    UserData.set_user_id(qwUserID);
    UserData.set_ban_end_time(dwBanEndTime);
    UserData.set_ban_reason(szBanReason);

    nRetCode = UserData.SerializeToArray(pData, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    dwSize = UserData.GetCachedSize();

    return TRUE;
Exit0:
    return FALSE;
}

BOOL USER::load_user(const char* pData, uint32_t dwSize)
{
    int32_t nRetCode = 0;
    USER_DB::USER_DATA UserData;

    LOG_PROCESS_ERROR(pData);
    LOG_PROCESS_ERROR(dwSize > 0);

    nRetCode = UserData.ParseFromArray(pData, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    qwUserID = UserData.user_id();
    dwBanEndTime = UserData.ban_end_time();
    strxcpy(szBanReason, UserData.ban_reason().c_str(), sizeof(szBanReason));

    return TRUE;
Exit0:
    return FALSE;
}

BOOL USER::save_role_base(uint64_t qwRoleID, char* pData, uint32_t &dwSize)
{
    int32_t nRetCode = 0;
    ROLE_BASE* pRoleBase = NULL;
    ROLE_DB::ROLE_BASE_DATA RoleBaseData;

    LOG_PROCESS_ERROR(pData);
    LOG_PROCESS_ERROR(dwSize > 0);

    for (int32_t i = 0; i < nRoleCount; i++)
    {
        if (stRoleBase[i].qwRoleID == qwRoleID)
        {
            pRoleBase = &stRoleBase[i];
            break;
        }
    }
    LOG_PROCESS_ERROR(pRoleBase);

    RoleBaseData.set_role_id(pRoleBase->qwRoleID);
    RoleBaseData.set_role_name(pRoleBase->szRoleName);
    RoleBaseData.set_level(pRoleBase->wLevel);

    RoleBaseData.set_create_time(pRoleBase->dwCreateTime);
    RoleBaseData.set_last_login_time(pRoleBase->dwLastLoginTime);
    RoleBaseData.set_last_save_time(pRoleBase->dwLastSaveTime);

    nRetCode = RoleBaseData.SerializeToArray(pData, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    dwSize = RoleBaseData.GetCachedSize();

    return TRUE;
Exit0:
    return FALSE;
}

BOOL USER::load_role_base(const char* pData, uint32_t dwSize)
{
    int32_t nRetCode = 0;
    ROLE_DB::ROLE_BASE_DATA RoleBaseData;
    
    LOG_PROCESS_ERROR(pData);
    LOG_PROCESS_ERROR(dwSize > 0);

    nRetCode = RoleBaseData.ParseFromArray(pData, dwSize);
    LOG_PROCESS_ERROR(nRetCode);

    for (int32_t i = 0; i < nRoleCount; i++)
    {
        if (stRoleBase[i].qwRoleID == RoleBaseData.role_id())
            LOG_PROCESS_ERROR(FALSE);
    }

    stRoleBase[nRoleCount].qwRoleID = RoleBaseData.role_id();
    strxcpy(stRoleBase[nRoleCount].szRoleName, RoleBaseData.role_name().c_str(), COMMON_NAME_LEN);
    stRoleBase[nRoleCount].wLevel = RoleBaseData.level();
    stRoleBase[nRoleCount].dwCreateTime = RoleBaseData.create_time();
    stRoleBase[nRoleCount].dwLastLoginTime = RoleBaseData.last_login_time();
    stRoleBase[nRoleCount].dwLastSaveTime = RoleBaseData.last_save_time();

    nRoleCount++;

    return TRUE;
Exit0:
    return FALSE;
}