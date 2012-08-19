#include"enemies.h"


Enemy::Enemy(int x, int y)
{
	e_x = x;
	e_y = y;
	e_health = 1;
	e_symbol = 'V';
}


int Enemy::GetX()
{
	return e_x;
}


int Enemy::GetY()
{
	return e_y;
}


char Enemy::GetSymbol()
{
	return e_symbol;
}


void Enemy::SetX(int x)
{
	e_x = x;
}


void Enemy::SetY(int y)
{
	e_y = y;
}


void Enemy::Move()
{
	e_y=e_y+1;
}






