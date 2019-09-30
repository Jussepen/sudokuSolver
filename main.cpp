#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "sudoku.h"

using namespace std; 

int const ROW = 9; 

string getNumericalList (); 
bool solveBoard(sudoku &); 

int main()
{	
  	string boardInput = getNumericalList (); 
  	
  	sudoku startBoard;
  	startBoard.setBoard(boardInput); 
		
		cout << endl; 
		if (solveBoard(startBoard))
		{
			cout << "the solution is:" << endl; 
		}
		cout << endl; 
		
		startBoard.printBoard();
  	
}
/*===========================================================================
gets the user's entry board
=============================================================================*/
string getNumericalList ()
{
	string rowInput;
	string boardInput; 
	
	cout << "enter the initial board below: " << endl; 
	for (int i = 0 ; i < ROW  ; i++ )
	{
			getline(cin,rowInput); 
			boardInput+= rowInput; 
	}
	
	return (boardInput); 
}
/*===========================================================================
solves the Sudoku gameboard using backtracking
=============================================================================*/
bool solveBoard(sudoku &game)
{
	
	game.findEmptyPos();
	point pos; 
	// if there are no more empty spots the program return true
	if (game.getEmptyPos().x == -1 && game.getEmptyPos().y == -1)
	{
		return (true); 
	}
	else
	{
		pos = game.getEmptyPos();
	}
	
	// domain of the values 
	for (int i = 1; i < 10 ; i++)
	{
		// constraints 
		if (game.isValidRow(i,pos) && 
				game.isValidCol(i, pos) && 
				game.isValidSquare(i, pos))
		{
			game.updateBoard(i,pos);
			
			// recursive call 
			if (solveBoard(game))
			{
				return (true);
			}
		}
		
		// if it does not follow the contraints then
		// the we reset that position to empy
		game.updateBoard(0,pos); 
				
	}
	// triggers backtracking 
	return (false); 

}