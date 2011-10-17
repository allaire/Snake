/*
 *  block.h
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#ifndef _BBLOCK_
#define _BLOCK_

using namespace std;

class Block
{
private:
	int _x;
	int _y;
public:
	Block(int, int);
	int getX();
	int getY();
};

#endif