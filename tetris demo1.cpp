#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int block();
int blockmove(int(*cube1)[4][4], int blockkind);
void array();
int outline[30][31] = { 0 };
void blockturnr(int(*cube1)[4][4], int blockkind);
void blockturnl(int(*cube1)[4][4], int blockkind);
int i, j = 0;
void clear();
int absx, absy;
void right(int(*cube1)[4][4], int blockkind);
void left(int(*cube1)[4][4], int blockkind);
int wall(int(*cube1)[4][4], int blockkind);
void fall(int(*cube1)[4][4], int blockkind),int key);
void down(int(*cube1)[4][4], int blockkind);
void up(int(*cube1)[4][4], int blockkind);
void check();


void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int main()
{
	for (int a = 1; a<31; a += 2)
	{
		int b = 0;
		gotoxy(a, b);
		printf("▩");
		outline[a][b] = 1;

		b = 30;
		gotoxy(a, b);
		printf("▩");
		outline[a][b] = 1;
	}
	for (int b = 1; b<31; b++)
	{

		int a = 1;
		gotoxy(a, b);
		printf("▩");
		outline[a][b] = 1;
		a = 29;
		gotoxy(a, b);
		printf("▩");
		outline[a][b] = 1;
	}
	array();
	absx = 3;
	absy = 1;
	block();

}

int block()
{
	check();
	array();
	absx = 3;
	absy = 1;
	array();
	srand((unsigned)time(NULL));
	int blockkind = rand() % 7;
	int cube1[7][4][4] =
	{

		0,0,0,0,
		0,1,1,0,
		0,1,1,0,
		0,0,0,0,

		0,0,0,0,
		0,1,1,0,
		0,1,0,0,
		0,1,0,0,

		0,0,0,0,
		0,1,1,0,
		0,0,1,0,
		0,0,1,0,

		0,0,0,0,
		1,1,1,1,
		0,0,0,0,
		0,0,0,0,

		0,0,0,0,
		0,0,1,0,
		0,1,1,0,
		0,1,0,0,

		0,0,0,0,
		0,1,0,0,
		0,1,1,0,
		0,0,1,0,

		0,0,0,0,
		0,1,0,0,
		1,1,1,0,
		0,0,0,0

	};

	absx = 3;
	absy = 1;
	gotoxy(absx, absy);

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}

	}
	while (1)
	{
		blockmove(cube1, blockkind);
	}
}

int blockmove(int(*cube1)[4][4], int blockkind)
{
	int key = 0;

	while (1)
	{
		if (kbhit())
		{
			key = getch();
			switch (key)
			{
			case 100:

				right(cube1, blockkind);
				array();
				gotoxy(absx, absy);
				if (wall(cube1, blockkind) == 1) {
					left(cube1, blockkind);
					array();

				}

				break;
			case 97:

				left(cube1, blockkind);
				array();
				gotoxy(absx, absy);
				if (wall(cube1, blockkind) == 1) {
					right(cube1, blockkind);
					array();
				}
				break;
			case 115:
				blockturnr(cube1, blockkind);
				clear();
				
				if (wall(cube1, blockkind) == 1) 
				{
					blockturnl(cube1, blockkind);
					array();
				}
				break;
			}
		}
		fall(cube1, blockkind, key);
	}
}

void array()
{

	for (int a = 1; a<31; a += 2)
	{
		for (int b = 0; b<31; b++)
		{
			if (outline[a][b] == 1)
			{
				gotoxy(a, b);
				printf("▩");
			}
		}
	}
	gotoxy(absx, absy);

	//제 2사분면의 안쪽 최초 좌표는 (3,1) 
	// 제 1사분면의 안쪽 최초 좌표는 (28,1 )
	//제 4사분면의 안쪽 최초 좌표는 (28,29 )
	//제 3사분면의 안쪽 최초 좌표는 (3,29 )	
}

void blockturnl(int(*cube1)[4][4], int blockkind)
{
	int copy[4][4] = { 0 };

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			copy[i][j] = cube1[blockkind][i][j];
		}

	}
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			cube1[blockkind][i][j] = copy[3 - j][i];
		}

	}

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}

	}
	array();
	gotoxy(absx, absy);

}

void blockturnr(int(*cube1)[4][4], int blockkind)
{
	int copy[4][4] = { 0 };

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			copy[i][j] = cube1[blockkind][i][j];
		}

	}
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			cube1[blockkind][i][j] = copy[j][3-i];
		}

	}

	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}

	}
	array();
	gotoxy(absx, absy);

}

void clear()
{
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			printf("  ");
		}

	}
}

int wall(int(*cube1)[4][4], int blockkind)
{
	int check[4][4] = { 0 };
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			check[i][j] = cube1[blockkind][i][j] + outline[absx + 2 * i][absy + j];
			if (check[i][j] == 2)
			{
				return 1;
			}
		}
	}
}

void right(int(*cube1)[4][4], int blockkind)
{
	clear();
	gotoxy(absx += 2, absy);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}
	}
}

void left(int(*cube1)[4][4], int blockkind)
{
	clear();
	gotoxy(absx -= 2, absy);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}
	}
}

void down(int(*cube1)[4][4], int blockkind)
{
	clear();
	gotoxy(absx, absy += 1);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}
	}
	array();
}

void up(int(*cube1)[4][4], int blockkind)
{
	clear();
	gotoxy(absx, absy -= 1);
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			gotoxy(absx + (i * 2), absy + j);
			if (cube1[blockkind][i][j] == 1)
			{

				printf("▦");
			}

		}
	}
	array();
}



void fall(int(*cube1)[4][4], int blockkind,int key)
{
	clock_t vind;
	vind = clock();
	if (vind % 200 == 0)
	{

		if (wall(cube1, blockkind) != = 0)
		{
			down(cube1, blockkind);
			if (wall(cube1, blockkind) == 1)
			{
				up(cube1, blockkind);
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (cube1[blockkind][i][j] == 1)
						{
							outline[absx + (i * 2)][absy + j] = 1;

						}
					}
				}

				clear();

				array();
				block();
			}
		}

	}

}

void check()
{

	{
		for (int b = 1; b<30; b++)
		{
			if (outline[3][b] && outline[5][b] && outline[7][b] && outline[9][b] && outline[11][b] && outline[13][b] && outline[15][b] && outline[17][b] &&
				outline[19][b] && outline[21][b] && outline[23][b] && outline[25][b] && outline[27][b])

			{
				for (int a = 3; a<29; a += 2)
				{
					gotoxy(a, b);
					printf(" ");
				}
				for (b = 29; b>1; b--)
				{
					for (int a = 3; a<29; a += 2)
					{
						outline[a][b] = outline[a][b - 1];
						outline[a][1] = 0;
					}
				}
				for (int a = 3; a<29; a += 2)
				{
					for (int b = 29; b>1; b--)
					{
						gotoxy(a, b);
						printf("  ");
					}
				}
			}

		}

	}
}