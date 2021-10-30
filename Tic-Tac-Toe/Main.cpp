#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame();
void initializeGame(string gameBoard[ROWS][COLS]);
void printCurrentBoard(string gameBoard[ROWS][COLS]);
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);
bool cellIsAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);
string getWinner(string gameBoard[ROWS][COLS]);
bool isBoardFull(string gameBoard[ROWS][COLS]);

int main() 
{
	runGame();

	return 0;
}


void runGame()
{
	string winner = "";
	bool xTurn = true;
	int theRow = 0;
	int theCol = 0;
	string gameBoard[ROWS][COLS];

	initializeGame(gameBoard);

	printCurrentBoard(gameBoard);

	while (winner == "")
	{
		if (xTurn)
		{
			cout << "It is X turn" << endl;
		}
		else 
		{
			cout << "It is 0 turn" << endl;
		}
		getUserInput(xTurn, gameBoard);
		cout << endl;
		printCurrentBoard(gameBoard); // reprint board after move
		winner = getWinner(gameBoard); //check for winner
		xTurn = !xTurn; // flip it

		if (winner == "" && isBoardFull(gameBoard))
		{
			winner = "C"; //no winner
		}
	}
	
	cout << endl;
	if (winner == "C")
	{
		cout << ".......... No Winner ! ..........";
	}
	else 
	{
		cout << "** The winner is " << winner << " **" << endl;
	}
	cout << endl;
}


void initializeGame(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = " "; //
		}
	}
}

void printCurrentBoard(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << gameBoard[i][j]; 
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << "- - - - -" << endl;
		}
	}

	cout << endl;

}

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]) 
{
	int row = -1;
	int col = -1; 
	bool keepAsking = true;
	//Keep asking until we got a proper input
	while (keepAsking)
	{
		cout << "Please enter Row, then Col, from 0 - 2, separated by space." << endl;
		cin >> row;
		cin >> col;
		//Valid answer - does the cell is occupied ?
		if (row >= 0 && col >= 0 && row <= 2 && col <= 2)
		{
			if (!cellIsAlreadyOccupied(row, col, gameBoard))
			{
				keepAsking = false;
			}
			else 
			{
				cout << "That cell is already occupied.. try again" << endl;
			}
		}
	}

	//valid answer cell is empty
	if (xTurn)
	{
		cout << "valid move ! " << endl;
		gameBoard[row][col] = "X";
	}
	else 
	{
		cout << "valid move ! " << endl;
		gameBoard[row][col] = "O";
	}
}

bool cellIsAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]) 
{

	return gameBoard[row][col] != " "; //if it is not a space, it is occupied
}

string getWinner(string gameBoard[ROWS][COLS]) 
{
	//check winner rows
	for (int i = 0; i < ROWS; i++)
	{
		if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
		{
			return gameBoard[i][0]; // we have a horizontal match
		}
	}
	//check winner cols
	for (int i = 0; i < COLS; i++)
	{
		if (gameBoard[i][0] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
		{
			return gameBoard[0][i]; // we have a vertical match
		}
	}
	//check winner Diagnol
	//upper-left to bottom right
	if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
	{
		return gameBoard[0][0];
	}
	//lower-left to upper right
	if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
	{
		return gameBoard[2][0];
	}

	//no winner yet..
	return "";
}

bool isBoardFull(string gameBoard[ROWS][COLS]) 
{
	int countFill = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] != " ")
			{
				countFill++;
			}
		}
	}

	return countFill == 9; //board is full
}




