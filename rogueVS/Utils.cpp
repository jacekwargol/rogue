#include "stdafx.h"

#include "Utils.hpp"

namespace Utils {
	Vector2::Vector2(int x, int y) : x{ x }, y{ y } {
	}


	Vector2::~Vector2() = default;

	int Vector2::getDist(Vector2 other) const noexcept {
		return static_cast<int>(sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y)));
	}

}

