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

	void Window::clear() {
		TCODConsole::root->clear();
	}

	void Window::flush() {
		TCODConsole::root->flush();
	}

	bool Window::isWindowClosed() {
		return TCODConsole::isWindowClosed();
	}

	void Window::putChar(const int x, const int y, const char ch) {
		TCODConsole::root->putChar(x, y, ch);
	}
}

