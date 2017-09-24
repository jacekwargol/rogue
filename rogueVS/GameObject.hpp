#pragma once
#include "stdafx.h"

#include "Window.hpp"
#include "Tile.hpp"
#include "Utils.hpp"

namespace rg {
	struct Tile;

	class GameObject {
	public:
		GameObject(char symbol, TCODColor symColor = TCODColor::white,
			TCODColor bgColor = TCODColor::black, Utils::Vector2 pos = Utils::Vector2{-1, -1});

		virtual ~GameObject() = 0;

		void draw(Window& window) noexcept;

		Utils::Vector2 getPos() const noexcept { return pos; }

	protected:
		Tile tile;
		Utils::Vector2 pos;
	};
}
