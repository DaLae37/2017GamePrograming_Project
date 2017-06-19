#pragma once
#include "Pieces.h"
class Knight : public Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
public:
	Knight(int x, int y, bool isWhite);
	~Knight();
	void draw();
	void setPos(int x, int y);
	pair<int, int> getPos();
};

