#include "Look.h"

Look::Look(int x, int y, bool isWhite) : Pieces(x,y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Look::~Look()
{
}

void Look::draw(){
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	cout << "·ç¿í";
}

void Look::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Look::getPos(){
	return pos;
}
