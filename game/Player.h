#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	int lifes, scoer;
	Sprite ship;
public:
	Player(Texture &shipTexture, RenderWindow &win )
	{
		ship.setTexture(shipTexture);


		// initial position of the ship will be approx middle of screen
		float shipX = win.getSize().x / 2.0f;
		float shipY = win.getSize().y - 50.0f;
		ship.setPosition(shipX, shipY);
		lifes = 3;
		scoer = 0;
	}

	void moveShip()
	{
		const float DISTANCE = 5.0;

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			// left arrow is pressed: move our ship left 5 pixels
			// 2nd parm is y direction. We don't want to move up/down, so it's zero.
			if (ship.getPosition().x > 5)
			{
				ship.move(-DISTANCE, 0);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			// right arrow is pressed: move our ship right 5 pixels
			if (ship.getPosition().x < 775)
			{
				ship.move(DISTANCE, 0);
			}
		}
	}

	void setScoer(int pontes)
	{
		scoer += pontes;
	}

	void loseALife()
	{
		lifes--;
	}

	int getScoer()
	{
		return scoer;
	}

	int getLifes()
	{
		return lifes;
	}

	bool isAlive()
	{
		return lifes > 0;
	}

	void draw(RenderWindow &win)
	{
		win.draw(ship);
	}

	Sprite getShip()
	{
		return ship;
	}
};