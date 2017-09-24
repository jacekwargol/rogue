#include "stdafx.h"

#include "Map.hpp"

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
			Utils::Vector2 roomSize{ rng.get(5, 40), rng.get(5, 40) };
			Utils::Vector2 roomPos{ rng.get(0, size.x - roomSize.x), rng.get(0, size.y - roomSize.y) };
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
		//TODO: add walls at edges of overlapping rooms

		bool isOverlapping = false;

		for (int i = pos.x; i < pos.x + size.x; ++i) {
			for (int j = pos.y; j < pos.y + size.y; ++j) {
				if (isTileAtPosition(Utils::Vector2{ i, j })) {
					map[i][j] = FLOOR_TILE;
					isOverlapping = true;
				}

				if ((i == pos.x || i == pos.x + size.x - 1 || j == pos.y || j == pos.y + size.y - 1) && !isOverlapping) {
					map[i][j] = WALL_TILE;
				}
				else {
					map[i][j] = FLOOR_TILE;
				}
			}
		}

		if (!isOverlapping) {
			rooms.push_back(Room{ pos, size });
		}
	}

	void Map::createCorridors() noexcept {
		for (auto& room : rooms) {
			if (!room.isConnected) {
				auto nearestRoom = findNearestRoom(room);
				connectRooms(room, nearestRoom);
			}
		}


	}

	void Map::connectRooms(Room& room1, Room& room2) noexcept {
		auto dir = Utils::Vector2{
			room1.upperLeft.x < room2.upperLeft.x ? 1 : -1,
			room1.upperLeft.y < room2.upperLeft.y ? 1 : -1
		};
		auto startingPoint = room1.upperLeft;
		auto endingPoint = room2.upperLeft;

		while (startingPoint.x != endingPoint.x) {
			startingPoint.x += dir.x;
			map[startingPoint.x][startingPoint.y] = FLOOR_TILE;
		}
		while (startingPoint.y != endingPoint.y) {
			startingPoint.y += dir.y;
			map[startingPoint.x][startingPoint.y] = FLOOR_TILE;
		}

		room1.isConnected = true;
		room2.isConnected = true;
	}

	Map::Room& Map::findNearestRoom(const Room& room) const noexcept {
		int minDist = INT_MAX;
		Room nearestRoom;
		for (const auto& other : rooms) {
			if (other.upperLeft != room.upperLeft) {
				int currDist = room.upperLeft.getDist(other.upperLeft);
				if (currDist < minDist) {
					minDist = currDist;
					nearestRoom = other;
				}
			}
		}

		return nearestRoom;
	}
}
