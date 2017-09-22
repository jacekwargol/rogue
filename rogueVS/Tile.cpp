#include "stdafx.h"

#include "Tile.hpp"

namespace rg {
	Tile::Tile(char symbol, TCODColor symColor, TCODColor bgColor, int x, int y) :
		symbol(symbol), symColor(symColor), bgColor(bgColor), x(x), y(y) {

	}

	Tile::~Tile() = default;

}