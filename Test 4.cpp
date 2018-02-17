#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void win(int a,int b);

int main(void) {
	int a = 1 ;
	int b =4;
	while(1) {
	
	srand((unsigned)time(NULL));
	a = rand();
	a=a%3;

	
		printf("가위는1 바위2 보는 3 \n");
		scanf("%d",&b);
		if(b>3){
			printf("잘못된 입력 \n"); 
		}
		else{
			if(a==0){
			printf("가위\n");
			win(a,b);
		}
		else if(a==1){
			printf("바위\n");
			win(a,b);
		}
		else
		{
			printf("보\n");
			win(a,b);
		 } 	
		}
	}
	return 0; 
}


void win(int a,int b){
	a++;
	int c =0;
	c = a-b;
	if(c>0){
		printf("승리");
	}
	else if(c==0){
		printf("무승부"); 
	} 
	else{
		printf("패배");
	}
	 
}



