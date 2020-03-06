#pragma once

#include <ctime>
#include <cstdio>
#include <cstring>

// template <typename... Vargs>
void debug_print(const char* file, const int line, const char* a);

#ifdef _DEBUG
#define LOG_DEBUG(...) debug_print(__FILE__, __LINE__, __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#endif

#ifdef _WIN32
#define DIRSEP '\\'
#else
#define DIRSEP '/'
#endif
