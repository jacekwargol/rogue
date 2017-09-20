#pragma once
#include "Window.hpp"

namespace rg {
	class Game {
	public:
		Game();
		~Game();

	private:
		Window gameWindow;

		void runGameLoop() noexcept;
		bool handleInput() noexcept;

	public:
		void startGame() noexcept;
	};
}


