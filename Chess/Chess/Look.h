#pragma once
#include "Pieces.h"
class Look : public Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
public:
	Look(int x, int y, bool isWhite);
	~Look();
	void draw();
	void setPos(int x, int y);
	pair<int, int> getPos();
};

