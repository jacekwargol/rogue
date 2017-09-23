#include "stdafx.h"
#include "GameObject.hpp"


namespace rg {
	GameObject::GameObject(char symbol, TCODColor symColor, TCODColor bgColor,
		int x, int y) : tile(symbol, symColor, bgColor, x, y) {
	}

	GameObject::~GameObject() = default;

	void GameObject::draw(Window& window) noexcept {
		window.drawTile(tile);
	}

	int GameObject::getX() const noexcept {
		return tile.x;
	}


	int GameObject::getY() const noexcept {
		return tile.y;
	}
}

