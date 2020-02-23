#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include<stdio.h>
//Glboal variables, functions, classes

//C++ program entry point
int main()
{
	//Creating the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "game");

	//Settign the framerate limit to 60 FPS
	window.setFramerateLimit(60);

	window.setKeyRepeatEnabled(false);

	//Variable that keeps the game loop running
	bool play = true;

	//Event object holding all events
	sf::Event event;


	bool up = false;
	bool down = false;

	//Variables
	int yVelocityPad1 = 0; //Y velocity of pad1
	int xVelocityBall = -4; //X velocity of the ball
	int yVelocityBall = -4; //Y velocity of the ball
	int yVelocityPad2 = 0; //Y velocity of pad2
	int pad1Score = 0; //Score for pad1
	int pad2Score = 0; //Score for pad2
	int level;
	int ctr = -4;

	std::cout << "choose the level" << std::endl;
	std::cout << "1)NOob" << std::endl;
	std::cout << "2)Easy" << std::endl;
	std::cout << "3)Normal" << std::endl;
	std::cout << "4)hard" << std::endl;
	std::cout << "5) Nightmare" << std::endl;
	std::cin >> level;

	if (level == 5)
	{
		window.setFramerateLimit(120);
	}

	//Pad1
	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(50, 100));
	pad1.setPosition(50, 200);

	//Pad
	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(50, 100));
	pad2.setPosition(700, 200);


	//Ball
	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(400, 200);


	//Game loop
	while (play == true)
	{
		//EVENTS
		while (window.pollEvent(event))
		{
			//Event type is window closed
			if (event.type == sf::Event::Closed)
			{
				//Set play to false in order to stop the game loop
				play = false;
			}

			//Key pressed
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				up = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				down = true;
			}

			//Key released
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
			{
				up = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
			{
				down = false;
			}
		}

		////////////LOGIC
		////Pad1
		//Check states
		if (up == true)
		{
			yVelocityPad1 = -5;
		}

		if (down == true)
		{
			yVelocityPad1 = 5;
		}

		if (up == true && down == true)
		{
			yVelocityPad1 = 0;
		}

		if (up == false && down == false)
		{
			yVelocityPad1 = 0;
		}

		//Move pad1
		pad1.move(0, yVelocityPad1);

		//Out of bounds check
		if (pad1.getPosition().y < 0)
		{
			pad1.setPosition(50, 0);
		}

		if (pad1.getPosition().y > 500)
		{
			pad1.setPosition(50, 500);
		}

		////Pad2
		//Check where the ball is and set the velocity
		if (level == 1)
		{
			if (ball.getPosition().y < pad2.getPosition().y)
			{

				yVelocityPad2 = -3;
			}

			if (ball.getPosition().y > pad2.getPosition().y)
			{
				yVelocityPad2 = 3;
			}
		}
		if (level == 2)
		{
			if (ball.getPosition().y < pad2.getPosition().y)
			{

				yVelocityPad2 = -4;
			}

			if (ball.getPosition().y > pad2.getPosition().y)
			{
				yVelocityPad2 = 4;
			}
		}
		if (level == 3)
		{
			if (ball.getPosition().y < pad2.getPosition().y)
			{
				yVelocityPad2 = -7;
			}
			if (ball.getPosition().y > pad2.getPosition().y)
			{
				yVelocityPad2 = 7;
			}
		}
		if (level == 4)
		{
			if (ball.getPosition().y < pad2.getPosition().y)
			{
				yVelocityPad2 = -9;
			}
			if (ball.getPosition().y > pad2.getPosition().y)
			{
				yVelocityPad2 = 9;
			}

		}
		if (level == 5)
		{
			if (ball.getPosition().y < pad2.getPosition().y)
			{
				yVelocityPad2 = -12;
			}
			if (ball.getPosition().y > pad2.getPosition().y)
			{
				yVelocityPad2 = 12;
			}
		}


		//Move pad2
		pad2.move(0, yVelocityPad2);

		/////Ball
		ball.move(xVelocityBall, yVelocityBall);

		//Out of bounds check
		if (ball.getPosition().y < 0)
		{
			yVelocityBall = -yVelocityBall;
		}

		if (ball.getPosition().y > 550)
		{
			yVelocityBall = -yVelocityBall;
		}

		//Left and right out of bounds check
		if (ball.getPosition().x < -50)
		{
			pad2Score++;
			ball.setPosition(300, 200); //Move the ball back to middle
		}

		if (ball.getPosition().x > 800)
		{
			pad1Score++;
			ball.setPosition(300, 200);
		}

		//Collision for pad1
		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds()) == true)
		{
			xVelocityBall = -xVelocityBall; //Invert the x velocity of ball

		}

		//Collision for pad2
		if (level == 1)
		{
			if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
			{
				xVelocityBall = -xVelocityBall;
			}
		}
		if (level == 2)
		{
			if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
			{
				if (rand() % 2 == 0)
				{
					xVelocityBall = -(xVelocityBall + 1);
				}
				else
				{
					xVelocityBall = (ctr);
				}

			}

		}
		if (level == 3)
		{
			if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
			{
				if (rand() % 3 == 0)
				{
					xVelocityBall = -(xVelocityBall + 5);
				}
				else if (rand() % 3 == 1)
				{
					xVelocityBall = -(xVelocityBall + 6);
				}
				else if (rand() % 3 == 2)
				{
					xVelocityBall = (ctr);
				}

			}

		}
		if (level == 4)
		{
			if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
			{
				if (rand() % 4 == 0)
				{
					xVelocityBall = -(xVelocityBall + 7);
				}
				else if (rand() % 4 == 1)
				{
					xVelocityBall = -(xVelocityBall + 2);
				}
				else if (rand() % 4 == 2)
				{
					xVelocityBall = -(xVelocityBall);
				}
				else
				{
					xVelocityBall = (ctr);
				}
			}
		}
		if (level == 5)
		{
			if (pad2.getGlobalBounds().intersects(ball.getGlobalBounds()) == true)
			{
				if (rand() % 5 == 0)
				{
					xVelocityBall = -(xVelocityBall + 10);
				}
				else if (rand() % 5 == 1)
				{
					xVelocityBall = -(xVelocityBall + 5);
				}
				else if (rand() % 5 == 2)
				{
					xVelocityBall = -(xVelocityBall + 3);
				}
				else if (rand() % 5 == 3)
				{
					xVelocityBall = -(xVelocityBall + 2);
				}
				else
				{
					xVelocityBall = -xVelocityBall;
				}


			}
		}
		//RENDERING
		window.clear();

		//Drawing the shapes

		window.draw(pad1);
		window.draw(pad2);
		window.draw(ball);
		if (pad2Score == 4)
		{
			char a;
			std::cout << "computer has w0n the game";
			play = false;

		}
		if (pad1Score == 4)
		{
			char a;
			std::cout << "computer has w0n the game";
			play = false;

		}




		window.display();
	}
	///////////

	//Clean up and close the window
	window.close();

	//Close the program
	return 0;
}

