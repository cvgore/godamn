#pragma once

#if defined(_WIN32) && !defined(_DEBUG)
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Utils.h"
#include "TiledMap.h"
#include "GameState.h"
#include "Player.h"