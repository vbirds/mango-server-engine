#ifndef  _COMMON_INC_H_
#define  _COMMON_INC_H_

//tbase
#include "pal/ttypes.h"
#include "tapp/tapp.h"
#include "tdr/tdr.h"

//lua
#if defined(__cplusplus) 
	extern "C"
	{
	#include "lualib.h"
	#include "lauxlib.h"
	#include "toluapp.h"
	}
#else
	#include "lualib.h"
	#include "lauxlib.h"
	#include "toluapp.h"
#endif

#include "file/ifile.h"

#include "lua/lua_script.h"
#include "lua/script_mgr.h"

#include "math/utf8.h"
#include "math/hash.h"
#include "math/crc32.h"
#include "math/crc32c_fast.h"
#include "math/math_ex.h"

#include "process_error/process_error.h"
#include "file/ifile.h"
#include "string/string_ex.h"

#include "shm/shm_pool.h"

#endif   /* ----- #ifndef _COMMON_INC_H_  ----- */

