#pragma once

/**
 * Release version cannot include debug console window.
 * Also we need to change entry from WinMain to platform-independent main function
 */
#if defined(_WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#if defined(_DEBUG) && defined(_MSC_VER)
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Engine.h"
