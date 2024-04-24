#pragma once


#include <SFML/Graphics.hpp>
#ifdef WIN32             // Exclure les en-tetes Windows rarement utilises
// Fichiers d'en-tete Windows
#include <windows.h>
#include <tchar.h>
#include <timeapi.h>
#include "targetver.h"
#endif

//#include "TronSFML.h"
//#include "player.h"
//#include "grid.h"
//#include "scene.h"
#include "App.h"

// Fichiers d'en-tete C RunTime
#include <cstdlib>
#include <malloc.h>
#include <memory.h>
#include <iostream>

using namespace sf;
using namespace std;


