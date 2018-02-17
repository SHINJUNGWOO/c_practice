#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int arr[3]= {0};
	srand((unsigned)time (NULL));
	for(int i=0;i<3;i++) {
		arr[i]=rand()%9;
		printf("%dÀÇ °ªÀº%d \n",i,arr[i]);
	}
	printf("%d,%d,%d \n,",arr[0],arr[1],arr[2]);
	return 0;
}
