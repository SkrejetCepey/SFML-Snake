#pragma once
#include <SFML/Graphics.hpp>

bool isMenu = 1;

void menu(sf::RenderWindow& window) 
{
	int menuNum = 0;
	
	sf::Texture btnTexture1, btnTexture2, btnTexture3, btnTexture4, aboutTexture, settingsTexture, menuBackground;

	btnTexture1.loadFromFile("images/new_game.png");
	btnTexture2.loadFromFile("images/options.png");
	btnTexture3.loadFromFile("images/about_us.png");
	btnTexture4.loadFromFile("images/exit.png");

	aboutTexture.loadFromFile("images/opa!.png");
	settingsTexture.loadFromFile("images/opa!.png");

	menuBackground.loadFromFile("images/Vitya.jpg");

	sf::Sprite btn1(btnTexture1), btn2(btnTexture2), btn3(btnTexture3), btn4(btnTexture4), about(aboutTexture), settings(settingsTexture), menuBg(menuBackground);

	btn1.setPosition(10, 30);
	btn2.setPosition(10, 90);
	btn3.setPosition(10, 150);
	btn4.setPosition(10, 210);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menuNum = 0;

		btn1.setColor(sf::Color::Black);
		btn2.setColor(sf::Color::Black);
		btn3.setColor(sf::Color::Black);
		btn4.setColor(sf::Color::Black);
		window.clear(sf::Color(129, 181, 221));

		if (sf::IntRect(10, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { btn1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(10, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { btn2.setColor(sf::Color::Blue); menuNum = 2; }
		if (sf::IntRect(10, 150, 300, 50).contains(sf::Mouse::getPosition(window))) { btn3.setColor(sf::Color::Blue); menuNum = 3; }
		if (sf::IntRect(10, 210, 300, 50).contains(sf::Mouse::getPosition(window))) { btn4.setColor(sf::Color::Blue); menuNum = 4; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 1:
				isMenu = false;
				break;
			case 2:
				window.draw(about); 
				window.display(); 
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
				break;
			case 3:
				window.draw(settings); 
				window.display(); 
				while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
				break;
			case 4:
				window.close(); 
				isMenu = false;
				break;
			default:
				break;
			}
		}

		window.draw(menuBg);
		window.draw(btn1);
		window.draw(btn2);
		window.draw(btn3);
		window.draw(btn4);

		window.display();
	}
}

void lose(sf::RenderWindow& window)
{
	sf::Texture loseScreenTexture;
	loseScreenTexture.loadFromFile("images/lose_screen.png");
	sf::Sprite loseScreen(loseScreenTexture);
	window.draw(loseScreen);
	window.display();
	while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	isMenu = true;
	menu(window);
}