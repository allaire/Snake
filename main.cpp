/*
 *  main.cpp
 *  snake
 *
 *  Created by Mathieu Allaire on 11-01-23.
 *  Copyright 2011 mathieuallaire.ca. All rights reserved.
 *
 */

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "block.h"
#include "snake.h"
#include "fruit.h"

using namespace std;

int main()
{
	// Window
	sf::RenderWindow app(sf::VideoMode(750, 625), "Snake 1.0 par Mathieu Allaire", sf::Style::Close);
	app.SetFramerateLimit(12);
	
	// The snake himself
	Snake snake(app);
	
	// All the blocks that build up the snake
	list<Block> blocks;
	list<Block>::iterator it;
	
	// Direction of the snake
	enum direction { UP, RIGHT, DOWN, LEFT };
	int direction = RIGHT;
	
	// The fruit himself
	Fruit fruit(app);
	
	// Tells if we need to respawn a fruit
	bool mustSpawnFruit = true;
	
	// Coords of the fruit
	int fruitX;
	int fruitY;
	
	while(app.IsOpened())
	{
		app.Clear();
		
		/**
		 * Process events
		 **/
		
		sf::Event Event;
		
		while (app.GetEvent(Event))
		{
			if(Event.Type == sf::Event::Closed)
			{
				app.Close();
			}
			
			// Determine the direction of the snake
			if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right))
			{
				direction = RIGHT;
			}
			else if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left))
			{
				direction = LEFT;
			}
			else if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Up))
			{
				direction = UP;
			}
			else if((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Down))
			{
				direction = DOWN;
			}
		}
		
		/**
		 * Spawn a fruit if necessary
		 **/
		
		if(mustSpawnFruit)
		{
			bool safe = true;
			
			// We make sure that it doesn't spawn on the snake
			do
			{
				fruitX = (rand() % 30) * 25;
				fruitY = (rand() % 25) * 25;
				
				blocks = snake.getBlocks();
				
				for(it = blocks.begin(); it != blocks.end(); it++)
				{
					if(it->getX() == fruitX && it->getY() == fruitY)
					{
						safe = false;
						break;
					}
					else 
					{
						safe = true;
					}
				}
			} while(safe != true);
			
			mustSpawnFruit = false;
		}
		
		fruit.spawn(fruitX, fruitY);
		
		snake.move(direction);
		snake.draw();
		
		/**
		 * Detects if the snake hits the bounds of the board
		 **/
		
		if(snake.getX() >= 750 || snake.getX() < 0 || snake.getY() >= 625 || snake.getY() < 0)
		{
			app.Close();
		}
		
		/**
		 * Detects if the snake hits a fruit
		 **/
		
		if(snake.getX() == fruit.getX() && snake.getY() == fruit.getY())
		{
			mustSpawnFruit = true;
			
			snake.grow();
		}

		/**
		 * Detects if the snake hits himself
		 **/
		
		blocks = snake.getBlocks();
		it = blocks.begin();
		
		it++; // Since we know the last inserted block is the same position as the snake's head, we skip it
		
		for(it; it != blocks.end(); it++)
		{
			if(it->getX() == snake.getX() && it->getY() == snake.getY())
			{
				app.Close();
			}
		}

		
		app.Display();
	}
	
	return EXIT_SUCCESS;
}