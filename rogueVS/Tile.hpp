#pragma once

#include "stdafx.h"


namespace rg {
	struct Tile {
		char symbol;
		TCODColor symColor, bgColor;

		Tile(char symbol = '.', TCODColor symColor = TCODColor::white,
			TCODColor bgColor = TCODColor::black);
		~Tile();

		bool operator==(const Tile& rhs) const {
			return symbol == rhs.symbol && symColor == rhs.symColor && bgColor == rhs.bgColor;
		}

		bool operator!=(const Tile& rhs) const { return !(*this == rhs); }
	};

}

