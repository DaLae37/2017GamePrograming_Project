#include "gameTool.h"
void gameTool::drawMap() {

	setPos(0, 0); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 1); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 2); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 3); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 4); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 5); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 6); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 7); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 8); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 9); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 10); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 11); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 12); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 13); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 14); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
	setPos(0, 15); setColor(DarkGray, Gray); cout << "��    ��    ��    ��    ��    ��    ��    ��    ��";
	setPos(0, 16); setColor(DarkGray, Gray); cout << "��������������������������������������������������";
}
void gameTool::exdrawMap() {

	setPos(55, 0); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 1); setColor(White, Black); cout << "��0  0��0  1��0  2��0  3��0  4��0  5��0  6��0  7��";
	setPos(55, 2); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 3); setColor(White, Black); cout << "��1  0��1  1��1  2��1  3��1  4��1  5��1  6��1  7��";
	setPos(55, 4); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 5); setColor(White, Black); cout << "��2  0��2  1��2  2��2  3��2  4��2  5��2  6��2  7��";
	setPos(55, 6); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 7); setColor(White, Black); cout << "��3  0��3  1��3  2��3  3��3  4��3  5��3  6��3  7��";
	setPos(55, 8); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 9); setColor(White, Black); cout << "��4  0��4  1��4  2��4  3��4  4��4  5��4  6��4  7��";
	setPos(55, 10); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 11); setColor(White, Black); cout << "��5  0��5  1��5  2��5  3��5  4��5  5��5  6��5  7��";
	setPos(55, 12); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 13); setColor(White, Black); cout << "��6  0��6  1��6  2��6  3��6  4��6  5��6  6��6  7��";
	setPos(55, 14); setColor(White, Black); cout << "��������������������������������������������������";
	setPos(55, 15); setColor(White, Black); cout << "��7  0��7  1��7  2��7  3��7  4��7  5��7  6��7  7��";
	setPos(55, 16); setColor(White, Black); cout << "��������������������������������������������������";
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