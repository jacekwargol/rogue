#include "stdafx.h"
#include "Window.hpp"

namespace rg {
	Window::Window(int width, int height, const std::string& title, bool isFullScreen) :
		width{ width },
		height{ height },
		title{ title },
		isFullScreen{ isFullScreen },
		viewX{ 0 },
		viewY{ 0 } {

		TCODConsole::initRoot(width, height, title.c_str(), isFullScreen);
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

	void Window::drawTile(const Tile& tile) noexcept {
		if (isInBoundaries(tile)) {
			TCODConsole::root->putCharEx(tile.x - viewX, tile.y - viewY, tile.symbol, tile.symColor, tile.bgColor);
		}
	}

	void Window::drawTile(const int x, const int y, const char ch,
		TCODColor symColor, TCODColor bgColor) noexcept {
		if (isInBoundaries(x, y)) {
			TCODConsole::root->putCharEx(x - viewX, y - viewY, ch, symColor, bgColor);

		}
	}

	void Window::moveView(int x, int y) noexcept {
		viewX = x;
		viewY = y;
	}

	bool Window::isInBoundaries(const Tile& tile) const noexcept {
		return tile.x >= viewX && tile.x < viewX + width &&
			tile.y >= viewY && tile.y < viewY + height;
	}

	bool Window::isInBoundaries(int x, int y) const noexcept {
		return x >= viewX && x < viewX + width && y >= viewY && y < viewY + height;
	}
}

