#include "ball.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Ball::Ball(int length, int width)
{
	setSize((sf::Vector2f(length, width)));
	std::srand(std::time(0));
	//setPosition(rand() % SCREENWIDTH - width, rand() % SCREENHEIGHT - length);
	setPosition(SCREENWIDTH/2 - width, SCREENHEIGHT/2 - length);
	setFillColor(sf::Color::White);
	bLength = length;
	bHeight = width;
	//speedX = (rand() % 5) / 5.0f;
	//speedY = (rand() % 5) / 5.0f;
	speedX = 0.5;
	speedY = 0.01;
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
void Ball::update(double dT, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision, std::vector<int>& pts)
{
	// if collision with paddle, reverse X direction
	if (isCollision(speedX, p1, p2, paddleCollision))
	{
		double ballCenter = getPosition().y + bHeight/2;
		double paddleCenter =  paddleCollision.getPosition().y + paddleCollision.getSize().y/2;
//		double degrees = 0.7;
		// if the ball is higher than center of paddle, bounce = -x, -y
		if (ballCenter < paddleCenter)
		{
			speedX = -speedX*1.05;
			double offSet = (paddleCenter - ballCenter);
			// if ball was coming from downwards
			if (speedY < 0)
			{
				speedY = -(offSet) / 100;
			}
			// if ball was coming from upwards
			if (speedY > 0)
			{
				speedY = (offSet) / 100;
			}
			std::cout << speedY << std::endl;
		}
		// if the ball is lower than the center of paddle, bounce = -x, +y
		else if (ballCenter > paddleCenter)
		{
			speedX = -speedX*1.05;
			double offSet = (ballCenter - paddleCenter);
			// if ball was coming from downwards
			if (speedY < 0)
			{
				speedY = -(offSet) / 100;
			}
			// if ball was coming from upwards
			if (speedY > 0)
			{
				speedY = (offSet) / 100;
			}
			std::cout << speedY << std::endl;
		}
		else if (ballCenter == paddleCenter)
		{
			speedX = -speedX*1.05;
		}
	}
	// if the ball is at the top or bottom of the screen, reverse Y direction ("bounce" off)
	if (getPosition().y <= 0 || getPosition().y >= SCREENHEIGHT - bLength)
	{
		speedY = -speedY;
	}
	// if the ball touches the sides, a point is scored
	if (getPosition().x <= 0 || getPosition().x >= SCREENWIDTH - bHeight)
	{
		// if ball was on ----> side
		if (speedX > 0)
		{
			pts[0]++;
		}
		// if ball was on <---- side
		else if (speedX < 0)
		{
			pts[1]++;
		}
		setPosition(SCREENWIDTH / 2, SCREENHEIGHT / 2);
		speedX = 0.5;
		speedY = 0.01;
	}
	Ball::move(speedX * dT, speedY * dT);
} 
