#include "stdafx.h"
#include "GameObject.hpp"


namespace rg {
	GameObject::GameObject(char symbol) : symbol{ symbol } {
	}

	GameObject::~GameObject() = default;

	void GameObject::draw(int x, int y, Window& window) noexcept {
		window.putChar(x, y, symbol);
	}

}

