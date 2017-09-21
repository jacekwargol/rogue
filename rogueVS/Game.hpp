#pragma once
#include "stdafx.h"

#include "Window.hpp"
#include <vector>
#include "GameObject.hpp"

namespace rg {
	class Game {
	public:
		Game();
		~Game();

		void startGame() noexcept;

	private:
		Window gameWindow;
		bool isRunning;
		std::vector<GameObject> actors;

		void runGameLoop() noexcept;
		void handleInput() noexcept;
		void endGame() noexcept;
	};
}


