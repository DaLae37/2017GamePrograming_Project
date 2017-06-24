#include "gameTool.h"
#include "Player.h"
#include "ChessBoard.h"
#include <conio.h>
#include<MMSystem.h> // ¹è°æÀ½¾Ç ¶§¹®¿¡ »ç¿ë
#pragma comment(lib,"Winmm.lib") // ¹è°æÀ½¾Ç
gameTool *global = new gameTool();
void mainMenu(){
	global->setColor(White, Black);
	global->setPos(25, 3); cout << "                                                 _/                      ";
	global->setPos(25, 4);cout << "    _/_/_/  _/_/_/  _/_/      _/_/_/  _/_/_/_/      _/_/_/      _/_/_/   ";
	global->setPos(25, 5);cout << " _/    _/  _/    _/    _/  _/    _/      _/    _/  _/    _/  _/    _/    ";
	global->setPos(25, 6);cout << "_/    _/  _/    _/    _/  _/    _/    _/      _/  _/    _/  _/    _/     ";
	global->setPos(25, 7);cout << " _/_/_/  _/    _/    _/    _/_/_/  _/_/_/_/  _/  _/    _/    _/_/_/      ";
	global->setPos(25, 8);cout << "             _/                            _/                   _/       ";
	global->setPos(25, 9);cout << "                                                                         ";
	global->setPos(25, 10);cout << "                                                                         ";
	global->setPos(25, 11);cout << "                                                                         ";
	global->setPos(25, 12);cout << "    _/_/_/  _/_/_/      _/_/      _/_/_/  _/  _/      _/_/_//_/          ";
	global->setPos(25, 13);cout << " _/        _/    _/  _/_/_/_/  _/        _/_/      _/_/                  ";
	global->setPos(25, 14);cout << "_/        _/    _/  _/        _/        _/  _/        _/_/               ";
	global->setPos(25, 15);cout << " _/_/_/  _/    _/    _/_/_/    _/_/_/  _/    _/  _/_/_/                  ";
	global->setPos(25, 20);cout << "                              input any key                  ";
	getch();
}
int main() {	
	sndPlaySoundA("bgm.wav", SND_ASYNC | SND_NODEFAULT | SND_LOOP);
	global->exdrawMap();
	mainMenu();
	ChessBoard *gameMap = new ChessBoard();
	Player *whitePlayer = new Player(true, gameMap);
	Player *blackPlayer = new Player(false, gameMap);

	global->exdrawMap();
	global->drawMap();

	whitePlayer->draw(gameMap);
	blackPlayer->draw(gameMap);

	while (!gameMap->whiteCheck()) {
		whitePlayer->Update(gameMap,blackPlayer);
		blackPlayer->draw(gameMap);
		if (gameMap->blackCheck())
			break;
		blackPlayer->Update(gameMap,whitePlayer);
		whitePlayer->draw(gameMap);
	}
	global->setColor(White, Black);
	global->setPos(0, 0);
	system("cls");
	for (int i = 0; i < 120; i++) {
		for (int j = 0; j < 15; j++) {
			global->setColor(j % 15 + 1, Black);
			cout << "¢Ã";
			Sleep(1);
		}
	}
	system("cls");
	global->setPos(50, 25);
	if (gameMap->blackCheck())
		cout << "¹é ½Â¸®!";
	else
		cout << "Èæ ½Â¸®!";
	delete(global);
	return 0;
}