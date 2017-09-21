#pragma once

#include "stdafx.h"
#include "GameObject.hpp"

namespace rg {
	class Player : public GameObject {
	public:
		Player(int x = -1, int y = -1);
		~Player();
	};
}


