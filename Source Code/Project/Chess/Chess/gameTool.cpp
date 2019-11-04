#include "gameTool.h"
gameTool::gameTool() {

}
void gameTool::drawMap() {

	setPos(30, 7); setColor(DarkGray, Gray); cout << "忙式式成式式成式式成式式成式式成式式成式式成式式忖";
	setPos(30, 8); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 9); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 10); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 11); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 12); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 13); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 14); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 15); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 16); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 17); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 18); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 19); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 20); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 21); setColor(DarkGray, Gray); cout << "戍式式托式式托式式托式式托式式托式式托式式托式式扣";
	setPos(30, 22); setColor(DarkGray, Gray); cout << "弛    弛    弛    弛    弛    弛    弛    弛    弛";
	setPos(30, 23); setColor(DarkGray, Gray); cout << "戌式式扛式式扛式式扛式式扛式式扛式式扛式式扛式式戎";
}
void gameTool::exdrawMap() {

	for (int i = 0; i < 32; i++){
		for (int j = 0; j < 120; j++){
			setPos(j, i); setColor(White, Black); cout << " ";
		}
	}
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

void gameTool::whiteTurn() {
	setColor(White, Black); setPos(15, 8); cout << "@   @  @ @";
	setPos(15,9); cout<<"@   @  @ @";
	setPos(15,10); cout<<"@@@@@  @ @";
	setPos(15,11); cout<<"@   @  @@@";
	setPos(15,12); cout<<"@   @  @ @";
	setPos(15,13); cout<<"@@@@@  @ @";
	setPos(15,14); cout<<"       @ @";
	setPos(15,15); cout<<"  ========";
	setPos(15,16); cout<<"         @";
	setPos(15,17); cout<<"         @";
	setPos(15,18); cout<<"         @";
	setPos(15,19); cout<<"         @";
	setPos(85, 8); cout << "               ";
	setPos(85, 9); cout << "               ";
	setPos(85, 10); cout << "               ";
	setPos(85, 11); cout << "               ";
	setPos(85, 12); cout << "               ";
	setPos(85, 13); cout << "               ";
	setPos(85, 14); cout << "               ";
	setPos(85, 15); cout << "               ";
	setPos(85, 16); cout << "               ";
	setPos(85, 17); cout << "               ";
	setPos(85, 18); cout << "               ";
	setPos(85, 19); cout << "               ";
	setPos(85, 20); cout << "               ";
}

void gameTool::blackTurn() {
	setColor(White, Black); setPos(15, 8); cout << "              ";
	setPos(15, 9); cout << "               ";
	setPos(15, 10); cout << "               ";
	setPos(15, 11); cout << "               ";
	setPos(15, 12); cout << "               ";
	setPos(15, 13); cout << "               ";
	setPos(15, 14); cout << "               ";
	setPos(15, 15); cout << "               ";
	setPos(15, 16); cout << "               ";
	setPos(15, 17); cout << "               ";
	setPos(15, 18); cout << "               ";
	setPos(15, 19); cout << "               ";
	setColor(Black, White);
	setPos(85,8); cout<<"     -      ";
	setPos(85,9); cout<<"     :.     ";
	setPos(85,10); cout<<" ********** ";
	setPos(85,11); cout<<"  .@@@@@@   ";
	setPos(85,12); cout<<"  @      @  ";
	setPos(85,13); cout<<"  @     ,@  ";
	setPos(85,14); cout<<"   ;@@@@~   ";
	setPos(85,15); cout<<";;;;;;;;;;;;";
	setPos(85,16); cout<<"            ";
	setPos(85,17); cout<<" ,@@@@@@@@  ";
	setPos(85,18); cout<<"         @  ";
	setPos(85,19); cout<<"         @  ";
	setPos(85,20); cout<<"         @  ";
}
void gameTool::setColor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}