#include "Pawn.h"

Pawn::Pawn(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Pawn::~Pawn()
{
}

void Pawn::draw() {
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "����";
}

void Pawn::setPos(int x, int y) {
	pos.first = x;
	pos.second = y;
}

pair<int, int> Pawn::getPos() {
	return pos;
}