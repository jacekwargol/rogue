#pragma once

#include "stdafx.h"


namespace rg {
	struct Tile {
		int x, y;
		char symbol;
		TCODColor symColor, bgColor;

		Tile(char symbol = '.', TCODColor symColor = TCODColor::white,
			TCODColor bgColor = TCODColor::black, int x = -1, int y = -1);
		~Tile();
	};

}

