#include "stdafx.h"

#include "Game.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Map.hpp"

namespace rg {
	Game::Game() : gameWindow{}, isRunning{ false }, actors{}, map{ Utils::Vector2{150, 150} }, 
		player{ Utils::Vector2{13, 13 } } {
		actors.push_back(std::make_shared<Player>(player));
		map.generateMap();
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
			runGame();
		}
	}

	void Game::runGame() noexcept {
		handleInput();
		drawObjects();
		handleGameWindow();
	}

	void Game::drawObjects() noexcept {
		map.draw(gameWindow);
		for (auto& actor : actors) {
			actor->draw(gameWindow);
		}
		gameWindow.flush();
	}

	void Game::handleInput() noexcept {
		TCOD_key_t key{};
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, nullptr);

		switch (key.vk) {
		case TCODK_UP:
			gameWindow.moveView(0, -1);
			break;
		case TCODK_DOWN:
			gameWindow.moveView(0, 1);
			break;
		case TCODK_LEFT:
			gameWindow.moveView(-1, 0);
			break;
		case TCODK_RIGHT:
			gameWindow.moveView(1, 0);
			break;
		case TCODK_ESCAPE:
			endGame();
			return;
		default:
			break;
		}
	}

	void Game::handleGameWindow() noexcept {
		gameWindow.clear();
	}

}
