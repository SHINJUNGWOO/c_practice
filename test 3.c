#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int win(int a,int b){
	a++;
	int c =0;
	c = a-b;
	if(c>0){
		printf("�¸�");
	}
	else if(c==0){
		prinff("���º�"); 
	} 
	else{
		printf("�й�");
	}
	 
}

int main(void) {	
	int a = 1 ;
	srand((unsigned)time(NULL));
	a = rand();
	a=a%3;
	int b =0;
	printf("������1 ����2 ���� 3 ");
	scanf("%d",&b);
	if(a==0){
		printf("����");
		win(a,b);
	}
	else if(a==1){
		printf("����");
		win(a,b);
	}
	else
	{
		printf("��");
		win(a,b);
	 } 
	 return 0; 
}
