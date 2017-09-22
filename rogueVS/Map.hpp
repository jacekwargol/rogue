#pragma once

#include "stdafx.h"

#include "Tile.hpp"
#include "Window.hpp"

namespace rg {
	const Tile WALL_TILE{ '#', TCODColor::white, TCODColor::black };
	const Tile FLOOR_TILE{ '.', TCODColor::white, TCODColor::black };

	class Map {
	public:
		Map(int width = 50, int height = 50);
		~Map();

		void generateMap() noexcept;
		void draw(Window& window) noexcept;

	private:
		int width, height;
		std::vector<Tile> map;

		void createRoom(int width, int height, int x, int y) noexcept;
	};
}


