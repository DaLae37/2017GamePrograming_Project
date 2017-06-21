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
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "ÄûÀÎ";
}

bool Queen::canMove(ChessBoard *map, int x, int y) {
	bool one, two, three, four, five, six, seven, eight;
	one = two = three = four = five = six = seven = eight = false;
	for (int i = 1; i <= 7; i++) {
		if (pos.first < x && pos.second < y && !one) {
			if (!map->isIn(pos.first + i, pos.second + i) && pos.first + i == x && pos.second + i == y)
				return true;
			else if (map->isIn(pos.first + i, pos.second + i))
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
		//bishop
		if (pos.second < y && !five) {
			if (!map->isIn(pos.first, pos.second + i) && pos.first == x && pos.second + i == y)
				return true;
			else if (map->isIn(pos.first, pos.second + i))
				five = true;
			if (map->isOpponent(pos.first, pos.second + i, isWhite) && pos.first == x && pos.second + i == y)
				return true;
		}
		if (pos.second > y && !six) {
			if (!map->isIn(pos.first, pos.second - i) && pos.first == x && pos.second - i == y)
				return true;
			else if (map->isIn(pos.first, pos.second - i))
				six = true;
			if (map->isOpponent(pos.first, pos.second - i, isWhite) && pos.first == x && pos.second - i == y)
				return true;
		}
		if (pos.first > x && !seven) {
			if (!map->isIn(pos.first - i, pos.second) && pos.first - i == x && pos.second == y)
				return true;
			else if (map->isIn(pos.first - i, pos.second))
				seven = true;
			if (map->isOpponent(pos.first - i, pos.second, isWhite) && pos.first - i == x && pos.second == y)
				return true;
		}
		if (pos.first < x && !eight) {
			if (!map->isIn(pos.first + i, pos.second) && pos.first + i == x && pos.second == y)
				return true;
			else if (map->isIn(pos.first + i, pos.second))
				eight = true;
			if (map->isOpponent(pos.first + i, pos.second, isWhite) && pos.first + i == x && pos.second == y)
				return true;
			//look
		}
	}
	return false;
}
void Queen::move(ChessBoard *map) {
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

void Queen::Input(ChessBoard *map) {
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
		map->PieceIn(x, y, isWhite);
		map->MakeFalse(pos.first, pos.second);
		setPos(x, y);
	}
	if (isSelected)
		Input(map);
}

void Queen::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> Queen::getPos(){
	return pos;
}