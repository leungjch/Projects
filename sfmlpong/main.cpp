#include <SFML/Graphics.hpp>
#include "playerpaddle.h"
#include "ball.h"
//https://en.sfml-dev.org/forums/index.php?topic=9738.0
const int SCREENWIDTH = 640;
const int SCREENHEIGHT = 480;
int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREENWIDTH,SCREENHEIGHT), "Pong");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::Font font;
	if (!font.loadFromFile("Munro.ttf"))
	{
		return 1;
	}
	sf::Text p1scoreI, p2scoreI;
	p1scoreI.setFont(font);
	p2scoreI.setFont(font);
	//p1scoreI.setString(str();

	PlayerPaddle p1(20, 100, SCREENWIDTH - 20, SCREENHEIGHT / 2, 1);
	PlayerPaddle p2(20, 100, 0, SCREENHEIGHT / 2, 2);
	Ball ball(15, 15);

	sf::Clock clock;
	sf::Time currentTime;

	PlayerPaddle paddleCollision;
	double dT = clock.getElapsedTime().asMilliseconds();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
		p1.update(dT);
		p2.update(dT);
		ball.update(dT, p1, p2, paddleCollision);
        window.clear();
		window.draw(p1);
		window.draw(p2);
		window.draw(ball);
		//window.draw(p1Pts);
		//window.draw(p2Pts);
        window.display();
		dT = clock.restart().asMilliseconds();
    }

    return 0;
}