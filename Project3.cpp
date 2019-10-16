#include <iostream>
#include <cctype>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

const int COLUMN_SIZE = 6;	//constant for num of columns
enum Global{SPACE = '-', RED = '0', BLUE = 'X'};	//changes char for array
void watermark();	//declare all functions
void introRules();
void printBoard(int rows, Global gameboard[][COLUMN_SIZE]);
void initArray(int rows, Global gameboard[][COLUMN_SIZE]);
bool playerMoves_r(int rows, int& userMoves_r, Global gameboard[][COLUMN_SIZE]);
bool playerMoves_b(int rows, int& compMoves_b, Global gameboard[][COLUMN_SIZE]);

int main() {
	int tm, rules, rows, userMoves_r, compMoves_b;
	bool r = true;	//bool for red move
	bool b = true;	//bool for blue move
	bool x = true;	//bool for row input
	bool won_r = false;	//update bool to continue game
	bool won_b = false; //update bool to continue game
	srand(time(NULL));	//random

	system("cls");				//clear compiler(Windows)
  system("clear");				//clear compiler(Linix)
  
	watermark();	//call funtions for intro
	introRules();

	cout << "Enter the desired number of rows on the board: ";	//input num of rows
	cin >> rows;
	
	do {
		if (rows >= 4 && rows <= 6) {		//row is between 4 and 6
			cout << "Initializing game board. . ." << endl;
			x = false;
		}

		else {
			cout << "Invalid number of rows. Must be between 4 and 6." << endl;
			cout << endl;
	    	cout << "Enter the desired number of rows on the board: ";
	    	cin >> rows;
		}	
	} while (x);	//loop for retry
	
	Global gameboard[rows][COLUMN_SIZE];	//declare 2d array
	initArray(rows, gameboard);		// initialize the board to space
	cout << endl;
	printBoard(rows, gameboard);	//prints board
	cout << endl;

	if (won_r != true) {
		do {
			cout << "RED MOVE: Enter column to place RED disc: ";    //input for red placement
			cin >> userMoves_r;

			do {
				if (userMoves_r >= 1 && userMoves_r <= 6) {    //red input must be between 1 and 6
					r = false;
					won_r = playerMoves_r(rows, userMoves_r, gameboard);    //initialize place to red and continue
					cout << endl;
					printBoard(rows, gameboard);    //print updated board
					cout << endl;
				} else {
					cout << "Invalid move, BLUES turn." << endl;
					cout << endl;
					break;
				}
			} while (r);        //loop for retry

			if (won_r) {
				break;
			}

/*  								//for one player
		cout << "BLUE MOVE: Enter column to place BLUE disc: ";		//blues input
		compMoves_b = rand() % 6 + 1;		//random move
		cout << compMoves_b << endl;

		do {
			if (compMoves_b >= 1 && compMoves_b <= 6 ) {
				b = false;
				won_b = playerMoves_b(rows, compMoves_b, gameboard);
				cout << endl;
				printBoard(rows, gameboard);
				cout << endl;
			}
			else {
				cout << "Invalid move, REDS turn" << endl;
				cout << endl;
				break;
			}
		} while (b);

		if (won_b == true) {
			break;
		}

	} while (won_r != true && won_b != true);
*/
			//for two players
			cout << "BLUE MOVE: Enter column to place BLUE disc: ";
			cin >> compMoves_b;

			do {
				if (compMoves_b >= 1 && compMoves_b <= 6) {
					b = false;
					won_b = playerMoves_b(rows, compMoves_b, gameboard);
					cout << endl;
					printBoard(rows, gameboard);
					cout << endl;
				} else {
					cout << "Invalid move, REDS turn" << endl;
					cout << endl;
					break;
				}
			} while (b);

			if (won_b) {
				break;
			}

		} while (!won_b);
	} else {
		cout << "RED MOVE: Enter column to place RED disc: ";
		cin >> userMoves_r;
		do {
			if (userMoves_r >= 1 && userMoves_r <= 6) {    //red input must be between 1 and 6
				r = false;
				won_r = playerMoves_r(rows, userMoves_r, gameboard);    //initialize place to red and continue
				cout << endl;
				printBoard(rows, gameboard);    //print updated board
				cout << endl;
			} else {
				cout << "Invalid move, BLUES turn." << endl;
				cout << endl;
				break;
			}
		} while (r);

		cout << "BLUE MOVE: Enter column to place BLUE disc: ";
		cin >> compMoves_b;
		do {
			if (compMoves_b >= 1 && compMoves_b <= 6) {
				b = false;
				won_b = playerMoves_b(rows, compMoves_b, gameboard);
				cout << endl;
				printBoard(rows, gameboard);
				cout << endl;
			} else {
				cout << "Invalid move, REDS turn" << endl;
				cout << endl;
				break;
			}
		} while (b);

	}


	if (won_r == true) {
		cout << "RED WINS!" << endl;	//end game
		cout << endl;
		printBoard(rows, gameboard);	//print final board
	}
	else if (won_b == true) {
		cout << "BLUE WINS!" << endl;	//end game
		cout << endl;
		printBoard(rows, gameboard);	//print final gameboard
	}


return 0;
}
	
