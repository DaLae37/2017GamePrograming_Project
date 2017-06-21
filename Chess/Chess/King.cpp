#include "King.h"

King::King(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

King::~King()
{
}

void King::draw() {
	global->setPos((pos.first) * 6 + 2, (pos.second) * 2 + 1);
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "Å°À×";
}

bool King::canMove(ChessBoard *map, int x, int y) {
	if (!map->isIn(pos.first + 1, pos.second + 1) && pos.first + 1 == x && pos.second +1 == y)
		return true;
	if (map->isOpponent(pos.first + 1, pos.second + 1, isWhite) && pos.first + 1 == x && pos.second + 1 == y)
		return true;
	//+1+1
	if (!map->isIn(pos.first + 1, pos.second) && pos.first + 1 == x && pos.second== y)
		return true;
	if (map->isOpponent(pos.first + 1, pos.second, isWhite) && pos.first + 1 == x && pos.second== y)
		return true;
	//+1+0
	if (!map->isIn(pos.first + 1, pos.second - 1) && pos.first + 1 == x && pos.second - 1 == y)
		return true;
	if (map->isOpponent(pos.first + 1, pos.second - 1, isWhite) && pos.first + 1 == x && pos.second - 1 == y)
		return true;
	//+1-1
	
	if (!map->isIn(pos.first, pos.second + 1) && pos.first == x && pos.second + 1 == y)
		return true;
	if (map->isOpponent(pos.first, pos.second + 1, isWhite) && pos.first== x && pos.second + 1 == y)
		return true;
	//+0+1
	if (!map->isIn(pos.first, pos.second - 1) && pos.first== x && pos.second - 1 == y)
		return true;
	if (map->isOpponent(pos.first, pos.second - 1, isWhite) && pos.first== x && pos.second - 1 == y)
		return true;
	//+0-1

	if (!map->isIn(pos.first - 1, pos.second + 1) && pos.first - 1 == x && pos.second + 1 == y)
		return true;
	if (map->isOpponent(pos.first - 1, pos.second + 1, isWhite) && pos.first - 1 == x && pos.second + 1 == y)
		return true;
	//-1+1
	if (!map->isIn(pos.first -1, pos.second) && pos.first- 1 == x && pos.second == y)
		return true;
	if (map->isOpponent(pos.first - 1, pos.second, isWhite) && pos.first- 1 == x && pos.second == y)
		return true;
	//-1+0
	if (!map->isIn(pos.first -1, pos.second - 1) && pos.first- 1 == x && pos.second - 1 == y)
		return true;
	if (map->isOpponent(pos.first - 1, pos.second - 1, isWhite) && pos.first- 1 == x && pos.second - 1 == y)
		return true;
	//-1-1
	return false;
}

void King::move(ChessBoard *map) {
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

void King::Input(ChessBoard *map) {
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
			map->whiteKingMove(pos.first, pos.second, x, y);
		}
		else {
			map->whiteMakeFalse(x, y);
			map->blackMakeFalse(pos.first, pos.second);
			map->blackKingMove(pos.first, pos.second, x, y);
		}
		map->MakeFalse(pos.first, pos.second);
		map->PieceIn(x, y, isWhite);
		setPos(x, y);
	}
	if (isSelected)
		Input(map);
}

void King::setPos(int x, int y){
	pos.first = x;
	pos.second = y;
}

pair<int, int> King::getPos(){
	return pos;
}