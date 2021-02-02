//Jacob Jakiemiec
//gameOfLife.cpp

#include <string>
using std::string;
#include <regex>
using std::regex;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;


//count how many neighbors are the specified index are the specified character
int neighborCount(const vector<vector<char>> & board, int row, int col, char c) {
	int count = 0;
	if (board[row + 1][col] == 'O')
		count++;
	if (board[row - 1][col] == 'O')
		count++;
	if (board[row][col + 1] == 'O')
		count++;
	if (board[row][col - 1] == 'O')
		count++;
	return count;
}

//print the board
//used for testing
void printboard(const vector<vector<char>>& board) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}


//gameOfLife
//takes in a string which is a 3x3 of either X's or O's
//example:
//	OXO
//	OOO
//	OOO
//
//	O represents a living cell
//	X represents a dead cell
//
//returns the string after one round of the life game
//	a cell dies if it has less than 2 neighbors or if it has 4 neighbors
//	a cell becomes alive if it has exactly 3 neighbors
string gameOfLife(string board) {
	//check to see if the board is formatted correctly
	regex format("[OX][OX][OX]\n[OX][OX][OX]\n[OX][OX][OX]");
	regex newline("\n");
	if (!std::regex_match(board, format))
		return "ERROR: incorrect board format";


	//convert board into a more usable 2-d vector
	//the board will be 5x5 to make boundary searching easier
	//N (neutral) will be the boundary
	board = board.substr(0, 3) + board.substr(4, 3) + board.substr(8, 3);
	vector<vector<char>> boardArray(5, vector<char> (5, 'N'));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			boardArray[i+1][j+1] = board[i * 3 + j];
		}
	}
	vector<vector<char>> boardArrayCopy = boardArray;


	//do the checks to see what happens to each cell
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			int alive = neighborCount(boardArray, i, j, 'O');
			if (alive < 2 || alive == 4)
				boardArrayCopy[i][j] = 'X';

			int dead = neighborCount(boardArray, i, j, 'X');
			if (dead == 3)
				boardArrayCopy[i][j] = 'O';
		}
	}


	//convert the 2-d vector back into a string
	string output = "";
	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			output += boardArrayCopy[i][j];
		}
		output += '\n';
	}
	output.pop_back();

	return output;
}