#include "gameTool.h"
#include "Player.h"
#include "ChessBoard.h"
#include <conio.h>
gameTool *global = new gameTool();
void mainMenu(){
	cout << "                                                 _/                      ";
	cout << "    _/_/_/  _/_/_/  _/_/      _/_/_/  _/_/_/_/      _/_/_/      _/_/_/   ";
	cout << " _/    _/  _/    _/    _/  _/    _/      _/    _/  _/    _/  _/    _/    ";
	cout << "_/    _/  _/    _/    _/  _/    _/    _/      _/  _/    _/  _/    _/     ";
	cout << " _/_/_/  _/    _/    _/    _/_/_/  _/_/_/_/  _/  _/    _/    _/_/_/      ";
	cout << "             _/                            _/                   _/       ";
	cout << "    _/_/_/  _/_/_/      _/_/      _/_/_/  _/  _/      _/_/_//_/          ";
	cout << " _/        _/    _/  _/_/_/_/  _/        _/_/      _/_/                  ";
	cout << "_/        _/    _/  _/        _/        _/  _/        _/_/               ";
	cout << " _/_/_/  _/    _/    _/_/_/    _/_/_/  _/    _/  _/_/_/                  ";
	cout << "                                        input any key                  ";
	getch();
}
int main() {	
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
	global->clearUnder();
	global->setColor(White, Black);
	global->setPos(20, 20);
	getch();
	if (gameMap->blackCheck())
		cout << "¹é ½Â¸®!";
	else
		cout << "Èæ ½Â¸®!";
	delete(global);
	return 0;
}