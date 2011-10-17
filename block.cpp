/*
 *  block.cpp
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#include "block.h"

using namespace std;

Block::Block(int x, int y)
{
	_x = x;
	_y = y;
}

int Block::getX()
{
	return _x;
}

int Block::getY()
{
	return _y;
}