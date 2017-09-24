#pragma once
#include "stdafx.h"

#include "Window.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
#include "Player.hpp"

namespace rg {
	class Game {
	public:
		Game();
		~Game();

		void startGame() noexcept;

	private:
		Window gameWindow;
		bool isRunning;
		std::vector<std::shared_ptr<GameObject>> actors;
		Map map;
		Player player;

		void runGameLoop() noexcept;
		void runGame() noexcept;
		void drawObjects() noexcept;
		void handleInput() noexcept;
		void handleGameWindow() noexcept;
		void endGame() noexcept;
	};
}


