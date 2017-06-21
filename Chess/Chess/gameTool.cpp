#include "gameTool.h"
void gameTool::drawMap() {

	setPos(0, 0); setColor(DarkGray, Gray); cout << "忙式式成式式成式式成式式成式式成式式成式式成式式忖";
	setPos(0, 1); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 2); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 3); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 4); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 5); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 6); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 7); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 8); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 9); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 10); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 11); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 12); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 13); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 14); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(0, 15); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(0, 16); setColor(DarkGray, Gray); cout << "戌式式扛式式扛式式扛式式扛式式扛式式扛式式扛式式戎";
}
void gameTool::exdrawMap() {

	setPos(55, 0); setColor(White, Black); cout << "忙式式成式式成式式成式式成式式成式式成式式成式式忖";
	setPos(55, 1); setColor(White, Black); cout << "弛0  0弛0  1弛0  2弛0  3弛0  4弛0  5弛0  6弛0  7弛";
	setPos(55, 2); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 3); setColor(White, Black); cout << "弛1  0弛1  1弛1  2弛1  3弛1  4弛1  5弛1  6弛1  7弛";
	setPos(55, 4); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 5); setColor(White, Black); cout << "弛2  0弛2  1弛2  2弛2  3弛2  4弛2  5弛2  6弛2  7弛";
	setPos(55, 6); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 7); setColor(White, Black); cout << "弛3  0弛3  1弛3  2弛3  3弛3  4弛3  5弛3  6弛3  7弛";
	setPos(55, 8); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 9); setColor(White, Black); cout << "弛4  0弛4  1弛4  2弛4  3弛4  4弛4  5弛4  6弛4  7弛";
	setPos(55, 10); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 11); setColor(White, Black); cout << "弛5  0弛5  1弛5  2弛5  3弛5  4弛5  5弛5  6弛5  7弛";
	setPos(55, 12); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 13); setColor(White, Black); cout << "弛6  0弛6  1弛6  2弛6  3弛6  4弛6  5弛6  6弛6  7弛";
	setPos(55, 14); setColor(White, Black); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(55, 15); setColor(White, Black); cout << "弛7  0弛7  1弛7  2弛7  3弛7  4弛7  5弛7  6弛7  7弛";
	setPos(55, 16); setColor(White, Black); cout << "戌式式扛式式扛式式扛式式扛式式扛式式扛式式扛式式戎";
}

void gameTool::clearUnder(){
	setColor(White, Black);
	for (int i = 0; i <= 120; i++){
		for (int j = 0; j <= 10; j++){
			setPos(i, 20 + j); cout << " ";
		}
	}
}

void gameTool::setPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gameTool::setColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}