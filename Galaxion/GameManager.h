#ifndef _GAME_MANAGER_
#define _GAME_MANAGER_

#include "ConsoleFunctions.h"

using namespace ingameObjects;
using namespace consoleFunctions;
using namespace constants;

namespace GameManager
{
	void		StartGame();
	void		PositionShip(Ship& ship);
	void		OnKeyPressed(const Key& key, Shot*& shots, int& shotsSize, Ship*& const ship);
	Ship*		CreateShip(const Position position, const bool isHeroShip = false);
	void		CreateShipArr(Ship**& const shipconst, const int enemyShipsCount, const int shipsPerLine);
	void		CreateShot(Shot*& shots, const Position position, int& shotsSize, const bool isHeroShot = false);
	void		DeleteShotByPosition(Shot*& shots, int& shotsSize, const int pos);
	void		MoveShots(Shot*& const shots, int& const shotsSize);
	bool		ShotsColisionCheck(Shot*& shots, int& shotsSize, Ship*& ship, Ship**& const enemyShip, int& enemyShipsCount);
	Position	GetPositionForEnemyShot(Ship*& const ship, Ship**& const enemyShip, const int enemyShipsCount);
	bool		IsShipHit(Ship*& ship, const Position shotPos);
	bool		IsAllEnemyiesKilled(Ship**& const enemyShip, const int enemyShipsCount);
	void		GameOver(bool isWin = true);
}

#endif // !_GAME_MANAGER_

