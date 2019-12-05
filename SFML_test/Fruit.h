#pragma once
#include <SFML/Graphics.hpp>

class Fruit
{
public:
	int x, y;
	Fruit();
	Fruit(int _x, int _y);
	void spawn_new();
	void spawn_new(int _x, int _y);
};