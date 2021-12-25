#pragma once

#include "MirageUtils.h"
#include "MirageApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"


#define START_MIRAGE_GAME(classname) \
int main()\
{\
	classname _mirage_game;\
	_mirage_game.Run();\
}