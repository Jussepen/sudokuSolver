#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "point.h"

using namespace std; 

class sudoku 
{
	private:
	
		point emptyPos; 
		vector<vector<int>> board;
		
	public:
	
		sudoku(); 
		
		void setBoard(string);
		void updateBoard(int,point); 
		void printBoard(); 
		
		void findEmptyPos();
		point getEmptyPos(); 
		
		bool isValidRow(int, point); 
		bool isValidCol(int, point);
		bool isValidSquare(int, point); 
		
		
};