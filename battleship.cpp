#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
char matrix[10][10]; // creates the computer's board
char playerboard[10][10]; // creates the player's board
char pos1;
int pos2;
int position;
int a,b,c,s,d = 0;
void prompt(){ // explaining the rules
	cout << "WELCOME TO BATTLESHIP!" << endl;
	cout << "Here are the rules:"<< endl;
	cout << "1. There are 5 ships randomly placed on the grid." << endl;
	cout << "2. Choose coordinates where you think the ship is located." << endl;
	cout << "3. An X or O will be placed on that coordinate to indicate if you hit or missed the ship." << endl;
	cout << "4. You will be given 50 chances to sink all the ships." << endl;
	cout << "LET'S BEGIN!" << endl;
	cout << endl;
}
void reset(char b [10][10]) // resets the board
{
	for(int r=0; r < 10; r++)
	{
		for(int c=0; c < 10; c++)
		{
			b[r][c] = '_';
		}
	}
}
void show(char b[10][10]) // displays board
{
	for(int r=0; r<10; r++){
		if(r<9){
			cout << " ";
		}
		cout << r+1 <<" ";
		for(int c = 0; c<10; c++){
			cout << b[r][c] << " ";
		}
		cout << endl;
	}
	cout << "   ";
	for(char letter = 'A'; letter < 'A' + 10; letter++){
		cout << letter << " ";
	}
}

// creates all the ships with different lengths

void aircraft(){
	int x = rand() % 6;
	int y = rand() % 6;
	int position = rand() % 2;
	for (int a = 0; a < 5; a++){
		if( position == 1){
			matrix[x+a][y] = 'A';
		}
		else{
			matrix[x][y+a] = 'A';

		}
	}
}
void battleship(){
	int x = rand() % 7;
	int y = rand() % 7;
	int position = rand() % 2;
	for (int a = 0; a < 4; a++){
		if( position == 1){
			//  cout << matrix[x+a][y] << endl;
			if(matrix[x+a][y] == 'A'){
				if(matrix[x][y] =='A'){
					battleship();
					break;
				}
				if(matrix[x+2][y]=='B'){
					// cout << "hi?" << endl;
					matrix[x+2][y] = '_';
				}
				if(matrix[x+1][y]=='B'){
					// cout << "umm" << endl;
					matrix[x+2-1][y]='_';
				}
				if(matrix[x][y]=='B'){
					//  cout << "hehe" << endl;
					matrix[x][y]='_';
				}
				battleship();
				break;
			}
			else{
				matrix[x+a][y] = 'B';
			}
		}
		else{
			if(matrix[x][y+a] == 'A'){
				if(matrix[x][y] =='A'){
					battleship();
					break;
				}
				if(matrix[x][y+2]=='B'){
					matrix[x][y+2] = '_';
				}
				if(matrix[x][y+1]=='B'){
					matrix[x][y+1]='_';
				}
				if(matrix[x][y]=='B'){
					matrix[x][y]='_';
				}
				battleship();
				break;
			}
			else{
				matrix[x][y+a] = 'B';
			}
		}
	}
}
void cruiser(){
	int x = rand() % 8;
	int y = rand() % 8;
	int position = rand() % 2;
	for (int a = 0; a < 3; a++){
		if( position == 1){
			if(matrix[x+a][y] == 'A'||matrix[x+a][y] == 'B'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'){
					cruiser();
					break;
				}
				if(matrix[x+1][y]=='C'){
					matrix[x+2-1][y]='_';
				}
				if(matrix[x][y]=='C'){
					matrix[x][y]='_';
				}
				cruiser();
				break;
			}
			else{
				matrix[x+a][y] = 'C';
			}
		}
		else{
			if(matrix[x][y+a] == 'A'||matrix[x][y+a] == 'B'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'){
					cruiser();
					break;
				}
				if(matrix[x][y+1]=='C'){
					matrix[x][y+1]='_';
				}
				if(matrix[x][y]=='C'){
					matrix[x][y]='_';
				}
				cruiser();
				break;
			}
			else{
				matrix[x][y+a] = 'C';
			}
		}
	}
}
void submarine(){
	int x = rand() % 8;
	int y = rand() % 8;
	int position = rand() % 2;
	for (int a = 0; a < 3; a++){
		if( position == 1){
			if(matrix[x+a][y] == 'A'||matrix[x+a][y] == 'B'||matrix[x+a][y] == 'C'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'||matrix[x][y] =='C'){
					submarine();
					break;
				}
				if(matrix[x+1][y]=='S'){
					matrix[x+2-1][y]='_';
				}
				if(matrix[x][y]=='S'){
					matrix[x][y]='_';
				}
				submarine();
				break;
			}
			else{
				matrix[x+a][y] = 'S';
			}
		}
		else{
			if(matrix[x][y+a] == 'A'||matrix[x][y+a] == 'B'||matrix[x][y+a] == 'C'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'||matrix[x][y] =='C'){
					submarine();
					break;
				}
				if(matrix[x][y+1]=='S'){
					matrix[x][y+1]='_';
				}
				if(matrix[x][y]=='S'){
					matrix[x][y]='_';
				}
				submarine();
				break;
			}
			else{
				matrix[x][y+a] = 'S';
			}
		}
	}
}
void destroyer(){
	int x = rand() % 9;
	int y = rand() % 9;
	int position = rand() % 2;
	for (int a = 0; a < 2; a++){
		if( position == 1){
			if(matrix[x+a][y] == 'A'||matrix[x+a][y] == 'B'||matrix[x+a][y] == 'C'||matrix[x+a][y] == 'S'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'||matrix[x][y] =='C'||matrix[x][y] == 'S'){
					destroyer();
					break;
				}
				if(matrix[x][y]=='D'){
					matrix[x][y]='_';
				}
				destroyer();
				break;
			}
			else{
				matrix[x+a][y] = 'D';
			}
		}
		else{
			if(matrix[x][y+a] == 'A'||matrix[x][y+a] == 'B'||matrix[x][y+a] == 'C'||matrix[x][y+a] == 'S'){
				if(matrix[x][y] =='A'||matrix[x][y] =='B'||matrix[x][y] =='C'||matrix[x][y] =='S'){
					destroyer();
					break;
				}
				if(matrix[x][y]=='D'){
					matrix[x][y]='_';
				}
				destroyer();
				break;
			}
			else{
				matrix[x][y+a] = 'D';
			}
		}
	}
}

