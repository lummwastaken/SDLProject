message(STATUS "Building platform library")

include_directories(
	${PLATFORM_INCLUDES}
)

set(PLATFORM_SOURCES
	"render/Renderer.cpp"
	"window/Window.cpp"
)

set(PLATFORM_HEADERS
	"render/Renderer.hpp"
	"utils/Types.hpp"
	"window/Window.hpp"
)

add_library(PROJ_PLATFORM ${PLATFORM_SOURCES} ${PLATFORM_HEADERS})
target_include_directories(PROJ_PLATFORM PRIVATE ${EXTERNAL_INCLUDES})

message(STATUS "Building platform library - done")