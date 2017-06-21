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
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "·ç¿í";
}

bool Look::canMove(ChessBoard *map, int x, int y) {
	bool one, two, three, four;
	one = two = three = four = false;
	for (int i = 1; i <= 7; i++) {
		if (pos.second < y && !one) {
			if (!map->isIn(pos.first, pos.second + i) && pos.first == x && pos.second + i == y)
				return true;
			else if (map->isIn(pos.first, pos.second + i))
				one = true;
			if (map->isOpponent(pos.first, pos.second + i, isWhite) && pos.first == x && pos.second + i == y)
				return true;
		}
		if (pos.second > y && !two) {
			if (!map->isIn(pos.first, pos.second - i) && pos.first == x && pos.second - i == y)
				return true;
			else if (map->isIn(pos.first, pos.second - i))
				two = true;
			if (map->isOpponent(pos.first, pos.second - i, isWhite) && pos.first == x && pos.second - i == y)
				return true;
		}
		if (pos.first > x && !three) {
			if (!map->isIn(pos.first - i, pos.second) && pos.first - i == x && pos.second == y)
				return true;
			else if (map->isIn(pos.first - i, pos.second))
				three = true;
			if (map->isOpponent(pos.first - i, pos.second, isWhite) && pos.first - i == x && pos.second == y)
				return true;
		}
		if (pos.first < x && !four) {
			if (!map->isIn(pos.first + i, pos.second) && pos.first + i == x && pos.second == y)
				return true;
			else if (map->isIn(pos.first + i, pos.second))
				four = true;
			if (map->isOpponent(pos.first + i, pos.second, isWhite) && pos.first + i == x && pos.second== y)
				return true;
		}
	}
	return false;
	return false;
}

void Look::move(ChessBoard *map) {
	int x, y;
	int white = 1;
	if (isWhite)
		white = -1;
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

void Look::Input(ChessBoard *map) {
	int x, y;
	global->setPos(30, 20);
	global->setColor(White, Black);
	cin >> y >> x;
	global->clearUnder();
	if (canMove(map, x, y)) {
		isSelected = false;
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

void Look::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Look::getPos(){
	return pos;
}
