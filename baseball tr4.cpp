#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
   int arr[3]={0};
   srand((unsigned)time(NULL));
   for(int i=0;i<3;i++){
      arr[i]=rand()%9;
     // printf("%d \n",arr[i]);
   }
   int d =0;
   while(d<3) {
   int a=10;
   int b=10;
   int c=10;
   while(a>9||b>9||c>9){
   	printf(" \n�� ���� �Է����ּ��� \n");
   scanf("%d %d %d",&a,&b,&c);
   }
   	printf("�Է��� ���� %d,%d,%d \n",a,b,c);
   	
   	
	   d=0;;
   	if(arr[0]==a||arr[0]==b||arr[0]==c){
   		printf(" ��Ʈ����ũ");
   		d++;
	   }
	   else{
	   	printf("��");
	   } 
	if(arr[1]==a||arr[1]==b||arr[1]==c){
   		printf(" ��Ʈ����ũ ");
   		d++;
	   }
	   else{
	   	printf(" �� ");
	   } 
	if(arr[2]==a||arr[2]==b||arr[2]==c){
   		printf(" ��Ʈ����ũ");
   		d++;
	   }
	   else{
	   	printf("��");
	   }
	}
	printf(" \n �¸��ϼ̽��ϴ�!");
}


