#include "stdafx.h"
#include "Map.hpp"
#include <iostream>

namespace rg {
	Map::Map(int height, int width) : width{ width }, height{ height } {
	}

	Map::~Map() = default;

	void Map::generateMap() noexcept {
		//TCODRandom rng;
		//int noRooms = rng.get(5, 10);
		//for (int i = 0; i < noRooms; ++i) {
		//	createRoom(10, 30, i * 10, i * 15);
		//}
		createRoom(160, 85, 0, 0);
	}

	void Map::draw(Window& window) noexcept {
		for (auto& tile : map) {
			window.drawTile(tile);
		}
	}

	void Map::createRoom(int width, int height, int x, int y) noexcept {
		for (int i = x; i < x + width; ++i) {
			for (int j = y; j < y + height; ++j) {
				if (i == x || i == x + width - 1 || j == y || j == y + height - 1) {
					map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor,
						WALL_TILE.bgColor, i, j });
				}
				else {
					map.push_back(Tile{ FLOOR_TILE.symbol, FLOOR_TILE.symColor,
						FLOOR_TILE.bgColor, i, j });
				}
			}
		}
	}

}

