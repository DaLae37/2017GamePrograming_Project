#include "Pawn.h"

Pawn::Pawn(int x, int y, bool isWhite) : Pieces(x, y, isWhite)
{
	isOnceMoved = false;
	isSelectedFinish = true;
	this->isWhite = isWhite;
	pos = make_pair(x, y);
}

Pawn::~Pawn()
{
}

void Pawn::draw() {
	global->setPos((pos.first) * 6 + 32, (pos.second) * 2 + 8);
	if (isWhite)
		global->setColor(White, Gray);
	else
		global->setColor(Black, Gray);
	if (isSelected)
		global->setColor(White, SkyBlue);
	cout << "포온";
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
		if (map->isOpponent(pos.first + white, pos.second  + white, isWhite) && pos.first + white == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first - white, pos.second + white, isWhite) && pos.first - white == x && pos.second + white == y)
			return true;
	}
	else {
		if (!map->isIn(pos.first, pos.second + white) && pos.first == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first + white, pos.second + white, isWhite) && pos.first + white == x && pos.second + white == y)
			return true;
		if (map->isOpponent(pos.first - white, pos.second + white, isWhite) && pos.first - white == x && pos.second + white == y)
			return true;
	}
	return false;
}

void Pawn::move(ChessBoard *map) {
	int x, y;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (canMove(map, j, i)) {
				global->setPos((j) * 6 + 32, (i) * 2 + 8);
				cout << "####";
			}
		}
	}
	Input(map);
}

void Pawn::Input(ChessBoard *map) {
	int x, y;
	INPUT_RECORD rec;
	DWORD        dwNOER;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1){
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
		if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
			{
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
				COORD Coor = { 0, 0 };
				DWORD dw;
				x = (mouse_x-31)/6;
				y = (mouse_y-7)/2;
				
				if (canMove(map, x, y)) {
					isSelected = false;
					if (!isOnceMoved)
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
					continue;
				else {
					isSelectedFinish = true;
					return;
				}
			}
			else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED){
				isSelected = false;
				isSelectedFinish = false;
				return;
			}
		}
	}
}

pair<int, int> Pawn::getPos() {
	return pos;
}