#include "Snake.h"
#include <time.h>

Snake::Snake()
{
	x = 0;
	y = 0;
}

void Snake::Moving(int num, int dir, Snake *s)
{
	for (int i = num; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}

	if (dir == 0) s[0].y += 1;
	if (dir == 1) s[0].x -= 1;
	if (dir == 2) s[0].x += 1;
	if (dir == 3) s[0].y -= 1;

	//if ((s[0].x == f.x) && (s[0].y == f.y))
	//{
	//	num++; f.x = rand() % 50; f.y = rand() % 30;
	//}

	if (s[0].x > 50) s[0].x = 0;  if (s[0].x < 0) s[0].x = 50;
	if (s[0].y > 30) s[0].y = 0;  if (s[0].y < 0) s[0].y = 30;

	for (int i = 1; i < num; i++)
		if (s[0].x == s[i].x && s[0].y == s[i].y)//Death
		{
			num = i;
			//menu(window);
		}
}