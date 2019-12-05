#pragma once
#include <SFML/Graphics.hpp>

class Snake
{
public:
	int x, y; 
	Snake();
	void Moving(int num, int dir, Snake *s);
};