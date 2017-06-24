#include "Player.h"

Player::Player(bool isWhite, ChessBoard *gameMap)
{
	m = new Mouse();
	gameTool *global = new gameTool();
	isGameOver = false;
	this->isWhite = isWhite;
	if (isWhite) {
		for (int i = 0; i<8; i++)
			pc[i] = new Pawn(i,6, isWhite);
		pc[8] = new Look(0, 7, isWhite);
		pc[15] = new Look(7, 7, isWhite);
		pc[9] = new Knight(1, 7, isWhite);
		pc[14] = new Knight(6, 7, isWhite);
		pc[10] = new Bishop(2, 7, isWhite);
		pc[13] = new Bishop(5, 7, isWhite);
		pc[11] = new Queen(4, 7, isWhite);
		pc[12] = new King(3, 7, isWhite);
	}
	else {
		for (int i = 0; i<8; i++)
			pc[i] = new Pawn(i, 1, isWhite);
		pc[8] = new Look(0, 0, isWhite);
		pc[15] = new Look(7, 0, isWhite);
		pc[9] = new Knight(1, 0, isWhite);
		pc[14] = new Knight(6, 0, isWhite);
		pc[10] = new Bishop(2, 0, isWhite);
		pc[13] = new Bishop(5, 0, isWhite);
		pc[11] = new Queen(4, 0, isWhite);
		pc[12] = new King(3, 0, isWhite);
	} //각각 플레이어의 말 초기화 부분
	for (int i = 0; i < 16; i++) {
		pair<int, int> pos = pc[i]->getPos();
		gameMap->PieceIn(pos.first, pos.second, isWhite);
	}
}

Player::~Player()
{

}

void Player::draw(ChessBoard *gameMap) {
	for (int i = 0; i < 16; i++) {
		if (isWhite && pc[i] != NULL) {
			pair<int, int> now = pc[i]->getPos();
			if(gameMap->isWhiteIn(now.first, now.second))
				pc[i]->draw();
		}
		else if(pc[i] != NULL){
			pair<int, int> now = pc[i]->getPos();
			if (gameMap->isBlackIn(now.first, now.second))
				pc[i]->draw();
		}
	}
}

void Player::Update(ChessBoard *gameMap, Player *opponenet) {

	InputCheck(gameMap);
	draw(gameMap);
	int tmp;
	for (int i = 0; i < 16; i++) {
		if (pc[i]!= NULL && pc[i]->isSelected) {
			tmp = i;
			pc[i]->move(gameMap);
		}
	}
	global->drawMap();
	draw(gameMap);
	opponenet->draw(gameMap);
	if (!pc[tmp]->isSelectedFinish) {
		Update(gameMap, opponenet);
	}
	for (int k = 0; k < 16; k++) {
		if (isWhite) {
			if (opponenet->pc[k]!= NULL && !gameMap->isBlackIn(opponenet->pc[k]->getPos().first, opponenet->pc[k]->getPos().second)) {
				opponenet->pc[k] = NULL;
			}
		}
		else {
			if (opponenet->pc[k] != NULL && !gameMap->isWhiteIn(opponenet->pc[k]->getPos().first, opponenet->pc[k]->getPos().second)) {
				opponenet->pc[k] = NULL;
			}
		}
	}
}
bool Player::CanMoveCheck(ChessBoard *map, int x) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pc[x]->canMove(map, j, i))
				return true;
		}
	}
	return false;
}
void Player::InputCheck(ChessBoard *map) {
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
				global->setPos(10, 0); cout << mouse_x << " " << mouse_y;
				for (int i = 0; i < 16; i++) {
					if (pc[i] == NULL)
						continue;
					pair<int, int> now = pc[i]->getPos();
					if (now.first == (mouse_x - 31) / 6 && now.second == (mouse_y - 7) / 2 && CanMoveCheck(map, i)) {
						if (isWhite && map->isWhiteIn(now.first,now.second)) {
							pc[i]->isSelected = true;
							return;
						}
						else if (!isWhite && map->isBlackIn(now.first, now.second)) {
							pc[i]->isSelected = true;
							return;
						}
					}
				}
			}
		}
	}
}