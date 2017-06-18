#pragma once
#include <utility>
#include "gameTool.h"
using namespace std;
class Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
protected:
	gameTool *global;
public:
	Pieces(int x, int y, bool isWhite);
	~Pieces();
	virtual void draw() = 0;
	virtual void setPos(int x, int y) = 0;
	virtual pair<int, int> getPos() = 0;
};

