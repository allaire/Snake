/*
 *  snake.h
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#ifndef _SNAKE_
#define _SNAKE_

#include <list>

using namespace std;

class Block;

class Snake
{
private:
	list<Block> _snake;
	sf::RenderWindow *_app;
	enum direction { UP, RIGHT, DOWN, LEFT };
	int _direction;
	
public:
	Snake(sf::RenderWindow&);

	void move(int);
	void draw();
	
	void grow();
	void shrink();
	
	list<Block> getBlocks();
	
	int getX();
	int getY();
};

#endif