#include<iostream>
#include<iomanip>
using namespace std;
int main ()
{
	cout << "Welcome to tic tac toe game :";
	char arr[3][3];
	int player = 1;
	bool p1 = true, p2 = false;
	int turn = 0;
	int cordinatex = 0,cordinatey=0;
	bool validate[3][3] = { false };
	bool game = true,won=false;


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ' ';
		}

	}

	while (game)
	{

		for (int i = 0; i < 3; i++)
		{
			cout << endl;
			int j = 0;

			cout << setw(3) << setfill(' ') << arr[i][j] << " |" << setw(3) << setfill(' ') << arr[i][j + 1] << "| " << setw(3) << setfill(' ') << arr[i][j + 2];
			if (i == 0 || i == 1)
			{
				cout << endl << setfill('-') << setw(12) << "-" << endl;
			}
			cout << endl;
		}
		if (p1)
		{
			cout << "player " << player << " turn :";
			player = 2;
			p1 = false;
			cout << " x cordinate 0-2  cordinate to place o ";
			cin >> cordinatex;
			cout << " y cordinate 0-2  cordinate to place o ";
			cin >> cordinatey;
			while (cordinatex > 2 || cordinatex < 0 || cordinatey>2 || cordinatey < 0 || validate[cordinatex][cordinatey] == true)
			{
				cout << endl << "invalid cordinate enter again ";
				cout << endl<<" x cordinate 0 - 2  cordinate to place o ";
				cin >> cordinatex;
				cout << endl << " y cordinate 0-2  cordinate to place o ";
				cin >> cordinatey;
			}
			arr[cordinatex][cordinatey] = 'o';
			validate[cordinatex][cordinatey] = true;
			p2 = true;
			turn++;

		}
		else if (p2)
		{
			cout << "player " << player << " turn :";

			player = 1;
			p2 = false;
			cout << " x cordinate 0-2  cordinate to place x ";
			cin >> cordinatex;
			cout << " y cordinate 0-2  cordinate to place x ";
			cin >> cordinatey;
			while (cordinatex > 2 || cordinatex < 0 || cordinatey>2 || cordinatey < 0 || validate[cordinatex][cordinatey] == true)
			{
				cout << endl << "invalid cordinate enter again ";
				cout << endl << " x cordinate 0-2  cordinate to place o ";
				cin >> cordinatex;
				cout << endl << " y cordinate 0 - 2  cordinate to place o ";
				cin >> cordinatey;
			}
			arr[cordinatex][cordinatey] = 'x';
			validate[cordinatex][cordinatey] = true;
			p1 = true;
			turn++;

		}
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			if (arr[i][0] == 'o' && arr[i][1] == 'o' && arr[i][2] == 'o')
			{
				cout << endl << "Player 1 Won!";
				won = true;
				break;
			}
			else if (arr[0][i] == 'o' && arr[1][i] == 'o' && arr[2][i] == 'o')
			{
				cout << endl << "PlAYER 1 WON !";
				won = true;
				break;
			}

		}
		for (int i = 0; i < 3; i++)
		{
			if (arr[i][0] == 'x' && arr[i][1] == 'x' && arr[i][2] == 'x')
			{
				cout << endl << "Player 2 Won!";
				won = true;
				break;
			}
			else if (arr[0][i] == 'x' && arr[1][i] == 'x' && arr[2][i] == 'x')
			{
				cout << endl << "PlAYER 2 WON !";
				won = true;
				break;
			}

		}
		if ((arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x') ||( arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == 'x'))
		{
			cout << endl << "PLAYER 2 WON !";
			won = true;
		}
		 if ((arr[0][0] == 'o' && arr[1][1] == 'o' && arr[2][2] == 'o') ||( arr[0][2] == 'o' && arr[1][1] == 'o' && arr[2][0] == 'o'))
		{
			cout << endl << "Player 1 Won ! ";
			won = true;
		}
		if (won)
		{
			game = false;
		}
		if (turn == 9)
		{
			cout <<endl<< "Match draw !";
			game = false;
		}
	}

	system ("pause");
	return 0;

}
