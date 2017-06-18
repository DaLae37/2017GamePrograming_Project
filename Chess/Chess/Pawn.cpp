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

}

void Pawn::setPos(int x, int y) {
	pos.first = x;
	pos.second = y;
}
pair<int, int> Pawn::getPos() {
	return pos;
}