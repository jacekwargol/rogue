#include "stdafx.h"
#include "GameObject.hpp"


namespace rg {
	GameObject::GameObject(char symbol, TCODColor fgColor, TCODColor bgColor,
		int x, int y) : tile{ x, y, symbol, fgColor, bgColor } {
	}

	GameObject::~GameObject() = default;

	void GameObject::draw(int x, int y, Window& window) noexcept {
		window.putChar(tile.x, tile.y, tile.symbol, tile.bgColor, tile.fgColor);
	}

}

