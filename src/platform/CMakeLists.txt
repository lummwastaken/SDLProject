message(STATUS "Building platform library")

include_directories(
	${PLATFORM_INCLUDES}
)

set(PLATFORM_SOURCES
	"render/Renderer.cpp"
	"render/texture/Texture.cpp"
	"utils/logging/Logger.cpp"
	"window/Window.cpp"
)

set(PLATFORM_HEADERS
	"render/Renderer.hpp"
	"render/sprite/ISprite.hpp"
	"render/texture/Texture.hpp"
	"utils/logging/Logger.hpp"
	"window/Window.hpp"
)

add_library(PROJ_PLATFORM ${PLATFORM_SOURCES} ${PLATFORM_HEADERS})
target_include_directories(PROJ_PLATFORM PRIVATE ${EXTERNAL_INCLUDES})
target_precompile_headers(PROJ_PLATFORM PRIVATE
	# Errors/File management
	[["cassert"]]
	[["filesystem"]]
	# Basic C-Standard
	[["iostream"]]
	[["algorithm"]]
	[["functional"]]
	[["memory"]]
	[["thread"]]
	[["utility"]]
	# Data Structures
	[["string"]]
	[["stack"]]
	[["deque"]]
	[["array"]]
	[["vector"]]
	[["set"]]
	[["map"]]
	[["unordered_set"]]
	[["unordered_map"]]
	[["utils/Types.hpp"]]
	[["utils/Paths.hpp"]]
	[["utils/logging/Logger.hpp"]]
)

message(STATUS "Building platform library - done")