void watermark() {		
    cout << "\t+---------------------------------------------------------+" << endl;
    cout << "\t|             Computer Science and Engineering            |" << endl;
    cout << "\t|              CSCE 1030 - Computer Science I             |" << endl;
    cout << "\t|    Patrick Friedman    psf0023    psf0023@my.unt.edu    |" << endl;
    cout << "\t+---------------------------------------------------------+" << endl;
    cout << endl;
}
	
void introRules() {		
    cout << "\t       W e l c o m e   t o   1 0 3 0   C o n n e c t " << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "This program will set up a game board to play 1030 Connect using a board" << endl;
    cout << "where the rows are determined by the user to be between 4 and 6, inclusively," << endl;
    cout << "but the number of columns if fixed at 6." << endl;
    cout << endl;
    cout << "Then, the user (RED) will play against the computer (BLUE) to attempt to" << endl;
    cout << "connect four discs in a row, either horizontal or vertical, on the board." << endl;
    cout << "The user (RED) will start the game." << endl;
    cout << "---------------------------------------------------------------------------" << endl;
	cout << endl;
}

void printBoard(int rows, Global gameboard[][COLUMN_SIZE]) {	
    cout << "    1  2  3  4  5  6 " << endl;
    cout << "  +------------------+" << endl;		

    for (int i = 0; i < rows; ++i) {
		switch (i) {
			case 0:
				cout << "A |";
				break;
			case 1:
                cout << "B |";
                break;
			case 2:
                cout << "C |";
                break;
			case 3:
                cout << "D |";
                break;
			case 4:
                cout << "E |";
                break;
			case 5:
                cout << "F |";
                break;
		}

        for (int j = 0; j < COLUMN_SIZE; ++j) {	

        	if (gameboard[i][j] == RED) {
            	cout << " ";
            	printf("\033[1;31m%c\033[0m", static_cast<char>(gameboard[i][j]));
            	cout << " ";
        	}
        	else if (gameboard[i][j] == BLUE) {
            	cout << " ";
            	printf("\033[1;34m%c\033[0m", static_cast<char>(gameboard[i][j]));
            	cout << " ";
        	}

        	else if (gameboard[i][j] == SPACE) {
            	cout << " ";
            	cout << static_cast<char>(gameboard[i][j]);
            	cout << " ";
        	}

			if (j == 5) {
				if (gameboard[i][j]) {
	               	cout << "|";
				}
           	}
     	}
    	cout << "\n";
	}
	cout << "  +------------------+" << endl;
}

void initArray(int rows, Global gameboard[][COLUMN_SIZE]) {
	for (int i = 0; i < rows; ++i) {
       	for (int j = 0; j < COLUMN_SIZE; ++j) {	
            gameboard[i][j] = SPACE;
   		}
	}
}

bool playerMoves_r(int rows, int& userMoves_r, Global gameboard[][COLUMN_SIZE]) {
	rows = rows - 1;
	int redMoves = 1;
	int j = userMoves_r - 1;
	bool q = false;	
	bool x = false;
	int i;

	for (i = rows; i >= 0 ; i--) {
		switch (gameboard[i][j]) {
			case SPACE:
				q = true;
				gameboard[i][j] = RED;
				break;
			case RED:
				redMoves++;
				break;
			default:
				redMoves = 1;
				break;
		}
		if (q == true) {
			break;
		}
    }

    if (redMoves >= 4) {
    	return true;
    }

    redMoves = 1;
    if (i < 0) {
    	redMoves - 1;
    	cout << "Invalid, BLUES turn." << endl;
    }
    else {
    	for (int p = j + 1; p <= rows; p++) {
    		switch (gameboard[i][p]) {
				case RED:
					redMoves++;
					break;
				default:
					redMoves = 1;
					break;
			}
    	}

    	if (redMoves >= 4) {
    		return true;
    	}	

    	redMoves = 1;
    	for (int p = j - 1; p >= 0; p--) {
   			switch (gameboard[i][p]) {
				case RED:
					redMoves++;
					break;
				default:
					redMoves = 1;
					break;
			}	
   		}

    	if (redMoves >= 4) {
    		return true;
    	}
    }	

return false;
}


bool playerMoves_b(int rows, int& compMoves_b, Global gameboard[][COLUMN_SIZE]) {
	rows = rows - 1;
	int blueMoves = 1;
	int j = compMoves_b - 1;
	bool q = false;		
	bool x = false;	
	int i;
	for (i = rows; i >= 0; i--) {
		switch (gameboard[i][j]) {
			case SPACE:
				q = true;
				gameboard[i][j] = BLUE;
				break;
			case BLUE:
				blueMoves++;
				break;
			default:
				blueMoves = 1;
				break;
		}
		if (q == true) {
			break;
		}
	}

	if (blueMoves >= 4) {
    	return true;
    }

    blueMoves = 1;
    if (i < 0) {
    	blueMoves - 1;
    	cout << "Invalid, REDS turn." << endl;
    }
    else {
    	for (int p = j + 1; p <= rows; p++) {
    		switch (gameboard[i][p]) {
				case BLUE:
					blueMoves++;
					break;
				default:
					blueMoves = 1;
					break;
			}
    	}

    	if (blueMoves >= 4) {
    		return true;
    	}

    	blueMoves = 1;
    	for (int p = j - 1; p >= 0; p--) {
   			switch (gameboard[i][p]) {
				case BLUE:
					blueMoves++;
					break;
				default:
					blueMoves = 1;
					break;
			}	
   		}

    	if (blueMoves >= 4) {
    		return true;
    	}	
    }

return false;
}
