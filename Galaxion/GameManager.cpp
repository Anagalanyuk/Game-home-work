#include "GameManager.h"
#include <Windows.h>
#include <conio.h>
#include "DrawFunctions.h"
#include <ctime>
#include <iostream>

using namespace ingameObjects;
using namespace drawFunctions;

void GameManager::StartGame()
{
	srand(time(NULL));
	SetConsoleTitle(TEXT("Galaxion"));
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD consoleWindowSize = { 100, 30 };
	SMALL_RECT src = { 0, 0, consoleWindowSize.X - 1, consoleWindowSize.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, consoleWindowSize);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(out_handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(out_handle, &structCursorInfo);

	GameField field = {};
	field.size.height = FIELD_SIZE_Y;
	field.size.width = FIELD_SIZE_X;
	DrawBorder(field);

	Position heroSrartPosition = { (FIELD_SIZE_X + X_SHIFT) / 2, FIELD_SIZE_Y - 1 };
	Ship* heroShip = CreateShip(heroSrartPosition, true);
	DrawShip(heroShip);

	Ship** enemyShip;
	const int shipsPerLine = FIELD_SIZE_X / 4;
	int enemyShipsCount = shipsPerLine * 3;
	CreateShipArr(enemyShip, enemyShipsCount, shipsPerLine);

	Shot* shots = nullptr;
	int shotsSize = 0;
	int shotsDelay = rand() % 30;
	bool isGameNotOver = true;
	while (isGameNotOver)
	{
		if (0 == shotsDelay)
		{
			shotsDelay = rand() % 30;
			CreateShot(shots, GetPositionForEnemyShot(heroShip, enemyShip, enemyShipsCount), shotsSize);
		}
		else
		{
			--shotsDelay;
		}
		if (_kbhit())
		{
			Key key = ReadKey();
			OnKeyPressed(key, shots, shotsSize, heroShip);
		}
		isGameNotOver = ShotsColisionCheck(shots, shotsSize, heroShip, enemyShip, enemyShipsCount);
		MoveShots(shots, shotsSize);
		Sleep(constants::FRAME_UPDATE_DELAY);
	}
	delete[](*enemyShip);
	if(nullptr != shots)
		delete []shots;
	if (heroShip)
		delete heroShip;
	system("Pause");
}

Ship* GameManager::CreateShip(const Position position, const bool isHeroShip /*= false*/)
{
	Ship* ship = new Ship;
	if (isHeroShip)
		ship->life = 1;
	else
		ship->life = 5;
	ship->position.x = position.x;
	ship->position.y = position.y;
	for (int i = 0; i < SHIP_SIZE; ++i)
	{
		if(isHeroShip && i > 3)
			ship->points[i].symbol = ' ';
		else
			ship->points[i].symbol = '*';
	}
	PositionShip(*ship);

	return ship;
}

void GameManager::CreateShipArr(Ship**& const enemyShip, const int enemyShipsCount, const int shipsPerLine)
{
	Position enemySrartPosition = { X_SHIFT + 2, Y_SHIFT + 1 };
	enemyShip = new Ship*[enemyShipsCount];
	for (int i = 0, shipsCounter = 1; i < enemyShipsCount; ++i, ++shipsCounter)
	{
		enemyShip[i] = CreateShip(enemySrartPosition);
		DrawShip(enemyShip[i]);
		if (!(shipsCounter % shipsPerLine))
		{
			enemySrartPosition.y += 4;
			enemySrartPosition.x = X_SHIFT + 2;
		}
		else
		{
			enemySrartPosition.x += 4;
		}
	}
}

void GameManager::CreateShot(Shot*& shots, const Position position, int& shotsSize, const bool isHeroShot)
{
	if (position.x >= 0 && position.y >= 0)
	{
		Shot* shotsTmp = new Shot[shotsSize + 1];
		for (int i = 0; i < shotsSize; ++i)
			shotsTmp[i] = shots[i];
		shotsTmp[shotsSize].isHeroShot = isHeroShot;
		shotsTmp[shotsSize].point.symbol = '*';
		shotsTmp[shotsSize].point.position.x = position.x;
		shotsTmp[shotsSize].point.position.y = (position.y + (isHeroShot ? -2 : 2));
		++shotsSize;
		if (nullptr != shots)
			delete[] shots;
		shots = shotsTmp;
	}
}

void GameManager::DeleteShotByPosition(Shot*& shots, int& shotsSize, const int pos)
{
	Draw(shots[pos].point.position);
	Shot* shotsTmp = new Shot[shotsSize - 1];
	for (int i = 0; i < pos; ++i)
		shotsTmp[i] = shots[i];
	for (int i = pos; i < shotsSize - 1; ++i)
		shotsTmp[i] = shots[i + 1];
	if (nullptr != shots)
		delete[] shots;
	shots = shotsTmp;
	--shotsSize;
}

void GameManager::MoveShots(Shot*& const shots, int& const shotsSize)
{
	DrawShots(shots, shotsSize, true);
	for (int i = 0; i < shotsSize; ++i)
	{
		if (shots[i].isHeroShot)
			--shots[i].point.position.y;
		else
			++shots[i].point.position.y;
	}
	DrawShots(shots, shotsSize);
}

bool GameManager::IsShipHit(Ship*& ship, const Position shotPos)
{
	bool isHit = false;

	if ((nullptr != ship) && (shotPos.x <= ship->position.x + 1) && (shotPos.x >= ship->position.x - 1) && (shotPos.y <= ship->position.y + 1) && (shotPos.y >= ship->position.y - 1))
		isHit = true;

	return isHit;
}

bool GameManager::IsAllEnemyiesKilled(Ship**& const enemyShip, const int enemyShipsCount)
{
	bool isAllEnemiesKilled = true;
	for (int i = 0; i < enemyShipsCount; ++i)
	{
		if (nullptr != enemyShip[i])
		{
			isAllEnemiesKilled = false;
			break;
		}
	}
	return isAllEnemiesKilled;
}

void GameManager::GameOver(bool isWin)
{
	Draw(Position{ (FIELD_SIZE_X / 2) - 5, FIELD_SIZE_Y / 2 }, ' ');
	if (true == isWin)
		std::cout << "You won\n";
	else
		std::cout << "You lose\n";
	Draw(Position{ (FIELD_SIZE_X / 2) - 5, (FIELD_SIZE_Y / 2) + 2 }, ' ');
}

bool GameManager::ShotsColisionCheck(Shot*& shots, int& shotsSize, Ship*& ship, Ship**& const enemyShip, int& enemyShipsCount)
{
	bool isGameNotOver = true;
	for (int i = 0; i < shotsSize; ++i)
	{
		if ((shots[i].point.position.y <= Y_SHIFT) || shots[i].point.position.y >= FIELD_SIZE_Y)
		{
			DeleteShotByPosition(shots, shotsSize, i);
		}
	}
	for (int i = 0; i < shotsSize - 1; ++i)
	{
		for (int j = i + 1; j < shotsSize; ++j)
		{
			if ((shots[i].point.position.x == shots[j].point.position.x) &&
				(shots[i].point.position.y - shots[j].point.position.y == -1 ||
					shots[i].point.position.y - shots[j].point.position.y == 0))
			{
				DeleteShotByPosition(shots, shotsSize, i);
				DeleteShotByPosition(shots, shotsSize, j - 1);
			}
		}
	}
	for (int i = 0; i < shotsSize; ++i)
	{
		if (IsShipHit(ship, shots[i].point.position))
		{
			DeleteShotByPosition(shots, shotsSize, i);
			DrawShip(ship, true);
			delete ship;
			ship = nullptr;
			isGameNotOver = false;
			GameOver(false);
			break;
		}
		for (int j = 0; j < enemyShipsCount; ++j)
		{
			if (IsShipHit(enemyShip[j], shots[i].point.position))
			{
				DeleteShotByPosition(shots, shotsSize, i);
				if (--enemyShip[j]->life <= 0)
				{
					DrawShip(enemyShip[j], true);
					delete enemyShip[j];
					enemyShip[j] = nullptr;
					if (IsAllEnemyiesKilled(enemyShip, enemyShipsCount))
					{
						isGameNotOver = false;
						GameOver();
						break;
					}
				}
				else
				{
					DrawShip(enemyShip[j]);
				}
			}
		}
	}
	return isGameNotOver;
}

Position GameManager::GetPositionForEnemyShot(Ship*& const ship, Ship**& const enemyShip, const int enemyShipsCount)
{
	Position pos = {};
	for (int i = (enemyShipsCount - 1); i >= 0; --i)
	{
		if ((nullptr != enemyShip[i]) && (enemyShip[i]->position.x >= (ship->position.x - 2) && enemyShip[i]->position.x <= ship->position.x))
		{
			pos.x = enemyShip[i]->position.x;
			pos.y = enemyShip[i]->position.y;
			break;
		}
		else
		{
			pos.x = -1;
			pos.y = -1;
		}
	}
	return pos;
}

void GameManager::PositionShip(Ship & ship)
{
	ship.points[1].position.x = ship.position.x;
	ship.points[1].position.y = ship.position.y;

	ship.points[0].position.x = ship.position.x;
	ship.points[0].position.y = ship.position.y - 1;
		
	ship.points[2].position.x = ship.position.x - 1;
	ship.points[2].position.y = ship.position.y + 1;
		
	ship.points[3].position.x = ship.position.x + 1;
	ship.points[3].position.y = ship.position.y + 1;
		
	ship.points[4].position.x = ship.position.x - 1;
	ship.points[4].position.y = ship.position.y;
		
	ship.points[5].position.x = ship.position.x + 1;
	ship.points[5].position.y = ship.position.y;
}

void GameManager::OnKeyPressed(const Key& key, Shot*& shots, int& shotsSize, Ship*& const ship)
{
	if (ship)
		DrawShip(ship, true);
	switch (key)
	{
	case Key::Left:
		if (ship && (ship->position.x > (X_SHIFT + 1)))
			--ship->position.x;
		break;
	case Key::Right:
		if (ship && (ship->position.x < (FIELD_SIZE_X + (X_SHIFT - 2))))
			++ship->position.x;
		break;
	case Key::Space:
		CreateShot(shots, ship->position, shotsSize, true);
		break;
	case Key::Esc:
		break;
	default:
		break;
	}
	if (ship)
	{
		PositionShip(*ship);
		DrawShip(ship);
	}
}
