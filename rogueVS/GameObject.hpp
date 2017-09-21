#pragma once
#include "stdafx.h"

#include "Window.hpp"

namespace rg {
	class GameObject {
	public:
		GameObject(char symbol);
		~GameObject();

		void draw(int x, int y, Window& window) noexcept;

	private:
		char symbol;
	};
}
