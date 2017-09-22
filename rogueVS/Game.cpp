#include "stdafx.h"
#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include <iostream>
#include "Map.hpp"

namespace rg {
	Game::Game() : gameWindow{}, isRunning{ false }, actors{} {
	}


	Game::~Game() = default;

	void Game::startGame() noexcept {
		actors.push_back(std::make_shared<Player>(13, 13));
		runGameLoop();
	}

	void Game::endGame() noexcept {
		isRunning = false;
	}


	void Game::runGameLoop() noexcept {
		Map map{};
		map.generateMap();

		isRunning = true;
		while (isRunning) {
			gameWindow.clear();
			handleInput();
			map.draw(gameWindow);
			for (auto& actor : actors) {
				actor->draw(gameWindow);
			}
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
