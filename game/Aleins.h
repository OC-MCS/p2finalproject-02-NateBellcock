#pragma once
#include <iostream>
#include <list>	
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Projectle.h"

class Alein
{
private:
	Sprite aline;
	bool alineIsMovingRight;
public:
	Alein(Texture &aleinTexture, float x, float y)
	{
		aline.setTexture(aleinTexture);
		aline.setPosition(x, y);
		alineIsMovingRight = true;
	}

	void move()
	{
		if (!alineIsMovingRight)
		{
			if (aline.getPosition().x > 10)
			{
				aline.move(0, 50);
			}
			else
			{
				alineIsMovingRight = true;
				aline.move(6, 0);
			}
		}
		else
		{
			if (aline.getPosition().x < 760)
			{
				aline.move(0, 50);
			}
			else
			{
				alineIsMovingRight = false;
				aline.move(-6, 0);
			}
		}
		
	}

	void draw(RenderWindow &win)
	{
		win.draw(aline);
	}

	Sprite getAline()
	{
		return aline;
	}

};

class Squadron
{
private:
	list<Alein> squad;
	list <Alein> ::iterator iter;
public:
	Squadron(Texture &aleinTextrue)
	{
		for (int i = 0; i < 10; i++)
		{
			Alein newAlein(aleinTextrue, 75.0f * (i) + 30, 50.0f);
			squad.push_back(newAlein);
		}
	}

	void move()
	{
		if (!squad.empty())
		{
			for (iter = squad.begin(); iter != squad.end(); iter++)
			{
				iter->move();
			}
		}
	}

	void draw(RenderWindow &win)
	{
		if (!squad.empty())
		{
			for (iter = squad.begin(); iter != squad.end(); iter++)
			{
				iter->draw(win);
			}
		}
	}

	void checkForHit(Missiles &missiles)
	{
		if (!squad.empty())
		{
			for (iter = squad.begin(); iter != squad.end(); )
			{
   				if (missiles.hitOrMiss(iter->getAline()))
				{
 					iter = squad.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
	}
	
	~Squadron()
	{
		while (!squad.empty())
		{
			squad.pop_front();
		}
	}
};