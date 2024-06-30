message(STATUS "Building game library")

include_directories(
	${PLATFORM_INCLUDES}
	${GAME_INCLUDES}
)

set(GAME_SOURCES
	"Test.cpp"
)

set(GAME_HEADERS
	"Test.hpp"
)

add_library(PROJ_GAME ${GAME_SOURCES} ${GAME_HEADERS})

message(STATUS "Building game library - done")