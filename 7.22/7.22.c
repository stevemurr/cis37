#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define ROWS 13
#define COLUMNS 13
#define TIME_TO_SLEEP 1

int main(void)
{
	
	void mazeTraverse( char maze[ROWS][COLUMNS], int starting_row, int starting_location );
	char maze[ROWS][COLUMNS] = {
		{'#','#','#','#','#','#','#','#','#','#','#','#'}, 
		{'#','.','.','.','#','.','.','.','.','.','.','#'},
		{'.','.','#','.','#','.','#','#','#','#','.','#'},
		{'#','#','#','.','#','.','.','.','.','#','.','#'},
		{'#','.','.','.','.','#','#','#','.','#','.','.'},
		{'#','#','#','#','.','#','.','#','.','#','.','#'},
		{'#','#','.','#','.','#','.','#','.','#','.','#'},
		{'#','.','.','.','.','.','.','.','.','#','.','#'},
		{'#','#','#','#','#','#','.','#','#','#','.','#'},
		{'#','.','.','.','.','.','.','#','.','.','.','#'},
		{'#','#','#','#','#','#','#','#','#','#','#','#'}
	};
	
	mazeTraverse(maze, 2, 0);
}

void mazeTraverse( char maze[ROWS][COLUMNS], int starting_row, int starting_location)
{
	void printMap( char maze[ROWS][COLUMNS]);
	int row = starting_row;
	int dot = starting_location;
	bool running = true;
	while (running) {
		printMap(maze);
		if ( maze[row][dot + 1] == '.' ) { // look to the right
			maze[row][dot] = 'X';
			dot = dot + 1;
		} else if ( maze[row + 1][dot] == '.' ) { // look down
			maze[row][dot] = 'X';
			row = row + 1;
		} else if ( maze[row - 1][dot] == '.' ) { // look up
			maze[row][dot] = 'X';
			row = row - 1;
		} else if ( maze[row][dot - 1] == '.' ) {
			maze[row][dot] = 'X';
			dot = dot - 1;
		}
		//printf("%d, %d\n", row, dot); // for debugging
		if (row == 4 && dot == 11) {
			maze[row][dot] = 'X';
			printMap(maze);
			break;
		}
		sleep(TIME_TO_SLEEP);
	}
	// 
}

void printMap( char maze[ROWS][COLUMNS]) 
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			printf("%c ", maze[i][j]);
			if (j == (COLUMNS - 1)) {
				printf("\n");
			}
		}
	}
}

