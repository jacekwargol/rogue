#pragma once

namespace Utils {
	struct Vector2 {
		Vector2(int x, int y);
		~Vector2();

		int x, y;

		int getDist(Vector2 other) const noexcept;

		Vector2& operator*(int i) noexcept { x *= i; y *= i; return *this; }
	};

}


