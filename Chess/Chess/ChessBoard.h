#pragma once
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Look.h"
#include "Pawn.h"
#include "Pieces.h"
class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
	Pieces *pieces[8][8];
	void Update();
};

