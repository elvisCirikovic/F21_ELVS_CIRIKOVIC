#pragma once

#include "MirageUtils.h"

#include "MirageApp.h"

#define START_MIRAGE_GAME(classname) \
int main()\
{\
	classname _mirage_game;\
	_mirage_game.Run();\
}