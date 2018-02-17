#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int win(int a,int b){
	a++;
	int c =0;
	c = a-b;
	if(c>0){
		printf("승리");
	}
	else if(c==0){
		prinff("무승부"); 
	} 
	else{
		printf("패배");
	}
	 
}

int main(void) {	
	int a = 1 ;
	srand((unsigned)time(NULL));
	a = rand();
	a=a%3;
	int b =0;
	printf("가위는1 바위2 보는 3 ");
	scanf("%d",&b);
	if(a==0){
		printf("가위");
		win(a,b);
	}
	else if(a==1){
		printf("바위");
		win(a,b);
	}
	else
	{
		printf("보");
		win(a,b);
	 } 
	 return 0; 
}
