#include "stdafx.h"
#include "Game.hpp"
#include "GameObject.hpp"

namespace rg {
	Game::Game() {
	}


	Game::~Game() {
	}

	void Game::startGame() noexcept {
		runGameLoop();
	}

	void Game::runGameLoop() noexcept {
		GameObject obj{ 'c' };
		while (!gameWindow.isWindowClosed()) {
			bool exit = handleInput();
			if (exit) {
				return;
			}
			gameWindow.clear();
			obj.draw(30, 30, gameWindow);
			gameWindow.flush();
		}
	}

	bool Game::handleInput() noexcept {
		TCOD_key_t key;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);

		switch (key.vk) {
		case TCODK_ESCAPE:
			return true;
		default:
			break;
		}

		return false;
	}
}
