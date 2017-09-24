#pragma once

#include "stdafx.h"

#include "Tile.hpp"
#include "Window.hpp"
#include "Vector2.hpp"

namespace rg {
	const Tile WALL_TILE{ '#' };
	const Tile FLOOR_TILE{ '.' };
	const Tile BLANK_TILE{ ' ' };

	class Map {
	public:
		Map(Utils::Vector2 size = Utils::Vector2{ 50, 50 });
		~Map();

		void generateMap() noexcept;
		void draw(Window& window) noexcept;

		bool isWall(Utils::Vector2 pos) const noexcept;
		bool isTileAtPosition(Utils::Vector2 pos) const noexcept;

	private:
		struct Room {
			Utils::Vector2 upperLeft;
			Utils::Vector2 size;
			bool isConnected;

			Room(Utils::Vector2 upperLeft, Utils::Vector2 size, bool isConnected = false);
		};

		Utils::Vector2 size;
		std::vector<std::vector<Tile>> map;
		std::vector<Room> rooms;

		void createRoom(Utils::Vector2 size, Utils::Vector2 pos) noexcept;
		void createCorridors() noexcept;
		void connectRooms(Room& room1, Room& room2) noexcept;


	};
}


