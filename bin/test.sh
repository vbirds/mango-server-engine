#!/bin/sh

cd router_server && ./start_server.bat && cd ..
cd service_mgr_server && ./start_server.bat && cd ..
cd tconnd && ./start_tconnd.bat && cd ..
cd server && ./start_server.bat && cd ..
cd func_server && ./start_server.bat && cd ..