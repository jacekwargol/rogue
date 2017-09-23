#include "stdafx.h"
#include "Map.hpp"
#include <iostream>
#include <algorithm>

namespace rg {
	Map::Map(int height, int width) : width{ width }, height{ height } {
	}

	Map::~Map() = default;

	void Map::generateMap() noexcept {
		TCODRandom rng;
		int noRooms = rng.get(15, 25);
		for (int i = 0; i < noRooms; ++i) {
			int roomWidth = rng.get(5, 20);
			int roomHeight = rng.get(5, 20);
			int roomGapX = rng.get(0, 10);
			int roomGapY = rng.get(0, 10);
			createRoom(roomHeight, roomWidth, i * roomWidth + roomGapX, i * roomHeight + roomGapY);
		}
	}

	void Map::draw(Window& window) noexcept {
		for (auto& tile : map) {
			window.drawTile(tile);
		}
	}

	bool Map::isWall(int x, int y) const noexcept {
		if (std::find_if(map.cbegin(), map.cend(),
			[&](const Tile& tile) {
			return tile.x == x && tile.y == y && tile.symbol == WALL_TILE.symbol;
		}) != map.cend()) {

			return true;
		}

		return false;
	}

	bool Map::isTileAtPosition(int x, int y) const noexcept {
		if (std::find_if(map.cbegin(), map.cend(),
			[&](const Tile& tile) {
			return tile.x == x && tile.y == y;
		}) != map.cend()) {

			return true;
		}

		return false;
	}


	void Map::createRoom(int width, int height, int x, int y) noexcept {
		for (int i = x; i < x + width; ++i) {
			for (int j = y; j < y + height; ++j) {
				if ((i == x || i == x + width - 1 || j == y || j == y + height - 1) && !isTileAtPosition(i, j)) {
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

