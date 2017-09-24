#pragma once

#include "stdafx.h"
#include "GameObject.hpp"

namespace rg {
	class Player : public GameObject {
	public:
		Player(Utils::Vector2 pos = Utils::Vector2{ -1, -1 });
		~Player();
	};
}


