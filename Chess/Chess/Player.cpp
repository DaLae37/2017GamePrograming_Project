#include "Player.h"

Player::Player(bool isWhite)
{
	isGameOver = false;
	if (isWhite) {
		for (int i = 0; i<8; i++)
			pc[i] = new Pawn(i,6, isWhite);
		pc[8] = new Look(0, 7, isWhite);
		pc[15] = new Look(7, 7, isWhite);
		pc[9] = new Knight(1, 7, isWhite);
		pc[14] = new Knight(6, 7, isWhite);
		pc[10] = new Bishop(2, 7, isWhite);
		pc[13] = new Bishop(5, 7, isWhite);
		pc[11] = new Queen(3, 7, isWhite);
		pc[12] = new King(4, 7, isWhite);
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
		
}

Player::~Player()
{
}

void Player::Update() {
	for (int i = 0; i < 16; i++){
		pc[i]->draw();
		pc[i]->getPos() == 
	}
		
}