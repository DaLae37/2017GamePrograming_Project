#include "Player.h"

Player::Player(bool isWhite)
{
	if (isWhite) {
		for (int i = 0; i<8; i++)
			pc[i] = new Pawn(i,6);
	}
		
}


Player::~Player()
{
}
