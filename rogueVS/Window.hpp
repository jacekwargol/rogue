#pragma once

#include "stdafx.h"


namespace rg {
	class Window {
	public:
		explicit Window(int width = 150, int height = 75,
			const std::string& title = "rogue",
			bool isFullScreen = false);

		~Window();

		void clear();
		void flush();
		bool isWindowClosed();

		void putChar(int x, int y, char ch,
			TCODColor fgColor = TCODColor::white, TCODColor bgColor = TCODColor::black);

	private:
		int width;
		int height;
		std::string title;
		bool isFullScreen;
	};
}


