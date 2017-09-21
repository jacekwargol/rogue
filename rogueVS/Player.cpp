#include "stdafx.h"
#include "Player.hpp"

namespace rg {
	Player::Player(int x, int y) : GameObject{ '@', TCODColor::amber, TCODColor::black,
		x, y } {
	}

	Player::~Player() = default;
}

