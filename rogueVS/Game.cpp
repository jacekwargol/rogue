#include "stdafx.h"
#include "Game.hpp"
#include "GameObject.hpp"

namespace rg {
	Game::Game() : gameWindow{}, isRunning{ false } {
	}


	Game::~Game() = default;

	void Game::startGame() noexcept {
		runGameLoop();
	}

	void Game::endGame() noexcept {
		isRunning = false;
	}


	void Game::runGameLoop() noexcept {
		isRunning = true;
		while (isRunning) {
			handleInput();
			gameWindow.clear();
			gameWindow.flush();
		}
	}

	void Game::handleInput() noexcept {
		TCOD_key_t key{};
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);

		switch (key.vk) {
		case TCODK_ESCAPE:
			endGame();
			return;
		default:
			break;
		}
	}
}
