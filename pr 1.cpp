#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int block1(void);

void gotoxy(int x,int y)
{
     COORD Cur;
     Cur.X=x;
     Cur.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}
int main()
{
		int outline[30][31]={0};
     for(int a=1;a<31;a+=2)
	 {
	 	int b =0;
     	gotoxy(a,b);
     	printf("▩");
     	outline[a][b]=1;
     	
     	b =30;
     	gotoxy(a,b);
     	printf("▩");
     	outline[a][b]=1;
	 }
	 for(int b=1;b<31;b++)
	 {
	 	
	 	int a=1;
	 	gotoxy(a,b);
	 	printf("▩");
	 	outline[a][b]=1;
	 	a=29;
	 	gotoxy(a,b);
	 	printf("▩");
	 	outline[a][b]=1;
	 }
 	//제 2사분면의 안쪽 최초 좌표는 (3,1) 
	// 제 1사분면의 안쪽 최초 좌표는 (28,1 )
	//제 4사분면의 안쪽 최초 좌표는 (28,29 )
	//제 3사분면의 안쪽 최초 좌표는 (3,29 )

	gotoxy(3,1);
	block1(); 
	
	
	
}


int block1(void) 
{
		srand ((unsigned)time (NULL));
		int block1a=0;
		int cube[4][3][3] =
		{
			{
			0,1,0,
			0,1,0,
			0,1,1
			},
			{
			
			0,0,0,
			1,1,1,
			1,0,0
			},
			{
			1,1,0,
			0,1,0,
			0,1,0
			},
			{
			0,0,1,
			1,1,1,
			0,0,0
			}
		};
		int i,j=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				gotoxy(3+(i*2),1+j);
				if(cube[a][i][j]==1)
				{
				
				printf("▦");
				}
			
			}		
			
		}
		
}
