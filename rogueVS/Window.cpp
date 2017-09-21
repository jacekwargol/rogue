#include "stdafx.h"
#include "Window.hpp"

namespace rg {
	Window::Window(int width, int height, const std::string& title, bool isFullScreen) :
		width{ width },
		height{ height },
		title{ title },
		isFullScreen{ isFullScreen } {

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
		TCODConsole::root->putCharEx(tile.x, tile.y, tile.symbol, tile.symColor, tile.bgColor);
	}

	void Window::drawTile(const int x, const int y, const char ch,
		TCODColor symColor, TCODColor bgColor) noexcept {

		TCODConsole::root->putCharEx(x, y, ch, symColor, bgColor);
	}
}

