#include "stdafx.h"
#include "Map.hpp"
#include <iostream>
#include <algorithm>

namespace rg {
	Map::Map(Utils::Vector2 size) : size{ size },
		map(size.x, std::vector<Tile>(size.y, BLANK_TILE)) {
	}


	Map::~Map() = default;

	Map::Room::Room(Utils::Vector2 upperLeft, Utils::Vector2 size, bool isConnected) :
		upperLeft{ upperLeft }, size{ size }, isConnected{ isConnected } {
	}

	void Map::generateMap() noexcept {
		TCODRandom rng;
		int noRooms = rng.get(15, 25);
		for (int i = 0; i < noRooms; ++i) {
			Utils::Vector2 roomSize{ rng.get(5, 20), rng.get(5, 20) };
			Utils::Vector2 roomPos{ rng.get(0, size.x - roomSize.x), rng.get(0, size.y - roomSize.y) };
			std::cout << size.x << " " << size.y << std::endl;
			std::cout << roomPos.x << " " << roomPos.y << std::endl;
			createRoom(roomSize, roomPos);
		}

		createCorridors();
	}

	void Map::draw(Window& window) noexcept {
		for (int i = 0; i < size.x; ++i) {
			for (int j = 0; j < size.y; ++j) {
				window.drawTile(Utils::Vector2{ i, j }, map[i][j]);
			}
		}

	}

	bool Map::isTileAtPosition(Utils::Vector2 pos) const noexcept {
		return map[pos.x][pos.y] != BLANK_TILE;
	}

	void Map::createRoom(Utils::Vector2 size, Utils::Vector2 pos) noexcept {
		for (int i = pos.x; i < pos.x + size.x; ++i) {
			for (int j = pos.y; j < pos.y + size.y; ++j) {
				if ((i == pos.x || i == pos.x + size.x - 1 || j == pos.y || j == pos.y + size.y - 1) && !isTileAtPosition(Utils::Vector2{ i, j })) {
					map[i][j] = WALL_TILE;
				}
				else {
					map[i][j] = FLOOR_TILE;
				}
			}
		}

		rooms.push_back(Room{ pos, size });
	}

	void Map::createCorridors() noexcept {
		for (auto room = rooms.begin(); room < rooms.end() - 2; ++room) {
			connectRooms(*room, *(room + 1));
		}
	}

	void Map::connectRooms(Room& room1, Room& room2) noexcept {
		//int startingX = (room1.upperLeftX + room1.width) / 2;
		//int startingY = (room1.upperLeftY + room1.height) / 2;
		//int endingX = (room2.upperLeftX + room2.width) / 2;
		//int endingY = (room2.upperLeftY + room2.height) / 2;

		//int dirX = (startingX < endingX ? 1 : -1);
		//int dirY = (startingY < endingY ? 1 : -1);

		//while (startingX != endingX) {
		//	map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX, startingY - 1 });
		//	map.push_back(Tile{ FLOOR_TILE.symbol, FLOOR_TILE.symColor, FLOOR_TILE.bgColor, startingX, startingY });
		//	map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX, startingY + 1 });
		//	startingX += dirX;
		//}

		//while (startingY != endingY) {
		//	map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX - 1, startingY });
		//	map.push_back(Tile{ FLOOR_TILE.symbol, FLOOR_TILE.symColor, FLOOR_TILE.bgColor, startingX, startingY });
		//	map.push_back(Tile{ WALL_TILE.symbol, WALL_TILE.symColor, WALL_TILE.bgColor, startingX + 1, startingY });
		//	startingY += dirY;
		//}
	}
}
