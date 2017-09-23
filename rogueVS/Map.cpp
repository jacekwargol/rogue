#include "stdafx.h"
#include "Map.hpp"
#include <iostream>
#include <algorithm>

namespace rg {
	Map::Map(int height, int width) : width{ width }, height{ height }, map{}, rooms{} {
	}

	Map::~Map() = default;

	Map::Room::Room(int upperLeftX, int upperLeftY, int width, int height, bool isConnected) :
		upperLeftX{ upperLeftX }, upperLeftY{ upperLeftY }, width{ width }, height{ height }, isConnected{ isConnected } {
	}

	void Map::generateMap() noexcept {
		TCODRandom rng;
		int noRooms = rng.get(15, 25);
		for (int i = 0; i < noRooms; ++i) {
			int roomWidth = rng.get(5, 20);
			int roomHeight = rng.get(5, 20);
			int roomGapX = rng.get(5, 20);
			int roomGapY = rng.get(5, 20);
			createRoom(roomHeight, roomWidth, roomWidth + i * roomGapX, roomHeight + i * roomGapY);
		}

		createCorridors();
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

		rooms.push_back(Room{ x, y, width, height });
	}

	void Map::createCorridors() noexcept {
		for (auto room = rooms.begin(); room < rooms.end() - 2; ++room) {
			connectRooms(*room, *(room + 1));
		}
	}

	void Map::connectRooms(Room& room1, Room& room2) noexcept {
		int startingX = (room1.upperLeftX + room1.width) / 2;
		int startingY = (room1.upperLeftY + room1.height) / 2;
		int endingX = (room2.upperLeftX + room2.width) / 2;
		int endingY = (room2.upperLeftY + room2.height) / 2;

		int dirX = (startingX < endingX ? 1 : -1);
		int dirY = (startingY < endingY ? 1 : -1);

		while (startingX != endingX) {
			map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX, startingY - 1 });
			map.push_back(Tile{ FLOOR_TILE.symbol, FLOOR_TILE.symColor, FLOOR_TILE.bgColor, startingX, startingY });
			map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX, startingY + 1});
			startingX += dirX;
		}

		while (startingY != endingY) {
			map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX - 1, startingY });
			map.push_back(Tile{ FLOOR_TILE.symbol, FLOOR_TILE.symColor, FLOOR_TILE.bgColor, startingX, startingY });
			map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX + 1, startingY });
			startingY += dirY;
		}

		{

		}
	}
}

