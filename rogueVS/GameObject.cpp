#include "stdafx.h"
#include "GameObject.hpp"


namespace rg
{
	GameObject::GameObject(char symbol) {
		this->symbol = symbol;
	}

	GameObject::~GameObject() {
	}

	void GameObject::draw(const int x, const int y, Window window) noexcept
	{
		window.putChar(x, y, this->symbol);
	}

}

