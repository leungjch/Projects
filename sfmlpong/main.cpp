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

	PlayerPaddle p1(20, 100, SCREENWIDTH - 20, SCREENHEIGHT / 2, 1);
	PlayerPaddle p2(20, 100, 0, SCREENHEIGHT / 2, 2);
	Ball ball(15, 15);

	sf::Clock clock;
	sf::Time currentTime;

	PlayerPaddle paddleCollision;

	std::vector<int> pts{ 0,0 };
	sf::Text p2score;
	sf::Text p1score;
	p2score.setPosition(SCREENWIDTH/4, 90);
	p2score.setCharacterSize(72);
	p2score.setFont(font);
	p1score.setPosition(SCREENWIDTH / 2 + SCREENWIDTH / 4, 90);
	p1score.setCharacterSize(72);
	p1score.setFont(font);

	double dT = clock.getElapsedTime().asMilliseconds();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
		p1.update(dT, ball);
		p2.update(dT, ball);
		ball.update(dT, p1, p2, paddleCollision, pts);

        window.clear();
		window.draw(p1);
		window.draw(p2);
		window.draw(ball);

		p2score.setString(std::to_string(pts[0]));
		p1score.setString(std::to_string(pts[1]));
		window.draw(p2score);
		window.draw(p1score);
        window.display();
		dT = clock.restart().asMilliseconds();
    }

    return 0;
}