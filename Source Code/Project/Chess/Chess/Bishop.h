#pragma once
#include "Pieces.h"
class Bishop : public Pieces
{
private:
	pair<int, int> pos;
	bool isWhite;
public:
	Bishop(int x, int y, bool isWhite);
	~Bishop();
	void draw();
	void setPos(int x, int y);
	void move(ChessBoard *map);
	void Input(ChessBoard *map);
	bool canMove(ChessBoard *map, int x, int y);
	pair<int, int> getPos();
};

