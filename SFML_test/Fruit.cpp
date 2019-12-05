#include "Fruit.h"

Fruit::Fruit()
{
	x = 0;
	y = 0;
}

Fruit::Fruit(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Fruit::spawn_new()
{
	x = rand() % 50;
	y = rand() % 30;
}

void Fruit::spawn_new(int _x, int _y)
{
	x = _x;
	y = _y;
}