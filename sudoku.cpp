
#include "sudoku.h"

char const SPACE = ' '; 

/*============================================================================
empty constructor
=============================================================================*/
sudoku:: sudoku() {}
/*============================================================================
initializes the gameBoard
=============================================================================*/
void sudoku:: setBoard (string boardInput)
{
	vector<int> row; 
	 for (int i = 0 ; i < boardInput.length() ; i++)
	 {
	 		if (boardInput[i] == SPACE)
	 		{
	 			continue; 
	 		}
	 		else 
	 		{
	 			row.push_back(boardInput[i] - '0');
	 			if ( (row.size() % 9 ) == 0)
	 			{
	 				board.push_back(row); 
	 				row.clear(); 
	 			}
	 		}
	 }
}
/*============================================================================
prints the game board
=============================================================================*/
void sudoku:: printBoard()
{
	vector<int> row; 
	for (int i = 0 ; i < board.size(); i++)
	{
		row = board[i]; 
		for (int j = 0 ; j < row.size(); j++ )
		{
			cout << board[i][j] << " "; 
		}
		cout << endl; 
	}
}
/*============================================================================
 finds the next empty position in the board
=============================================================================*/
void sudoku:: findEmptyPos()
{
	emptyPos.x = -1; 
	emptyPos.y = -1; 
	
	vector <int> row; 
	for (int i = 0 ; i < board.size() ; i++)
	{
		row = board[i]; 
		for (int j = 0 ; j < row.size() ; j++)
		{
			if (board[i][j] == 0)
			{
				emptyPos.x = i; 
				emptyPos.y = j; 
				return; 
			}
		}
	}
}
/*============================================================================
 gets the object's empty position
=============================================================================*/
point sudoku:: getEmptyPos()
{
	return (emptyPos); 
}
/*============================================================================
determines if the new entry follows the row constraint
=============================================================================*/
bool sudoku:: isValidRow(int number,point pos)
{
	for (int j = 0; j < 9; j++)
	{
		if (board[pos.x][j] == number && j != pos.y)
		{
			return (false); 
		}
	}
	return (true);
}
/*============================================================================
determines if the new entry follows the column constraint
=============================================================================*/
bool sudoku:: isValidCol(int number, point pos)
{ 
	for (int i = 0 ; i < 9 ; i++)
	{
		if (board[i][pos.y] == number && i != pos.x)
		{
			return (false);
		}
	}
	return (true); 
}
/*============================================================================
determines if the new entry follows the 3X3 constraint
=============================================================================*/
bool sudoku:: isValidSquare(int number, point pos)
{ 
	int squareX = pos.x / 3;
	int squareY = pos.y / 3;
	
	for (int i = (squareX * 3); i < ((squareX * 3) + 3); i++)
	{
		for (int j = (squareY * 3) ; j < ((squareY * 3) + 3) ; j++)
		{
			if (board[i][j] == number && (i != pos.x && j != pos.y))
					{
						return (false);
					}
		}
	}
	return (true); 
}
/*============================================================================
changes the object's gameboard if all constraints are followed
=============================================================================*/
void sudoku:: updateBoard(int number,point pos)
{
	board[pos.x][pos.y] = number; 
}