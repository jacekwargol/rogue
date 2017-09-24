#include "stdafx.h"

#include "Window.hpp"

namespace rg {
	Window::Window(Utils::Vector2 size, const std::string& title, bool isFullScreen) :
		size{ size }, title{ title }, isFullScreen{ isFullScreen }, viewportPos{ 0, 0 } {

		TCODConsole::initRoot(size.x, size.y, title.c_str(), isFullScreen);
	}

	Window::~Window() = default;

	void Window::clear() noexcept {
		TCODConsole::root->clear();
	}

	void Window::flush() noexcept {
		TCODConsole::root->flush();
	}

	bool Window::isWindowClosed() const noexcept {
		return TCODConsole::isWindowClosed();
	}

	void Window::drawTile(const Utils::Vector2& pos, const Tile& tile) noexcept {
		if (isInBoundaries(pos)) {
			TCODConsole::root->putCharEx(pos.x - viewportPos.x, pos.y - viewportPos.y,
				tile.symbol, tile.symColor, tile.bgColor);
		}
	}

	void Window::moveView(int dx, int dy) {
		viewportPos.x += dx;
		viewportPos.y += dy;
	}

	void Window::moveViewToPos(const Utils::Vector2& newPos) noexcept {
		viewportPos = newPos;
	}

	bool Window::isInBoundaries(const Utils::Vector2& pos) const noexcept {
		return pos.x >= viewportPos.x && pos.x < viewportPos.x + size.x &&
			pos.y >= viewportPos.y && pos.y < viewportPos.y + size.y;
	}
}

