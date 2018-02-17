#include <stdio.h>
#include <windows.h>
#include <conio.h> //키보드 입력과 관련 
#include <time.h>
#include <stdlib.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32

int map[22][12];
int gameboard[21][10];
int numberone=0;
int numbertwo=0;

int block[7][4][4]=
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
   
;
   
typedef struct blockinformation
{
   int block[4][4];
   int nowblock;
   int fx;
   int fy;
   int x;
   int y;
    
}blockinformation;


   
   
   
void gotoxy(int x, int y)
{
   COORD Cur;
   Cur.X=x;
   Cur.Y=y;
   
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}




void makemap(void)
{
   int a,b;
   
   for(a=0;a<22;a++)
   {
      for(b=0;b<12;b++)
      {
         if(a==0||a==21)
         {
            map[a][b]=1;
         }
         else
         {
            map[a][0]=1;
            map[a][11]=1;
         }
      }
   }
}

void makegameboard(void)
{
   int a,b;
   
   for(a=0;a<20;a++)
   {
      for(b=0;b<10;b++)
      {
         if(a==20)
         {
            gameboard[a][b]=1;
          }
      }
   }
}


// 뷰맵에서는 xy위치가 배열과 반대임 
void viewmap(void)
{
   int a,b;
   for(a=0;a<22;a++)
   {
   
      for(b=0;b<12;b++)
      {
         if(map[a][b]==1)
         {
            gotoxy(b*2,a);// xy위치가 반대라 바꿔서 해놓음 
            printf("▨");
         }
      }
    }
}


blockinformation* makeblock(void)
{
   srand((unsigned)time(NULL));
   blockinformation* t=(blockinformation*)malloc(sizeof(blockinformation));
   int a,b;
   t->nowblock=rand()%7;
   t->fx=0;
   t->fy=3;
   t->x=t->fx;
   t->y=t->fy; 
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         t->block[a][b]=block[t->nowblock][a][b];
      }
   }
   return t;
   
} 

blockinformation* drowblock(blockinformation* t)
{
   int a,b;
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         if(t->block[a][b]==1) 
         {
            
            gameboard[a+t->x][b+t->y]=1;
         }
         /*else
         {
            gameboard[a+t->x][b+t->y]=0;
         }*/
      }
   }
   return t;
}

void viewblock(void)
{
   int a,b;
   for(a=0;a<20;a++)//블럭을 보는 것은 0~19까지 20은 안보이나 1 
   {
   
      for(b=0;b<10;b++)
      {
         
         if(gameboard[a][b]==1)
         {
            gotoxy(b*2+2,a+1);// +2는 틀을 벗어난 지역에 나타 내기 위해 a+1은 중요 
            printf("□");
         }
         else
         {
            gotoxy(b*2+2,a+1);// +2는 틀을 벗어난 지역에 나타 내기 위해 a+1은 중요 
            printf("  ");
         }
      
      }
    }
}

void turnblock(blockinformation* t)
{
   int copy[4][4];
   int a,b;
   
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         copy[a][b]=t->block[a][b];
      }
   }
   
   
   
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         t->block[b][3-a]=copy[a][b];
      }
   }
   
   
   
}



void removecursor(void)
{
   CONSOLE_CURSOR_INFO curinfo;
   curinfo.bVisible =0;
   GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
} 

void eraseblock(blockinformation* t)
{
   int a,b;
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         gameboard[a+t->x][b+t->y]=0;
      }
   }
}

int main(void)
{
   makemap();
   viewmap();
   makegameboard();
   
    //세팅완료
    
    
   viewblock();


   
   
   blockinformation *one=drowblock(makeblock());// 동적할당으로 교체 
   
   
   
   //정상 확인
   viewblock();
   
   
   while(1)
   {
   char key; 
   
   
   while(kbhit())
   {
      
      key=getch();
      switch(key)
      {
         case UP:
            eraseblock(one);
            one->x-=1;
            drowblock(one);
            viewblock();
            break;
         case DOWN:
            eraseblock(one);
            one->x+=1;
            drowblock(one);
            viewblock();
            break;
         case LEFT:
              eraseblock(one);
            one->y-=1;
            drowblock(one);
            viewblock();
              break;
          case RIGHT:
              eraseblock(one);
            one->y+=1;
            drowblock(one);
            viewblock();
             break;
             
             
          
      }
      
      if(key==SPACEBAR)
      {
         eraseblock(one);
         turnblock(one);
         drowblock(one);
         viewblock();
      }
   }
    }

    
}

