#pragma once

#if defined(_WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.h"
