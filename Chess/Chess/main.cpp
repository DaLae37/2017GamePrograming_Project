#include "gameTool.h"
#include "Player.h"
#include <conio.h>
int main() {
	gameTool *global = new gameTool();
	Player *whitePlayer = new Player(true);
	Player *blackPlayer = new Player(false);
	int x, y;
	while (!whitePlayer->isGameOver || !blackPlayer->isGameOver) {
		global->drawMap();
		whitePlayer->Update();
		global->setPos(20, 20); 
		global->setColor(White, Black); cin >> x >> y;
		if (!whitePlayer->isGameOver || !blackPlayer->isGameOver)
		blackPlayer->Update();
		getch();
	}
	delete(global);
	return 0;
}