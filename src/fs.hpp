#pragma once

#if __has_include(<filesystem>)
	#define FS_SUPPORT true
	#include <filesystem>
	namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
	#define FS_SUPPORT true
	#include <experimental/filesystem>
	namespace fs = std::experimental::filesystem;
#else
	#define FS_SUPPORT false
	#error "no support for filesystem"
#endif
