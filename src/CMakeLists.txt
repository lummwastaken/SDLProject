project(${CMAKE_PROJECT_NAME})

set(PLATFORM_INCLUDES
	"${PROJECT_SOURCE_DIR}/platform/"
	"${PROJECT_SOURCE_DIR}/platform/events/"
	"${PROJECT_SOURCE_DIR}/platform/render/"
	"${PROJECT_SOURCE_DIR}/platform/render/texture"
	"${PROJECT_SOURCE_DIR}/platform/utils/"
	"${PROJECT_SOURCE_DIR}/platform/window/"
)

set(GAME_INCLUDES
	"${PROJECT_SOURCE_DIR}/game/"
)

set(APP_INCLUDES
	"${PROJECT_SOURCE_DIR}/app/"
	"${PROJECT_SOURCE_DIR}/app/application/"
)

add_subdirectory(platform)
add_subdirectory(game)
add_subdirectory(app)