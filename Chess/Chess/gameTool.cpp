#include "gameTool.h"
void gameTool::drawMap() {

	setPos(0, 0); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 1); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 2); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 3); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 4); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 5); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 6); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 7); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 8); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 9); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 10); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 11); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 12); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 13); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 14); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(0, 15); setColor(White, Black); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 16); setColor(White, Black); cout << "��������������������������������������������������";
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