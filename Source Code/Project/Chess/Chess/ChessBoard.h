#pragma once
class ChessBoard
{
private:
	bool map[8][8];
	bool whiteMap[8][8];
	bool blackMap[8][8];
	bool whiteKingMap[8][8];
	bool blackKingMap[8][8];
public:
	ChessBoard();
	~ChessBoard();
	void PieceIn(int x, int y, bool isWhite);
	void blackMakeFalse(int x, int y);
	void whiteMakeFalse(int x, int y);
	void blackKingMove(int now_x, int now_y, int after_x, int after_y);
	void whiteKingMove(int now_x, int now_y, int after_x, int after_y);
	void MakeFalse(int x, int y);
	bool isIn(int x, int y);
	bool isOpponent(int x, int y, bool isWhite);
	bool isWhiteIn(int x, int y);
	bool isBlackIn(int x, int y);
	bool whiteCheck();
	bool blackCheck();
};

