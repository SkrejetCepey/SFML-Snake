#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Snake.h"
//#include "Fruit.h"
#include "Menu.h"

using namespace sf;
using namespace std;

int N = 20, M = 20;
int size_pix = 16;
int w = size_pix * N;
int h = size_pix * M;

int mass[20][20];

Snake s;

int dir = 3;
int num = 4;

RenderWindow window(VideoMode(w, h), "Snake Game!", Style::Close);

void start_game()
{
	srand(time(0));

	Texture t1, t2, t3;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");
	t3.loadFromFile("images/green.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);

	Clock clock;
	float timer = 0, delay = 0.1;

	while (window.isOpen())
	{
		float delta = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += delta;

		if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 0;
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			dir = 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 3;
		
		if (timer > delay) 
		{
			timer = 0; 
			s.Moving(dir, mass);
		}

		////// draw  ///////
		window.clear();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				switch (mass[j][i])
				{
				case 0:
					sprite1.setPosition(i * size_pix, j * size_pix);
					window.draw(sprite1);
					break;
				case 1:
					sprite3.setPosition(i * size_pix, j * size_pix);
					window.draw(sprite3);
					break;
				case 3:
					sprite2.setPosition(i * size_pix, j * size_pix);
					window.draw(sprite2);
					break;
				}
			}
		window.display();
	}
}

int main()
{
	mass[5][0] = 1;
	mass[6][0] = 1;
	mass[7][0] = 1;

	mass[7][8] = 3;

	s.seg[0].x = 7;
	s.seg[0].value = 1;

	s.seg[1].x = 6;
	s.seg[1].value = 1;

	s.seg[2].x = 5;
	s.seg[2].value = 1;

	s.seg[3].x = 4;
	s.seg[3].value = 0;

	menu(window);
	start_game();
	return 0;
}

