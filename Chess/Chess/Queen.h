#pragma once
#include "Pieces.h"
class Queen : public Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
public:
	Queen(int x, int y, bool isWhite);
	~Queen();
	void draw();
	void setPos(int x, int y);
	pair<int, int> getPos();
};

