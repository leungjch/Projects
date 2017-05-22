#include <SFML/Graphics.hpp>
#ifndef BALL_H
#define BALL_H
#include "playerpaddle.h"
class PlayerPaddle;
extern const int SCREENWIDTH;
extern const int SCREENHEIGHT;
class Ball : public sf::RectangleShape
{
public:
	Ball(int length, int width);
	bool isCollision(double ballDirection, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision);
	void update(double dT, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision, std::vector<int>& pts);
	int bLength;
	int bHeight;
	double speedX;
	double speedY;

};
#endif