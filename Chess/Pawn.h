#pragma once
#include "Pieces.h"
class Pawn : public Pieces
{
private :
	pair<int, int> pos;
	bool isWhite;
	bool isOnceMoved;
public:
	Pawn(int x, int y, bool isWhite);
	~Pawn();
	void draw();
	void setPos(int x, int y);
	void move(ChessBoard *map);
	void Input(ChessBoard *map);
	bool canMove(ChessBoard *map, int x, int y);
	pair<int, int> getPos();
};

