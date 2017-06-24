#pragma once
#include <utility>
#include "gameTool.h"
#include "ChessBoard.h"
using namespace std;
class Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
protected:
	gameTool *global;
	Mouse *mouse;
public:
	bool isSelected;
	bool isSelectedFinish;
	Pieces(int x, int y, bool isWhite);
	~Pieces();
	virtual void draw() = 0;
	virtual void setPos(int x, int y) = 0;
	virtual void move(ChessBoard *map) = 0;
	virtual void Input(ChessBoard *map) = 0;
	virtual bool canMove(ChessBoard *map, int x, int y) = 0;
	virtual pair<int, int> getPos() = 0;
};
