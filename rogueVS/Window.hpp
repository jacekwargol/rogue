#pragma once

#include "stdafx.h"
#include "Tile.hpp"
#include "Utils.hpp"


namespace rg {
	class Window {
	public:
		explicit Window(Utils::Vector2 size = Utils::Vector2{ 150, 75 },
			const std::string& title = "rogue",
			bool isFullScreen = false);

		~Window();

		void clear() noexcept;
		void flush() noexcept;
		bool isWindowClosed() const noexcept;
		void drawTile(const Utils::Vector2& pos, const Tile& tile) noexcept;

		void moveView(int dx, int dy);
		void moveViewToPos(const Utils::Vector2& newPos) noexcept;

	private:
		Utils::Vector2 size;
		Utils::Vector2 viewportPos;
		std::string title;
		bool isFullScreen;

		bool isInBoundaries(const Utils::Vector2& pos) const noexcept;
	};
}


