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

bool Knight::canMove(ChessBoard *map, int x, int y) {
	int tmp1 = 1, tmp2 = 2;
	for (int i = 1; i <= 2; i++){
		if (!map->isIn(pos.first + tmp1, pos.second + tmp2) && x == pos.first + tmp1 && y == pos.second + tmp2)
			return true;
		if (map->isOpponent(pos.first + tmp1, pos.second + tmp2, isWhite) && x == pos.first + tmp1 && y == pos.second + tmp2)
			return true;

		if (!map->isIn(pos.first - tmp1, pos.second + tmp2) && x == pos.first - tmp1 && y == pos.second + tmp2)
			return true;
		if (map->isOpponent(pos.first - tmp1, pos.second + tmp2, isWhite) && x == pos.first - tmp1 && y == pos.second + tmp2)
			return true;

		if (!map->isIn(pos.first + tmp1, pos.second - tmp2) && x == pos.first + tmp1 && y == pos.second - tmp2)
			return true;
		if (map->isOpponent(pos.first + tmp1, pos.second - tmp2, isWhite) && x == pos.first + tmp1 && y == pos.second - tmp2)
			return true;

		if (!map->isIn(pos.first - tmp1, pos.second - tmp2) && x == pos.first - tmp1 && y == pos.second - tmp2)
			return true;
		if (map->isOpponent(pos.first - tmp1, pos.second - tmp2, isWhite) && x == pos.first - tmp1 && y == pos.second - tmp2)
			return true;
		int temp = tmp1;
		tmp1 = tmp2;
		tmp2 = temp;
	}
	
	//case 1
	

	return false;
}

void Knight::move(ChessBoard *map) {
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

void Knight::Input(ChessBoard *map) {
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

void Knight::setPos(int x, int y){
	pos.first = x;
	pos.second  = y;
}

pair<int, int> Knight::getPos(){
	return pos;
}