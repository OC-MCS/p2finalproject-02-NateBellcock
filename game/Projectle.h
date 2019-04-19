#pragma once
#include <iostream>
#include <list>	
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Projectle
{
private:
	Sprite missile;
	bool isOnSreen;
public:
	Projectle(Texture& missileTexture, Sprite ship)
	{
		missile.setTexture(missileTexture);
		missile.setPosition(ship.getPosition().x + 8, ship.getPosition().y - 5);
		isOnSreen = true;
	}

	void move()
	{
		missile.move(0, -6);
		if (missile.getPosition().y < 0)
		{
			isOnSreen = false;
		}
	}

	void draw(RenderWindow &win)
	{
		win.draw(missile);
	}

	bool getIsOnSreen()
	{
		return isOnSreen;
	}

	Sprite getProjtle()
	{
		return missile;
	}
};

class Missiles
{
private:
	list<Projectle> missiles;
	list<Projectle>::iterator iter;
public:
	Missiles()
	{

	}

	void addMissile(Projectle &missile)
	{
		missiles.push_back(missile);
	}

	void move()
	{
		if (!missiles.empty())
		{
			for (iter = missiles.begin(); iter != missiles.end(); iter++)
			{
				iter->move();
			}
		}
	}

	void draw(RenderWindow &win)
	{
		if (!missiles.empty())
		{
			for (iter = missiles.begin(); iter != missiles.end(); iter++)
			{
				iter->draw(win);
			}
		}
	}

	void removeMissiles()
 	{
		if (!missiles.empty())
		{
			for (iter = missiles.begin(); iter != missiles.end();)
			{
				if (!iter->getIsOnSreen())
				{
					iter = missiles.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}
	}

	bool hitOrMiss(Sprite target)
	{
		bool hit = false;
		if (!missiles.empty())
		{
			for (iter = missiles.begin(); iter != missiles.end() && !hit;)
			{
				if (!iter->getProjtle().getGlobalBounds().intersects(target.getGlobalBounds()))
				{
					iter = missiles.erase(iter);
					hit = true;
				}
				else
				{
					iter++;
				}
			}
		}
		return hit;
	}
	~Missiles()
	{
		while (!missiles.empty())
		{
			missiles.pop_front();
		}
	}
};