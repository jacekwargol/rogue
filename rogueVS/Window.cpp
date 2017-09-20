#include "stdafx.h"
#include "Window.hpp"

namespace rg {
	Window::Window(const int width, const int height, char* title, const bool isFullScreen) {

		this->width = width;
		this->height = height;
		this->title = title;
		this->isFullScreen = isFullScreen;

		TCODConsole::initRoot(this->width, this->height, this->title,
			this->isFullScreen);
	}

	Window::~Window() {
	}

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

