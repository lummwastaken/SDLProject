#pragma once
#include <filesystem>

#define ASSETS_PATH std::filesystem::path(RESOURCE_PATH+"/assets")
#define DATA_PATH std::filesystem::path(RESOURCE_PATH+"/data")

#define TEXTURE_PATH std::filesystem::path(ASSETS_PATH+"/textures")