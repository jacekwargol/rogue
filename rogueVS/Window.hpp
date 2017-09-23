#pragma once

#include "stdafx.h"
#include "Tile.hpp"


namespace rg {
	class Window {
	public:
		explicit Window(int width = 150, int height = 75,
			const std::string& title = "rogue",
			bool isFullScreen = false);

		~Window();

		void clear() noexcept;
		void flush() noexcept;
		bool isWindowClosed() const noexcept;
		void drawTile(const Tile& tile) noexcept;
		void drawTile(int x, int y, char ch,
			TCODColor symColor = TCODColor::white, TCODColor bgColor = TCODColor::black) noexcept;

		void moveView(int x, int y) noexcept;

	private:
		int width;
		int height;
		int viewX;
		int viewY;
		std::string title;
		bool isFullScreen;

		bool isInBoundaries(const Tile& tile) const noexcept;
		bool isInBoundaries(int x, int y) const noexcept;
	};
}


