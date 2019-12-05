#pragma once
#include <SFML/Graphics.hpp>
#include "Fruit.h"
#include <iostream>

class Snake
{
public:
	int x, y; 
	Snake();
	void Moving(int num, int dir, Snake *s);
	void Death(Snake* s, int &num, Fruit &f);
	void Eaten(int &num, Fruit &f, Snake* s);
};