#include "stdafx.h"
#include "Player.hpp"

namespace rg {
	Player::Player(Utils::Vector2 pos) : GameObject{ '@', TCODColor::amber, TCODColor::black, pos } {
	}

	Player::~Player() = default;
}
