#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Snake.h"
#include "Fruit.h"
#include "Menu.h"

using namespace sf;

int N = 50, M = 30;
int size = 16;
int w = size * N;
int h = size * M;

Snake s[100];
Fruit f(10, 10);

int dir, num = 4;

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

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 0;

		if (timer > delay) 
		{
			timer = 0; 
			s->Moving(num,dir,s); 
			s->Eaten(num, f, s);
			s->Death(s, num, f);
			if (num==0) 
			{ 
				lose(window); 
			}
		}

		////// draw  ///////
		window.clear();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				sprite1.setPosition(i * size, j * size);  window.draw(sprite1);
			}

		for (int i = 0; i < num; i++)
		{
			sprite3.setPosition(s[i].x * size, s[i].y * size);  window.draw(sprite3);
		}

		sprite2.setPosition(f.x * size, f.y * size);  window.draw(sprite2);

		window.display();
	}
}

int main()
{
	menu(window);
	start_game();
	return 0;
}

