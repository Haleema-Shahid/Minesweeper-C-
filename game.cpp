#include<iostream>
#include<ctime>
#include<conio.h>
#include"help.h"
using namespace std;
void BackEndGridbeg(int arr[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = 0;
		}
	}
	srand(time(0));
	int x = 0, y = 0;
	for (int i = 0; i < 10; i++)
	{
		x = rand() % 10;
		y = rand() % 10;
		arr[x][y] = -1;
	}
	int count = 0;
	int j = 0;
	for (int i = 1; i < 9; i++) //loop for arr[i][0] side
	{
		count = 0;
		if (arr[i][j] == 0)
		{
			if (arr[i - 1][j] == -1)
			{
				count++;
			}
			if (arr[i - 1][j + 1] == -1)
			{
				count++;
			}
			if (arr[i][j + 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j + 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j] == -1)
			{
				count++;
			}
			arr[i][j] = count;
		}
	}
	count = 0;
	j = 9;
	for (int i = 1; i < 9 ; i++ ) //loop for arr[i][9]
	{
		count = 0;
		if (arr[i][j] ==0)
		{
			if (arr[i - 1][j] == -1)
			{
				count++;
			}
			if (arr[i - 1][j - 1] == -1)
			{
				count++;
			}
			if (arr[i][j - 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j - 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j] == -1)
			{
				count++;
			}
			arr[i][j] = count;
		}
	}
	int i = 0;
	count = 0;
	for (int j = 1; j < 9; j++) //loop for arr[0][j]
	{
		count = 0;
		if (arr[i][j] == 0)
		{
			if (arr[i][j - 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j - 1] == -1)
			{
				count++;
			}
			if (arr[i + 1][j] == -1)
			{
				count++;
			}
			if (arr[i + 1][j + 1] == -1)
			{
				count++;
			}
			if (arr[i][j + 1] == -1)
			{
				count++;
			}
			arr[i][j] = count;
		}
	}
	i = 9;
	count = 0;
	for (int j = 1; j < 9; j++) // loop for arr[9][j]
	{
		count = 0;
		if (arr[i][j] == 0)
		{
			if (arr[i][j - 1] == -1)
			{
				count++;
			}
			if (arr[i - 1][j - 1] == -1)
			{
				count++;
			}
			if (arr[i - 1][j] == -1)
			{
				count++;
			}
			if (arr[i - 1][j + 1] == -1)
			{
				count++;
			}
			if (arr[i][j + 1] == -1)
			{
				count++;
			}
			arr[i][j] = count;
		}
	}
	count = 0;
	for (int i = 1; i < 9; i++) //loop for every block except corners and edges
	{
		for (int j = 1; j < 9; j++)
		{
			count = 0;
			if (arr[i][j] == 0)
			{
				if (arr[i - 1][j] == -1)
					count++;
				if (arr[i - 1][j - 1] == -1)
					count++;
				if (arr[i][j - 1] == -1)
					count++;
				if (arr[i + 1][j - 1] == -1)
					count++;
				if (arr[i + 1][j] == -1)
					count++;
				if (arr[i + 1][j + 1] == -1)
					count++;
				if (arr[i][j + 1] == -1)
					count++;
				if (arr[i - 1][j + 1] == -1)
					count++;
				arr[i][j] = count;
			}
		}
	}
	//corners
	count = 0; 
	if (arr[0][0]==0)
	{
		if (arr[0][1] == -1)
			count++;
		if (arr[1][1] == -1)
			count++;
		if (arr[1][0] == -1)
			count++;
		arr[0][0] = count;
	}
	count = 0;
	if (arr[9][0]==0)
	{
		if (arr[8][0] == -1)
			count++;
		if (arr[8][1] == -1)
			count++;
		if (arr[9][1] == -1)
			count++;
		arr[9][0] = count;
	}
	count = 0;
	if (arr[9][9] == 0)
	{
		if (arr[9][8] == -1)
			count++;
		if (arr[8][8] == -1)
			count++;
		if (arr[8][9] == -1)
			count++;
		arr[9][9] = count;
	}
	count = 0;
	if (arr[0][9] == 0)
	{
		if (arr[0][8] == -1)
			count++;
		if (arr[0][8] == -1)
			count++;
		if (arr[1][8] == -1)
			count++;
		arr[0][9] = count;
	}
}
void UserGrid(char arr[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = '+';
		}
	}
}
void PrintFrontface(char arr[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
		cout << endl;
	}
}
void show0cells(int arr[10][10], char user[10][10], int i, int j, int x, int y)
{
	if (arr[i][j] != -1 && user[i][j] == '+' && i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		gotoxy(x, y);
		cout << arr[i][j];
		user[i][j] = '-';
		if (arr[i][j] == 0)
		{
			gotoxy(x, y);
			user[i][j] = '-';
			show0cells(arr, user, i, j + 1, x + 3, y);
			show0cells(arr, user, i, j - 1, x - 3, y);
			show0cells(arr, user, i-1, j + 1, x + 3, y-2);
			show0cells(arr, user, i-1, j , x , y-2);
			show0cells(arr, user, i-1, j - 1, x - 3, y-2);
			show0cells(arr, user, i+1, j, x , y+2);
			show0cells(arr, user, i+1, j + 1, x + 3, y+2);
			show0cells(arr, user, i+1, j - 1, x - 3, y+2);
		}
	}
}
void open(int arr[10][10],char user[10][10],int i, int j, int x, int y)
{
	if (arr[i][j] != 0 && arr[i][j] != -1 && user[i][j] == '+' && i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		gotoxy(x, y);
		cout << arr[i][j];
		user[i][j] = '-';
	}
	else if (arr[i][j] == 0 && user[i][j] == '+' && i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		show0cells(arr, user, i, j, x, y);
	}
	else if (arr[i][j] == -1 && user[i][j] == '+' && i >= 0 && i <= 9 && j >= 0 && j <= 9)
	{
		system("cls");
		cout << "KABOOM" << endl;
		cout << "GAME OVER" << endl;
		system("pause");
	}
}
void cursor(int arr[10][10], char user[10][10])
{
	int i = 0;
	int j = 0;
	int x = 0; 
	int y = 0;
	while (1) {
		char c='a';
		if (c == c)
		{
			c = _getch();
			if (c == 'w')
			{
				if (y > 0)
				{
					i--;
					y = y - 2;
					gotoxy(x, y);
				}
			}
			if (c == 'a')
			{
				if (x > 0)
				{
					j--;
					x=x-3;
					gotoxy(x, y);
				}
			}
			if (c == 'd')
			{
				if (x < 25)
				{
					j++;
					x=x+3;
					gotoxy(x, y);
				}
			}
			if (c == 's')
			{
				if (y < 18)
				{
					i++;
					y=y+2;
					gotoxy(x, y);
				}
			}
			if (c == 'o')
			{
				open(arr, user, i, j, x, y);
			}
			if (c == 'f')
			{
				if (user[i][j] == '+')
				{
					cout << 'f';
					user[i][j] = 'f';
				}
				else if (user[i][j] == 'f')
				{
					cout << '+';
					user[i][j] = '+';
				}
			}
		}
		else
			cout << c;

	}
}
void PrintGrid(int arr[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << "    ";
		}
		cout << endl;
	}
}
int main()
{
	
	int arr[10][10] = { 0 };
	BackEndGridbeg(arr);
	char Frontface[10][10];
	UserGrid(Frontface);
	PrintFrontface(Frontface);
	cursor(arr,Frontface);
	
}
