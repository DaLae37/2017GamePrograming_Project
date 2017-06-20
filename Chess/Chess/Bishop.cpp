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
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "ºñ¼ó";
}

bool Bishop::canMove(ChessBoard *map, int x, int y) {
	bool one, two, three, four;
	one = two = three = four = false;
	for (int i = 1; i <= 7; i++) {
		if (pos.first < x && pos.second < y && !one) {
			if (!map->isIn(pos.first + i, pos.second + i) && pos.first + i == x && pos.second + i == y)
				return true;
			else if(map->isIn(pos.first + i, pos.second + i))
				one = true;
			if (map->isOpponent(pos.first + i, pos.second + i, isWhite) && pos.first + i == x && pos.second + i == y)
				return true;
		}
		if (pos.first < x && pos.second > y && !two) {
			if (!map->isIn(pos.first + i, pos.second - i) && pos.first + i == x && pos.second - i == y)
				return true;
			else if (map->isIn(pos.first + i, pos.second - i))
				two = true;
			if (map->isOpponent(pos.first + i, pos.second - i, isWhite) && pos.first + i == x && pos.second - i == y)
				return true;
		}
		if (pos.first > x && pos.second < y && !three) {
			if (!map->isIn(pos.first - i, pos.second + i) && pos.first - i == x && pos.second + i == y)
				return true;
			else if (map->isIn(pos.first - i, pos.second + i))
				three = true;
			if (map->isOpponent(pos.first - i, pos.second + i, isWhite) && pos.first - i == x && pos.second + i == y)
				return true;
		}
		if (pos.first > x && pos.second > y && !four) {
			if (!map->isIn(pos.first - i, pos.second - i) && pos.first - i == x && pos.second - i == y)
				return true; 
			else if (map->isIn(pos.first - i, pos.second - i))
				four = true;
			if (map->isOpponent(pos.first - i, pos.second - i, isWhite) && pos.first - i == x && pos.second - i == y)
				return true;
		}
	}
	return false;
}

void Bishop::move(ChessBoard *map) {
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

void Bishop::Input(ChessBoard *map) {
	int x, y;
	global->setPos(30, 20);
	global->setColor(White, Black);
	cin >> y >> x;
	global->setPos(30, 20);
	cout << "        ";
	if (canMove(map, x, y)) {
		setPos(x, y);
		isSelected = false;
		if (isWhite) {
			map->blackMakeFalse(x, y);
			map->whiteMakeFalse(pos.first, pos.second);
			map->MakeFalse(pos.first, pos.second);
		}
		else {
			map->whiteMakeFalse(x, y);
			map->blackMakeFalse(pos.first, pos.second);
			map->MakeFalse(pos.first, pos.second);
		}
		map->PieceIn(x, y, isWhite);
	}
	if (isSelected)
		Input(map);
}

void Bishop::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Bishop::getPos(){
	return pos;
}