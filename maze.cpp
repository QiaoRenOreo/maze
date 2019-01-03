/*
 * maze.cpp
 *
 *  Created on: 14 Feb 2017
 *      Author: Alexander Green, Qiao Ren
 *		 Group: 15
 */

#include <maze.h>

Maze::Maze(std::string name)
{
	direction = 3;
	map = {{
    		{'#','#','#','#','#','#','#','#','#','#','#','#'},
			{'#','.','.','.','#','.','.','.','.','.','.','#'},
			{'.','.','#','.','#','.','#','#','#','#','.','#'},
			{'#','#','#','.','#','.','.','.','.','#','.','#'},
			{'#','.','.','.','.','#','#','#','.','#','.','x'},
			{'#','#','#','#','.','#','.','#','.','#','.','#'},
			{'#','.','.','#','.','#','.','#','.','#','.','#'},
			{'#','#','.','#','.','#','.','#','.','#','.','#'},
			{'#','.','.','.','.','.','.','.','.','#','.','#'},
			{'#','#','#','#','#','#','.','#','#','#','.','#'},
			{'#','.','.','.','.','.','.','#','.','.','.','#'},
			{'#','#','#','#','#','#','#','#','#','#','#','#'}
		}};
}


void Maze::printMaze()
{
	for(int row=0; row<size; row++)				// go through each row ...
	{
		for(int column=0; column<size; column++)	// ... and column ...
		{
			std::cout<<map[row][column]<<" ";	// ... and print the character.
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}


void Maze::mazeFindEntrance()	// go through each entry in the matrix until 'x'
{								// is found.

	for(int row=0; row<size; row++)
		{
			for(int column=0; column<size; column++)
			{
				if (map[row][column] == 'x')
					{
					entrance = {column+1,row};
					return;
					}
			}
		}
}


void Maze::walkOn()		// walk in the facing direction
{
	switch (direction % 4)
	{
		case 0:	// North
			traverser.y = traverser.y-1;
			break;
		case 1:	// East
			traverser.x = traverser.x+1;
			break;
		case 2:	// South
			traverser.y = traverser.y+1;
			break;
		case 3:	// West
			traverser.x = traverser.x-1;
	}
	orientate();
}

void Maze::orientate()	// face the specified direction
{
	switch (direction % 4)
	{
		case 0:	// North
			hand = traverser;
			ahead = traverser;
			hand.x = hand.x+1;
			ahead.y = ahead.y-1;
			break;
		case 1:	// East
			hand = traverser;
			ahead = traverser;
			hand.y = hand.y+1;
			ahead.x = ahead.x+1;
			break;
		case 2:	// South
			hand = traverser;
			ahead = traverser;
			hand.x = hand.x-1;
			ahead.y = ahead.y+1;
			break;
		case 3:	// West
			hand = traverser;
			ahead = traverser;
			hand.y = hand.y-1;
			ahead.x = ahead.x-1;
	}
}


void Maze::mazeTraverse()	// Walk through the maze from entrance to exit
{
	Maze::mazeFindEntrance();
	traverser =  entrance;						// start at entrance
	walkOn();									// walk into maze
	bool foundExit = false;

	while (!foundExit)
	{
		if (!(traverser.x%size) or !(traverser.y%size))	// exit is at maze perimeter
		{
			foundExit = true;
		}

		map[traverser.y][traverser.x] = 'X';	// place an X along traversed path
		Maze::printMaze();

		if (map[hand.y][hand.x] == '#')			// if still touching the wall
		{
			if (map[ahead.y][ahead.x] != '#')	// if not facing wall
			{
				walkOn();						// continue straight ahead
			}
			else
			{
				direction = direction-1;		// turn left
				orientate();
			}
		}
		else
		{
			direction++;						// turn right and walk ahead
			walkOn();
		}

	}

	std::cout<<"Found the exit!"<<std::endl;

}
