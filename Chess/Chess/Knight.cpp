#include "Knight.h"

Knight::Knight(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Knight::~Knight()
{
}

void Knight::draw(){
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "³ªŸæ";
}

void Knight::setPos(int x, int y){
	pos.first = x;
	pos.second  = y;
}

pair<int, int> Knight::getPos(){
	return pos;
}