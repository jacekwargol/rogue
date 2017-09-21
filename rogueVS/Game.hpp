#pragma once
#include "stdafx.h"

#include "Window.hpp"

namespace rg {
	class Game {
	public:
		Game();
		~Game();

		void startGame() noexcept;

	private:
		Window gameWindow;
		bool isRunning;

		void runGameLoop() noexcept;
		void handleInput() noexcept;
		void endGame() noexcept;
	};
}


