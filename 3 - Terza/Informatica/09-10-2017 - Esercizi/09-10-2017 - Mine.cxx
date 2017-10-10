//Trovato online
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdlib.h>
using namespace std;

char displayArray [5][5], mineArray [5][5], playAgain;
int numMines, xPosNum, yPosNum, count = 0;
string mines, xPos, yPos;

void assignArray();
void mineCount();
void showArray(char anArray[5][5]);
void playGame();
void adjacentCheck();
int checkGame();

int main()
{
	//Main program running
	do
	{
		system("cls");

		//User inputs the number of mines he wants
		do
		{
			cout << "Please enter a valid number of mines (min = 5, max = 10): ";
			cin >> mines;
			stringstream(mines) >> numMines;
		}while(numMines < 5 || numMines > 10);

		//Code to clear the screen
		system("cls");

		assignArray();
		showArray(displayArray);
		playGame();

		cout << "Play again? (Y/N): ";
		cin >> playAgain;
		}while(playAgain == 'Y' || playAgain == 'y');

	return 0;
}

//Function to randomly assign mines and symbols to the arrays
void assignArray()
{
	srand((unsigned int)time(0));
	
	//Assigning symbols to the arrays
	for(int row = 0; row < 5; row ++){
		for(int col = 0; col < 5; col ++){
			displayArray [row][col] = '*';
			mineArray [row][col] = '0';
		}
	}

	//Randomly assigning mines
	for(int i = 0; i < numMines; i++){
		int row = (rand() % 4);
		int col = (rand() % 4);
		while(mineArray[row][col] == '@'){
			row = (rand() % 4);
			col = (rand() % 4);
		}
		mineArray[row][col] = '@';
	}

	//Counting the mines for adjacent tiles
	mineCount();
}

//Function to count mines for surrounding tiles
void mineCount()
{
	for(int row = 0; row < 5; row ++){
		for(int col = 0; col < 5; col++){
			if(mineArray [row][col] == '@'){
				for(int x = row - 1; x <= row + 1; x++){
					for(int y = col - 1; y <= col + 1; y++){
						if(x >= 0 && x <= 4){
							if(y >= 0 && y <= 4){
								if(mineArray[x][y] != '@'){
									mineArray[x][y] += 1;
								}
							}
						}
					}
				}
			}
		}
	}
}

//Function for displaying arrays
void showArray(char anArray[5][5])
{
	for(int row = 0; row < 5; row++){
		for(int col = 0; col < 5; col++){
			cout << anArray [row][col] << " ";
		}
		cout << endl;
	}
}

//Function for playing the game
void playGame()
{
	//Code for selecting a valid tile
	for(int i = 0; i <= 25; i++){

		do
		{
			cout << "Please enter a valid row position number (1 - 5): ";
			cin >> xPos;
			stringstream(xPos) >> xPosNum;
		}while(xPosNum < 1 || xPosNum > 5);

		do
		{
			cout << "Please enter a valid column position number (1 - 5): ";
			cin >> yPos;
			stringstream(yPos) >> yPosNum;
		}while(yPosNum < 1 || yPosNum > 5);

		//Code for checking if the tile has already been chosen
		while(displayArray[xPosNum - 1][yPosNum - 1] == mineArray[xPosNum - 1][yPosNum - 1]){
			cout << "That position has already been revealed." << endl << endl;

			cout << "Please enter another row position number: ";
			cin >> xPos;
			stringstream(xPos) >> xPosNum;

			cout << "Please enter another column position number: ";
			cin >> yPos;
			stringstream(yPos) >> yPosNum;
		}

		//Code for checking for a loss or victory
		if(mineArray[xPosNum - 1][yPosNum - 1] == '@'){
			cout << "\nOpps! You stepped on a mine!" << endl;
			cout << "Game Over!" << endl << endl;
			showArray(mineArray);
			return;
		}

		else{
			system("cls");
			displayArray[xPosNum - 1][yPosNum - 1] = mineArray[xPosNum - 1][yPosNum - 1];
			adjacentCheck();
			showArray(displayArray);
			count = checkGame();

			if(count == (25 - numMines)){
				cout << "\nCongrats! You've cleared all the mines!" << endl;
				return;
			}
		}
	}
}

//Function for revealing numbers surrounding a '0' tile
void adjacentCheck()
{
	if(mineArray[xPosNum - 1][yPosNum - 1] == '0'){
		for(int x = xPosNum - 2; x != xPosNum + 1; x++){
			for(int y = yPosNum - 2; y != yPosNum + 1; y++){
				if(x >= 0 && x <= 4){
					if(y >= 0 && y <= 4){
						displayArray[x][y] = mineArray[x][y];						
						if(mineArray[x][y] == '0'){
							for(int x2 = x - 1; x2 != x + 2; x2++){
								for(int y2 = y - 1; y2 != y + 2; y2++){
									if(x2 >= 0 && x2 <= 4){
										if(y2 >= 0 && y2 <= 4){
											if(mineArray[x2][y2] != '@'){
											displayArray[x2][y2] = mineArray[x2][y2];
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

//Function to check for a victory
int checkGame()
{
	int count = 0;
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			if(displayArray[x][y] == mineArray[x][y]){
				count += 1;
			}
		}
	}
	return count;
}
