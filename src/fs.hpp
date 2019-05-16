#pragma once
// Check for filesystem and if it doesn't exist at all, remove from code
#if __has_include(<filesystem>)
	#define FS_SUPPORT
	#include <filesystem>
	namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
	#define FS_SUPPORT
	#include <experimental/filesystem>
	namespace fs = std::experimental::filesystem;
#else
	#warning "no support for filesystem"
#endif
