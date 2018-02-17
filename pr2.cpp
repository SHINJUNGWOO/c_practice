#include <stdio.h>
#include <windows.h>

void gotoxy(int x,int y)
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

int main(void)
{
	
}

void outline()
{
	int a,b;
	for(a=1;a<41;a++)
	{
		b=0;
		gotoxy(a,b);
		printf("O");
	}
}

