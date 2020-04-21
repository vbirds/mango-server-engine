ServerConfig.Common = 
{
	nTestValue = 1;
	nInitBtCtxCount = 100;
	nInitBtEventCount = 100;
	nInitBtGlobalEventListCount = 100;
	nInitTimerPoolCount = 100;

	nInitShmSize = 100 * 1024 * 1024;
		
	nServerStopTimeout = 20 * 1000;
	nServerEndWaitTimeout = 3 * 1000;

    DumpConfig =
    {
        bIsMiniDump = false,
        nDumpInterval = 30 * 60 * 1000,
    },
}