// updates player's board if they hit the ship
// update counter for each ship
bool attack(char x,char y)
{
	if(matrix[x][y] == 'A'){
		playerboard[x][y] = 'X';
		a++;
		return true;
	}
	if(matrix[x][y] == 'B'){
		playerboard[x][y] = 'X';
		b++;
		return true;
	}
	if(matrix[x][y] == 'C'){
		playerboard[x][y] = 'X';
		c++;
		return true;
	}
	if(matrix[x][y] == 'S'){
		playerboard[x][y] = 'X';
		s++;
		return true;
	}
	if(matrix[x][y] == 'D'){
		playerboard[x][y] = 'X';
		d++;
		return true;
	}
	if(matrix[x][y] == '_'){
		playerboard[x][y] ='O';

	}
	return false;
}

// wins only if all ships are sank
bool won(){
	if(a == 5 && b == 4 && c == 3 && s == 3 && d == 2){
		return true;
	}
	return false;
}
int main()
{
	srand(time(NULL));
	prompt(); // prints prompt
	reset(matrix); // sets up the computer's board
	// laying out the ships on the computer's board
	aircraft();
	battleship();
	cruiser();
	submarine();
	destroyer();
	reset(playerboard); // sets up the player's board
	int shipcount = 0;
	int counter = 0;
	do{
		{
			//show(matrix); // testing purposes to check if player is hitting computer's ships
			cout << endl;
			show(playerboard);
			cout << endl;
			cout << "counter: " << counter << endl;
			cout << "Please enter a capital letter (A-J): ";
			cin >> pos1;
			{
				if(pos1 == 'A'){
					pos1 = 0;
				}
				else if (pos1 == 'B'){
					pos1 = 1;
				}
				else if(pos1 == 'C'){
					pos1 = 2;
				}
				else if(pos1 == 'D'){
					pos1 = 3;
				}
				else if(pos1 == 'E'){
					pos1 = 4;
				}
				else if(pos1 == 'F'){
					pos1 = 5;
				}
				else if(pos1 == 'G'){
					pos1 = 6;
				}
				else if(pos1 == 'H'){
					pos1 = 7;
				}
				else if(pos1 == 'I'){
					pos1 = 8;
				}
				else if(pos1 == 'J'){
					pos1 = 9;
				}
			}

			// getting user's input for number
			// printing appropriate text
			cout << "Please enter a number (1-10): ";
			cin >> pos2;
			if(attack(pos2-1,pos1)){
				cout << "You got me!" << endl;

			}
			else{
				cout << "Sorry no ship at that position!" << endl;
			}
			if(a == 5){
				cout << "YOU SANK THE AIRCRAFT" << endl;
			}
			if(b == 4){
				cout << "YOU SANK THE BATTLESHIP" << endl;
			}
			if(c == 3){
				cout << "YOU SANK THE CRUISER" << endl;
			}
			if(s == 3){
				cout << "YOU SANK THE SUBMARINE" << endl;
			}
			if(d == 2){
				cout << "YOU SANK THE DESTROYER" << endl;
			}

			counter++;
		}
	} while(counter <= 50 && won()== false); // lost if counter gets to 50
	if(won()== true){
		cout << endl;
		cout << "YOU WON!" << endl;
	}
	else{
		cout << endl;
		cout << "GAME OVER!" << endl;
	}

	show(matrix);
}



