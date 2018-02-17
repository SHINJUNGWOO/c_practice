#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int arr[3]={0,0,0};
	for(int i=0;i<3;i++){
		srand((unsigned)time(NULL));
		arr[i]=rand();
		printf("%d \n",arr[i]);
	}
}
