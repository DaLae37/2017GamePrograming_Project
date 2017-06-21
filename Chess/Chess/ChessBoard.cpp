#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			blackKingMap[i][j] = whiteKingMap[i][j] = blackMap[i][j] = whiteMap[i][j] = map[i][j] = false;
		}
	}
}

ChessBoard::~ChessBoard()
{
}
void ChessBoard::whiteKingMove(int now_x, int now_y, int after_x, int after_y){
	blackKingMap[now_y][now_x] = false;
	blackKingMap[after_y][after_x] = true;
}
void ChessBoard::blackKingMove(int now_x, int now_y, int after_x, int after_y){
	whiteKingMap[now_y][now_x] = false;
	whiteKingMap[after_y][after_x] = true;
}
bool ChessBoard::blackCheck(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (blackKingMap[i][j]  && blackKingMap[i][j] == blackMap[i][j])
				return false;
		}
	}
	return true;
}

bool ChessBoard::whiteCheck(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (whiteKingMap[i][j] && whiteKingMap[i][j] == whiteMap[i][j])
				return false;
		}
	}
	return true;
}

void ChessBoard::PieceIn(int x, int y, bool isWhite) {
	map[y][x] = true;
	if (isWhite)
		whiteMap[y][x] = true;
	else
		blackMap[y][x] = true;
}
void ChessBoard::blackMakeFalse(int x, int y) {
	blackMap[y][x] = false;
}
void ChessBoard::whiteMakeFalse(int x, int y) {
	whiteMap[y][x] = false;
}
void ChessBoard::MakeFalse(int x, int y) {
	map[y][x] = false;
}
bool ChessBoard::isIn(int x, int y) {
	return map[y][x];
}

bool ChessBoard::isWhiteIn(int x, int y) {
	return whiteMap[y][x];
}

bool ChessBoard::isBlackIn(int x, int y) {
	return blackMap[y][x];
}

bool ChessBoard::isOpponent(int x, int y, bool isWhite) {
	if (isWhite)
		return blackMap[y][x];
	else
		return whiteMap[y][x];
}