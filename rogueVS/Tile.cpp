#include "stdafx.h"

#include "Tile.hpp"

namespace rg {
	Tile::Tile(char symbol, TCODColor symColor, TCODColor bgColor) :
		symbol(symbol), symColor(symColor), bgColor(bgColor) {

	}

	Tile::~Tile() = default;
}
