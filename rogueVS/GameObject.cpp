#include "stdafx.h"

#include "GameObject.hpp"


namespace rg {
	GameObject::GameObject(char symbol, TCODColor symColor, TCODColor bgColor, Utils::Vector2 pos) : 
		tile(symbol, symColor, bgColor), pos{ pos } {
	}

	GameObject::~GameObject() = default;

	void GameObject::draw(Window& window) noexcept {
		window.drawTile(pos, tile);
	}
}

