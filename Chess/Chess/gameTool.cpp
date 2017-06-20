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