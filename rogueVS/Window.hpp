#pragma once

#include "stdafx.h"

#include "include/libtcod.hpp"

namespace rg {
	class Window {
	public:
		explicit Window(const int width = 150, const int height = 75,
			char* title = "rogue",
			const bool isFullScreen = false);

		~Window();

		void clear();
		void flush();
		bool isWindowClosed();

		void putChar(const int x, const int y, const char ch);

	private:
		int width;
		int height;
		char* title;
		bool isFullScreen;
	};
}


