#pragma once
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Look.h"
#include "Pawn.h"
#include "Pieces.h"
#include "ChessBoard.h"
#include <conio.h>
class Player
{
public:
	Player(bool isWhite, ChessBoard *gameMap);
	~Player();
	bool isGameOver;
	bool isWhite;
	bool CanMoveCheck(ChessBoard *map, int i);
	int x, y;
	Pieces *pc[16];
	gameTool *global;
	void Update(ChessBoard *gameMap);
	void InputCheck(ChessBoard *map);
	void draw(ChessBoard *gameMap);
};

