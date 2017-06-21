#include "Pawn.h"

Pawn::Pawn(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	isOnceMoved = false;
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
	cout << "Æ÷¿Â";
}

void Pawn::setPos(int x, int y) {
	pos.first = x;
	pos.second = y;
}

bool Pawn::canMove(ChessBoard *map, int x, int y) {
	if (x < 0 || x >= 8 || y < 0 || y >= 8)
		return false;
	int white = 1;
	if (isWhite)
		white = -1;
	if (!isOnceMoved) {
		for (int i = 1; i <= 2; i++) {
			if (!map->isIn(pos.first, pos.second + (white * i)) && pos.first == x && pos.second + (white * i) == y)
				return true;
			else if (map->isIn(pos.first, pos.second + (white * i)))
				break;
		}
		if (map->isOpponent(pos.first + white, pos.second + white, isWhite) && pos.first == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first + (-white), pos.second + white, isWhite) && pos.first + (-white) == x && pos.second + white == y)
			return true;
	}
	else {
		if (!map->isIn(pos.first, pos.second + white) && pos.first == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first + white, pos.second + white, isWhite) && pos.first == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first + (-white), pos.second + white, isWhite) && pos.first + (-white) == x && pos.second + white== y)
			return true;
	}
	return false;
}

void Pawn::move(ChessBoard *map) {
	int x, y;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (canMove(map, j, i)) {
				global->setPos((j) * 6 + 2, (i) * 2 + 1);
				cout << "####";
			}
		}
	}
	Input(map);
}

void Pawn::Input(ChessBoard *map) {
	int x, y;
	global->setPos(30, 20);
	global->setColor(White, Black);
	cin >> y >> x;
	global->clearUnder();
	if (canMove(map, x, y)) {
		isSelected = false;
		if(!isOnceMoved)
			isOnceMoved = true;
		if (isWhite) {
			map->blackMakeFalse(x, y);
			map->whiteMakeFalse(pos.first, pos.second);
		}
		else {
			map->whiteMakeFalse(x, y);
			map->blackMakeFalse(pos.first, pos.second);
		}
		map->MakeFalse(pos.first, pos.second);
		map->PieceIn(x, y, isWhite);
		setPos(x, y);
	}
	if (isSelected)
		Input(map);
}

pair<int, int> Pawn::getPos() {
	return pos;
}