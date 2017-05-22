#include "SFML/Graphics.hpp"
#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H
#include "ball.h"
class Ball;
extern const int SCREENHEIGHT;
extern const int SCREENHEIGHT;
class PlayerPaddle : public sf::RectangleShape
{
public :
	PlayerPaddle();
	PlayerPaddle(int length, int width, int posX, int posY, int player);
	void update(double dt, Ball ball);
	sf::Keyboard::Key keyUp;
	sf::Keyboard::Key keyDown;
	int pWidth;
	int pHeight;
	bool isAI;
};
#endif