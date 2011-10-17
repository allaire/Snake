/*
 *  fruit.cpp
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-24.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>

#include "fruit.h"

using namespace std;

Fruit::Fruit(sf::RenderWindow &App)
{
	_app = &App;
}

void Fruit::spawn(float x, float y)
{
	sf::Shape block = sf::Shape::Rectangle(0, 0, 20, 20, sf::Color::Green);
	block.Move(x, y);
	
	_x = x;
	_y = y;
	
	_app->Draw(block);
}

float Fruit::getX()
{
	return _x;
}

float Fruit::getY()
{
	return _y;
}