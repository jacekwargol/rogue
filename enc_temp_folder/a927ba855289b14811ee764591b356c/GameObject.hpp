#pragma once
#include "Window.hpp"

namespace rg {
	class GameObject {
	public:
		GameObject(char symbol);
		~GameObject();

		void draw(const int x, const int y, const Window window) noexcept;

	private:
		char symbol;
	};
}
