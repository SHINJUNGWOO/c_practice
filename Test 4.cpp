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

	
		printf("������1 ����2 ���� 3 \n");
		scanf("%d",&b);
		if(b>3){
			printf("�߸��� �Է� \n"); 
		}
		else{
			if(a==0){
			printf("����\n");
			win(a,b);
		}
		else if(a==1){
			printf("����\n");
			win(a,b);
		}
		else
		{
			printf("��\n");
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
		printf("�¸�");
	}
	else if(c==0){
		printf("���º�"); 
	} 
	else{
		printf("�й�");
	}
	 
}



