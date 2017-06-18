#pragma once
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Look.h"
#include "Pawn.h"
#include "Pieces.h"
class Player
{
public:
	Player(bool isWhite);
	~Player();
	Pieces *pc[16];
};

