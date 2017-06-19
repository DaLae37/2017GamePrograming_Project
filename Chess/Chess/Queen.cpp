#include "Queen.h"

Queen::Queen(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Queen::~Queen()
{
}

void Queen::draw(){
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	cout << "ÄûÀÎ";
}

void Queen::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Queen::getPos(){
	return pos;
}