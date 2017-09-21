#pragma once
#include <vector>
#include "Tile.hpp"

namespace rg {
	class Window;

	class Map {
	public:
		Map(int width = 50, int height = 50);
		~Map();

		void generate() noexcept;
		void draw(Window& window) noexcept;

	private:
		int width, height;
		std::vector<Tile> map;
	};
}


