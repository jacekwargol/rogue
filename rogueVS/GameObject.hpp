#pragma once
#include "stdafx.h"

#include "Window.hpp"
#include "Tile.hpp"

namespace rg {
	struct Tile;

	class GameObject {
	public:
		GameObject(char symbol, TCODColor fgColor = TCODColor::white,
			TCODColor bgColor = TCODColor::black,
			int posX = -1, int posY = -1);

		~GameObject();

		void draw(int x, int y, Window& window) noexcept;

	protected:
		Tile tile;
	};
}
