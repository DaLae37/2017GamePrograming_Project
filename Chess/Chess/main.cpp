#include "gameTool.h"
#include "Player.h"
#include <conio.h>
int main() {
	gameTool *global = new gameTool();
	Player *whitePlayer = new Player(true);
	Player *blackPlayer = new Player(false);

	while (!whitePlayer->isGameOver || !blackPlayer->isGameOver) {
		global->drawMap();
		whitePlayer->Update();
		blackPlayer->Update();
		getch();
	}
	delete(global);
	return 0;
}