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
	cout << "Æ÷¿Â";
}

void Pawn::setPos(int x, int y) {
	pos.first = x;
	pos.second = y;
}

pair<int, int> Pawn::getPos() {
	return pos;
}