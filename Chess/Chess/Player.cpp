#include "Player.h"

Player::Player(bool isWhite, ChessBoard *gameMap)
{
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
		if (isWhite) {
			pair<int, int> now = pc[i]->getPos();
			if(gameMap->isWhiteIn(now.first, now.second))
				pc[i]->draw();
		}
		else {
			pair<int, int> now = pc[i]->getPos();
			if (gameMap->isBlackIn(now.first, now.second))
				pc[i]->draw();
		}
	}
}

void Player::Update(ChessBoard *gameMap) {
	if (pc[12] == NULL) {
		isGameOver = true;
		return;
	}
	InputCheck(gameMap);
	draw(gameMap);
	int tmp;
	for (int i = 0; i < 16; i++) {
		if (pc[i]->isSelected) {
			tmp = i;
			pc[i]->move(gameMap);
		}
	}
	global->drawMap();
	draw(gameMap);
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
	global->setPos(30, 20);
	global->setColor(White, Black);
	cin >> y >> x;
	global->clearUnder();
	cout << "        ";
	for (int i = 0; i < 16; i++) { 
		pair<int, int> now = pc[i]->getPos();
		if (now.first == x && now.second == y && CanMoveCheck(map, i)) {
			pc[i]->isSelected = true;
			return;
		}
	}
	global->setPos(30, 22); cout << "잘못된 입력!";
	getch();
	global->clearUnder();
	InputCheck(map);
}