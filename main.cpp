#include <SFML/Graphics.hpp>

int main()
{
    //variables
    int scoreL = 0, scoreR = 0;

    //ball variables
    double xpos = 390, ypos = 290, xspeed = 5, yspeed = 5;

    //paddle variables
    double rPosY = 240, lPosY = 240;

    //window
    sf::RenderWindow window(sf::VideoMode(1200, 700), "PONG");

    //loading
    sf::Texture paddleRTexture;
    paddleRTexture.loadFromFile("Keyblade.png");

    sf::Sprite paddleR;
    paddleR.setTexture(paddleRTexture);
    paddleR.scale(0.4, 0.4);
    paddleR.setPosition(1080, rPosY);

    sf::Texture paddleLTexture;
    paddleLTexture.loadFromFile("Oathkeeper.png");

    sf::Sprite paddleL;
    paddleL.setTexture(paddleLTexture);
    paddleL.scale(1.2, 1.2);
    paddleL.setPosition(80, lPosY);

    sf::Texture ballTexture;
    ballTexture.loadFromFile("ball.png");

    sf::Sprite ball;
    ball.setTexture(ballTexture);
    ball.scale(0.08, 0.08);
    ball.setPosition(xpos, ypos);

    sf::Font font;
    font.loadFromFile("Kingdom_Hearts_Font.ttf");

    sf::Text scoreP1;
    scoreP1.setFont(font);
    scoreP1.setString(std::to_string(scoreL));
    scoreP1.setCharacterSize(100);
    scoreP1.setPosition(480, 0);

    sf::Text scoreP2;
    scoreP2.setFont(font);
    scoreP2.setString(std::to_string(scoreR));
    scoreP2.setCharacterSize(100);
    scoreP2.setPosition(700, 0);

    //game loop
    while (window.isOpen())
    {

        //listening for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                rPosY += 10;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                rPosY -= 10;

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

                lPosY -= 10;

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){

                lPosY += 10;

            }

        }


        //logic

        //paddle movement

        if(rPosY < 0) {

            rPosY = 0;

        }

        if(rPosY >= 420){

            rPosY = 420;

        }

        paddleR.setPosition(1080, rPosY);

        if(lPosY < 0) {

            lPosY = 0;

        }

        if(lPosY >= 420){

            lPosY = 420;

        }

        paddleL.setPosition(80, lPosY);

        //ball movement

        xpos += xspeed;

        if (xpos >= 1160){

            xpos = 200;
            xspeed = xspeed * 1;
            scoreL += 1;

        }

        scoreP1.setString(std::to_string(scoreL));

        if (xpos < 0){

            xpos = 1000;
            xspeed = xspeed * 1;
            scoreR += 1;

        }

        scoreP2.setString(std::to_string(scoreR));

        ypos += yspeed;

        if (ypos > 660 || ypos < 0){

            yspeed = yspeed * -1;

        }

        ball.setPosition(xpos, ypos);

        //collision detection
        if (ball.getGlobalBounds().intersects(paddleR.getGlobalBounds())){

            xspeed *= -1;
            xpos -= 20;

        }

        if (ball.getGlobalBounds().intersects(paddleL.getGlobalBounds())){

            xspeed *= -1;
            xpos += 20;

        }

        //render
        window.clear();
        window.draw(paddleR);
        window.draw(paddleL);
        window.draw(ball);
        window.draw(scoreP1);
        window.draw(scoreP2);
        window.display();
    }

    return 0;
}
