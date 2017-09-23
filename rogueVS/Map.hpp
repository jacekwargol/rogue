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

		bool isWall(int x, int y) const noexcept;
		bool isTileAtPosition(int x, int y) const noexcept;

	private:
		struct Room {
			int upperLeftX;
			int upperLeftY;
			int width;
			int height;
			bool isConnected;

			Room(int upperLeftX, int upperLeftY, int width, int height, bool isConnected = false);
		};

		int width, height;
		std::vector<Tile> map;
		std::vector<Room> rooms;

		void createRoom(int width, int height, int x, int y) noexcept;
		void createCorridors() noexcept;
		void connectRooms(Room& room1, Room& room2) noexcept;


	};
}


