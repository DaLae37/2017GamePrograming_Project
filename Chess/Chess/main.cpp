#include "gameTool.h"
#include "Player.h"
#include "ChessBoard.h"
#include <conio.h>
int main() {
	gameTool *global = new gameTool();
	ChessBoard *gameMap = new ChessBoard();
	Player *whitePlayer = new Player(true, gameMap);
	Player *blackPlayer = new Player(false, gameMap);

	global->drawMap();
	whitePlayer->draw(gameMap);
	blackPlayer->draw(gameMap);

	while (!whitePlayer->isGameOver) {
		whitePlayer->Update(gameMap);
		blackPlayer->draw(gameMap);
		if (blackPlayer->isGameOver)
			break;
		blackPlayer->Update(gameMap);
		whitePlayer->draw(gameMap);
	}
	global->setColor(White, Black);
	system("cls");	
	global->setPos(20, 20);
	getch();
	if (whitePlayer->isGameOver)
		cout << "Èæ ½Â¸®!";
	else
		cout << "¹é ½Â¸®!";

	delete(global);
	return 0;
}