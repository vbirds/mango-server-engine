pre_project (STATIC LIB)

file (GLOB_RECURSE MISC_FILES 
	"${BASE_DIR}/inc/define/*.h"
	"${BASE_DIR}/inc/protocol/*.h"
	"${BASE_DIR}/bin/server_config/*.lua"
	"${BASE_DIR}/bin/script/*.lua"
	"${BASE_DIR}/src/proto/db/*.proto"
	"${BASE_DIR}/src/proto/db/*.h"
	"${BASE_DIR}/src/proto/db/*.cc"
	"${BASE_DIR}/src/proto/protocol/*.proto"
	"${BASE_DIR}/src/proto/protocol/*.h"
	"${BASE_DIR}/src/proto/protocol/*.cc"
)
set (SRC_FILES ${SRC_FILES} ${MISC_FILES})

list (APPEND SRC_FILES
	"${BASE_DIR}/build/CMakeLists.txt"
	"${BASE_DIR}/build/precompile.cmake"
	"${BASE_DIR}/build/project.cmake"
	"${BASE_DIR}/build/proto.cmake"
	"${BASE_DIR}/build/toluapp.cmake"
)

list (APPEND SRC_FILES
	"${BASE_DIR}/bin/tools/deploy/config/hosts.yml"
	"${BASE_DIR}/bin/tools/deploy/config/local_deploy.yml"
	"${BASE_DIR}/bin/tools/deploy/config/proc.yml"
	"${BASE_DIR}/bin/tools/deploy/config/tcm_deploy.yml"
	"${BASE_DIR}/bin/tools/deploy/local/configure.py"
)

process_proto("src/proto")

add_project ()

post_project ()
