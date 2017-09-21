#include "stdafx.h"
#include "GameObject.hpp"


namespace rg {
	GameObject::GameObject(char symbol, TCODColor symColor, TCODColor bgColor,
		int x, int y) : tile{ x, y, symbol, symColor, bgColor } {
	}

	GameObject::~GameObject() = default;

	void GameObject::draw(Window& window) noexcept {
		window.drawTile(tile);
	}

}

