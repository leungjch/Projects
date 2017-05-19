#include "ball.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>

Ball::Ball(int length, int width)
{
	setSize((sf::Vector2f(length, width)));
	std::srand(std::time(0));
	//setPosition(rand() % SCREENWIDTH - width, rand() % SCREENHEIGHT - length);
	setPosition(SCREENWIDTH/2 - width, SCREENHEIGHT/2 - length);
	setFillColor(sf::Color::White);
	bLength = length;
	bWidth = width;
	//speedX = (rand() % 5) / 5.0f;
	//speedY = (rand() % 5) / 5.0f;
	speedX = 0.5;
	speedY = 0;
}

bool Ball::isCollision(double ballDirection, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision)
{
	// if the ball is heading towards right paddle
	if (ballDirection > 0)
	{
		paddleCollision = p1;
	}
	else if (ballDirection < 0)
	{
		paddleCollision = p2;
	}
	if (getGlobalBounds().intersects(paddleCollision.getGlobalBounds()))
	{
		return true;
	}
	return false;
}
void Ball::update(double dT, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision)
{
	// if collision with paddle, reverse X direction
	if (isCollision(speedX, p1, p2, paddleCollision))
	{
		double ballCenter = getPosition().y / 2;
		double paddleCenter = paddleCollision.getPosition().y / 2;
//		double degrees = 0.7;
		// if the ball is higher than center of paddle, bounce = -x, -y
		if (ballCenter < paddleCenter)
		{
			speedX = -speedX;
			double offSet = (paddleCenter - ballCenter)/100;
			speedY = (offSet);
		}
		// if the ball is lower than the center of paddle, bounce = -x, +y
		else if (ballCenter > paddleCenter)
		{
			speedX = -speedX;
			double offSet = (ballCenter - paddleCenter)/100;
			speedY = (offSet);
		}
		else if (ballCenter == paddleCenter)
		{
			speedX = -speedX;
		}
	}
	// if the ball is at the top or bottom of the screen, reverse Y direction ("bounce" off)
	if (getPosition().y <= 0 || getPosition().y >= SCREENHEIGHT - bLength)
	{
		speedY = -speedY;
	}
	// if the ball touches the sides, a point is scored
	if (getPosition().x <= 0 || getPosition().x >= SCREENWIDTH - bWidth)
	{
		setPosition(SCREENWIDTH / 2, SCREENHEIGHT / 2);
		speedX = 0.5;
		speedY = 0;
	}
	Ball::move(speedX * dT, speedY * dT);
} 
