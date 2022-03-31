#include<iostream>
#include <cstdlib>
using namespace std;

char Matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
void Draw();
char Player_Win_logic();
void Toggle_Player();
void Input();
char First_Player = 'X';

/*
 1  2  3          0,0  0,1  0,2
 4  5  6    ->    1,0  1,1  1,2     (3X3 Matrix)
 7  8  9          2,0  2,1  2,2

*/


int main()
{
	Draw();
	while(1)
	{
		Input();
		Draw();
		Toggle_Player();
		if (Player_Win_logic() == 'X')
		{
			cout<<"X wins!"<<"\n"; break;
		}
		else if(Player_Win_logic() == 'O')
		{
			cout<<"O wins!"<<"\n"; break;
		}

	}
	return 0;
}


void Draw()
{
    system("cls");
	cout<<"Tic Tac Toe -> Game"<<"\n";
	cout<<"--------------------"<<"\n";

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<Matrix[i][j]<<" ";
		}
		cout<<'\n';
	}

}

void Input()
{
	int p;
	cout<<"Press the number of the field: "; cin>>p;

	if(p == 1)      Matrix[0][0] = First_Player;
	else if(p == 2) Matrix[0][1] = First_Player;
	else if (p == 3) Matrix[0][2] = First_Player;
	else if(p == 4) Matrix[1][0] = First_Player;
	else if (p == 5) Matrix[1][1] = First_Player;
	else if(p == 6) Matrix[1][2] = First_Player;
	else if (p == 7) Matrix[2][0] = First_Player;
	else if (p == 8) Matrix[2][1] = First_Player;
	else if (p == 9) Matrix[2][2] = First_Player;

}

void Toggle_Player()
{
	if(First_Player == 'X') {cout <<"2nd Player turn\n"; First_Player ='O';}
	else {cout <<"1st Player turn\n";First_Player = 'X';}
}


char Player_Win_logic()
{
	//For first_Player

	//Horizontal rows
	if (Matrix[0][0] == 'X' && Matrix[0][1] == 'X' && Matrix[0][2] == 'X') return 'X';
	if (Matrix[1][0] == 'X' && Matrix[1][1] == 'X' && Matrix[1][2] == 'X') return 'X';
	if (Matrix[2][0] == 'X' && Matrix[2][1] == 'X' && Matrix[2][2] == 'X') return 'X';

	//Vertical columns
	if (Matrix[0][0] == 'X' && Matrix[1][0] == 'X' && Matrix[2][0] == 'X') return 'X';
	if (Matrix[0][1] == 'X' && Matrix[1][1] == 'X' && Matrix[2][1] == 'X') return 'X';
	if (Matrix[0][2] == 'X' && Matrix[1][2] == 'X' && Matrix[2][2] == 'X') return 'X';

	//Corner 1,2
	if (Matrix[2][0] == 'X' && Matrix[1][1] == 'X' && Matrix[0][2] == 'X') return 'X';
	if (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X') return 'X';


	//For second Player

	//Horizontal rows
	if (Matrix[0][0] == 'O' && Matrix[0][1] == 'O' && Matrix[0][2] == 'O') return 'O';
	if (Matrix[1][0] == 'O' && Matrix[1][1] == 'O' && Matrix[1][2] == 'O') return 'O';
	if (Matrix[2][0] == 'O' && Matrix[2][1] == 'O' && Matrix[2][2] == 'O') return 'O';

	//Vertical columns
	if (Matrix[0][0] == 'O' && Matrix[1][0] == 'O' && Matrix[2][0] == 'O') return 'O';
	if (Matrix[0][1] == 'O' && Matrix[1][1] == 'O' && Matrix[2][1] == 'O') return 'O';
	if (Matrix[0][2] == 'O' && Matrix[1][2] == 'O' && Matrix[2][2] == 'O') return 'O';

	//Corner 1,2
	if (Matrix[2][0] == 'O' && Matrix[1][1] == 'O' && Matrix[0][2] == 'O') return 'O';
	if (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O') return 'O';

	return '/';
}
