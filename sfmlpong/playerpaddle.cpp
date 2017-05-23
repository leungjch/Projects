#include "playerpaddle.h"
#include "SFML/Graphics.hpp"
PlayerPaddle::PlayerPaddle() = default;
PlayerPaddle::PlayerPaddle(int length, int width, int posX, int posY, int player)
{
	setSize((sf::Vector2f(length, width)));
	setPosition(posX, posY);
	setFillColor(sf::Color::White);
	setOutlineThickness(5);
	int pLength = length;
	int pWidth = width;
	int pPlayer = player;
	bool isAI = false;
	if (pPlayer == 1)
	{
		keyUp = sf::Keyboard::Key::Up;
		keyDown = sf::Keyboard::Key::Down;
	}
	else if (pPlayer == 2)
	{
		keyUp = sf::Keyboard::Key::W;
		keyDown = sf::Keyboard::Key::S;
	}
	else if (pPlayer == 3)
	{
		isAI = true;
	}
}
void PlayerPaddle::update(double dT, Ball ball)
{
	if (sf::Keyboard::isKeyPressed(keyUp))
	{
		if (getPosition().y > 0)
		{
			PlayerPaddle::move(0, -1 * dT);
		}
	}
	if (sf::Keyboard::isKeyPressed(keyDown))
	{
		if (getPosition().y < SCREENHEIGHT - getSize().y)
		{
			PlayerPaddle::move(0, 1 * dT);
		}
	}
	if (PlayerPaddle::isAI)
	{
		// if ball is coming towards AI
		if (ball.speedX < 0)
		{
			sf::Clock reactionTime;
				if (reactionTime.getElapsedTime() > sf::milliseconds(20))
				{
					ball.speedY;
				}
		}
	}
}