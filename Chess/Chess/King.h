#pragma once
#include "Pieces.h"
class King : public Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
public:
	King(int x, int y, bool isWhite);
	~King();
	void draw();
	void setPos(int x, int y);
	pair<int, int> getPos();
};

