/*
 *  fruit.h
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-24.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#ifndef _FRUIT_
#define _FRUIT_

using namespace std;

class Fruit
{
private:
	sf::RenderWindow *_app;
	float _x;
	float _y;
public:
	Fruit(sf::RenderWindow&);

	void spawn(float, float);
	
	float getX();
	float getY();
};

#endif