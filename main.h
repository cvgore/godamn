#pragma once

/**
 * Release version cannot include debug console window.
 * Also we need to change entry from WinMain to platform-independent main function
 */
#if defined(_WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include "Engine.h"
