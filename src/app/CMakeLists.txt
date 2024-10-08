message(STATUS "Building application")

include_directories(
	${PLATFORM_INCLUDES}
	${GAME_INCLUDES}
	${APP_INCLUDES}
)

set(APP_SOURCES
	"EntryPoint.cpp"
	"application/Application.cpp"
)

set(APP_HEADERS
	"application/Application.hpp"
)

add_executable(${CMAKE_PROJECT_NAME} WIN32
	$<TARGET_OBJECTS:PROJ_PLATFORM>
	$<TARGET_OBJECTS:PROJ_GAME>
	${APP_SOURCES}
	${APP_HEADERS}
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${EXTERNAL_INCLUDES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${EXTERNAL_LIBRARIES})

target_precompile_headers(${CMAKE_PROJECT_NAME} REUSE_FROM PROJ_PLATFORM)
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${CMAKE_PROJECT_NAME}> $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>
	COMMAND_EXPAND_LISTS
)
add_custom_target(COPY_RESOURCES ALL
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_SOURCE_DIR}/resources"
	"${CMAKE_BINARY_DIR}/resources"
)
add_dependencies(${CMAKE_PROJECT_NAME} COPY_RESOURCES)
MESSAGE(STATUS "Copying resources into build directory...")
# installs needed DLLs automatically
# except SDL_image and mixer, which have to be added manually