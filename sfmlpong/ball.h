#include <SFML/Graphics.hpp>
#include "playerpaddle.h"
extern const int SCREENWIDTH;
extern const int SCREENHEIGHT;
class Ball : public sf::RectangleShape
{
public:
	Ball(int length, int width);
	bool isCollision(double ballDirection, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision);
	void update(double dT, PlayerPaddle p1, PlayerPaddle p2, PlayerPaddle& paddleCollision);
	void speedReset();
	int bLength;
	int bWidth;
	double speedX;
	double speedY;
};