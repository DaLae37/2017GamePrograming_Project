#include "Bishop.h"

Bishop::Bishop(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Bishop::~Bishop()
{
}

void Bishop::draw(){
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	cout << "ºñ¼ó";
}

void Bishop::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Bishop::getPos(){
	return pos;
}