/*
 * maze.h
 *
 *  Created on: 14 Feb 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <string>
#include <array>
#include <iostream>

const int size = 12;

struct Coordinate
{
	int x;
	int y;
};

/*enum Directions
{
	N,
	E,
	S,
	W
};*/

class Maze
{
public:
	Maze(std::string name);

	void printMaze();
	void mazeFindEntrance();
	void walkOn();				// walk in facing direction
	void orientate();			// face specified direction
	void mazeTraverse();		// walk through maze by right-hand-on-wall algorithm

private:
    std::array<std::array<char, size>, size> map;
    Coordinate entrance;
    Coordinate traverser;
//    Directions direction;
    int direction;				// North: 0, East: 1, South: 2, West: 3
    Coordinate hand;			// tile to your right
    Coordinate ahead;			// tile in front
};

