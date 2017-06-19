#pragma once
#include "Pieces.h"
class Pawn : public Pieces
{
private :
	pair<int, int> pos;
	bool isWhite;
public:
	Pawn(int x, int y, bool isWhite);
	~Pawn();
	void draw();
	void setPos(int x, int y);
	pair<int, int> getPos();
};

