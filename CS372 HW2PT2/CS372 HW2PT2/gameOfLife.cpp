//Jacob Jakiemiec
//gameOfLife.cpp

#include <string>
using std::string;
#include <regex>
using std::regex;

//gameOfLife
//takes in a string which is a 3x3 of either X's or O's
//example:
//	OXO
//	OOO
//	OOO
string gameOfLife(string board) {

	/*bool format = true;
	for (int i = 0; i < board.size(); i++) {
		if ((i - 1) % 4 == 0) {
			if (board[i] != '\n') {
				format = false;
			}
		}
		else
			if (!(board[i] == 'O' || board[i] == 'X'))
				format = false;


	}
	if (board == "")
		format = false;

	if (!format)
		return "ERROR: incorrect board format";*/
	regex format("[OX][OX][OX]\n[OX][OX][OX]\n[OX][OX][OX]");
	if (!std::regex_match(board, format))
		return "ERROR: incorrect board format";
	return "";
}