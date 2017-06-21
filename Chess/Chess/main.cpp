#include "gameTool.h"
#include "Player.h"
#include "ChessBoard.h"
#include <conio.h>
int main() {
	system("title Ã¼½º");
	system("mode con:cols=120 lines=32");
	gameTool *global = new gameTool();
	ChessBoard *gameMap = new ChessBoard();
	Player *whitePlayer = new Player(true, gameMap);
	Player *blackPlayer = new Player(false, gameMap);

	global->drawMap();
	global->exdrawMap();
	whitePlayer->draw(gameMap);
	blackPlayer->draw(gameMap);

	while (!gameMap->whiteCheck()) {
		whitePlayer->Update(gameMap);
		blackPlayer->draw(gameMap);
		if (gameMap->blackCheck())
			break;
		blackPlayer->Update(gameMap);
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