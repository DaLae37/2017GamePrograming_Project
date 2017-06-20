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
	int white = 1;
	if (isWhite)
		white = -1;
	if (!map->isIn(pos.first, pos.second + white))
		return true;
	if (map->isOpponent(pos.first + white, pos.second + white, isWhite))
		return true;
	if (map->isOpponent(pos.first + (-white), pos.second + white, isWhite))
		return true;
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
	global->setPos(30, 20);
	cout << "        ";
	if (canMove(map, x, y)) {
		setPos(x, y);
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