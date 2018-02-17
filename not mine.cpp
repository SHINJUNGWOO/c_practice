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
int gameboard[21][12];
int numberone=0;
int numbertwo=0;
int linenumber=0;
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
   
   for(a=0;a<21;a++)
   {
      for(b=0;b<12;b++)
      {
         if(a==20)
         {
            gameboard[a][b]=3;
          }
         
         else if(b==0||b==11)
         {
            gameboard[a][b]=5;//벽면은 5로 일단 설정 
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

void eraseblock(blockinformation* t)
{
   int a,b;
   for(a=0;a<4;a++)
   {
      for(b=0;b<4;b++)
      {
         if(t->block[a][b]==1)
      {
         gameboard[a+t->x][b+t->y]-=1;//1뺀다 그 부분만 
      } 
         
      }
   }
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
            
            gameboard[a+t->x][b+t->y]+=1;//1 더한다
          
         }

      }
   }
   return t;
}

void linedown(void)
{
   int a,b;
   int total;
   int save;
   for(a=19;a>0;a--)
        {
           total=0;
            for(b=1;b<11;b++)
            {
               total+=gameboard[a][b];
            }
            
            if(total==30)
            {
               save=a;
               for(;a>0;a--)
                {
                    for(b=0;b<12;b++)
                    {
                       gameboard[a+1][b]=gameboard[a][b];
                    }
                }
                a=save+1;
                linenumber+=1;
                gotoxy(50,20);
                printf("%d",linenumber);
         }
        }

}



void viewblock(void)
{
   int a,b;
   for(a=0;a<20;a++)//블럭을 보는 것은 0~19까지 20은 안보이나 1  일시적 20까지 보이게 함 
   {
   
      for(b=0;b<12;b++)
      {
         
         if(gameboard[a][b]==1)
         {
            gotoxy(b*2,a+1);// +2는 틀을 벗어난 지역에 나타 내기 위해 a+1은 중요 
            printf("□");
         }
         else if(gameboard[a][b]==3)
         {
            gotoxy(b*2,a+1);
            printf("☆");
         }
         

         else if(gameboard[a][b]==0)
         {
            gotoxy(b*2,a+1);
            printf("  ");
         }
      }
    }
}

int chackbottom(void)
{
   int a,b;
    for(a=0;a<21;a++) //여기는21까 
    {
   
      for(b=0;b<12;b++)
      {
         
         if(gameboard[a][b]==4)
         {
            return 1;
         }
         
      }
    }
    return 0;
}

int chackwall(void)
{
   numberone=0;
    int a,b;
    for(a=0;a<20;a++) 
    {
   
      for(b=0;b<12;b++)
      {
         
         if(b==0||b==11)
         {
            numberone+=gameboard[a][b];
         }
         
      }
    }
    if(numberone==200)
    {
       return 0;
   }
   else
   {
      return 1;
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

void staticblock(blockinformation* t)
{
    int a,b;
   
    for(a=0;a<4;a++)
    {
        for(b=0;b<4;b++)
        {
          if(t->block[a][b]==1)
          {
             gameboard[a+t->x][b+t->y]=3;
        }
          
        }
     }
     
} 




int main(void)
{
   CONSOLE_CURSOR_INFO CurInfo;
   CurInfo.dwSize=1;
   CurInfo.bVisible=FALSE;
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);



   makemap();
   viewmap();
   makegameboard();
   
    
   viewblock();


   start:;
   
   blockinformation *one=drowblock(makeblock());// 동적할당으로 교체 
   
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
            if(chackbottom()==1)//바닥에 블록이 닿았을 때 
            {
               eraseblock(one);
               one->x-=1;//롤백 밑에 이제 배경에 추가해야징 
            staticblock(one);
            linedown(); 
            viewblock();
            free(one);//동적할당 해제 
            
            goto start;
         }
          else
          {
             viewblock();
         }
            
            break;
         case LEFT:
                eraseblock(one);
                 one->y-=1;
                drowblock(one);
                if(chackbottom()==1)//바닥에 블록이 닿았을 때 
                {
                   eraseblock(one);
                   one->y+=1;
               drowblock(one);
               viewblock();
             }
              else
              {
                   if(chackwall()==0)
                    {
                        viewblock();
                 }
                    else
                   {
                       eraseblock(one);
                       one->y+=1;
                   drowblock(one);
                   viewblock();
                 }
             }
                
           
            
              break;
          case RIGHT:
            eraseblock(one);
            one->y+=1;
            drowblock(one);
             if(chackbottom()==1)//바닥에 블록이 닿았을 때 
                {
                   eraseblock(one);
                   one->y-=1;
               drowblock(one);
               viewblock();
             }
              else
              {
                   if(chackwall()==0)
                    {
                        viewblock();
                 }
                    else
                   {
                       eraseblock(one);
                       one->y-=1;
                   drowblock(one);
                   viewblock();
                 }
             }
            
                break;
             
             
          
      }
      
      if(key==SPACEBAR)
      {
         eraseblock(one);
         turnblock(one);
         drowblock(one);
         if(chackwall()==0)
            {
                viewblock();
         }
        else
            {
                  eraseblock(one);
                  one->y-=1;
            drowblock(one);
            if(chackwall()==0)//이게 벽에서 돌릴 때 발생하는 오류 잡는 코드 
                {
                   viewblock();
            }
                else
                {
                   eraseblock(one);
                   one->y+=2;
               drowblock(one);
               viewblock();//여기까지 
            }
         }
      }
   }
    }

    
}
