#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int a =0;
	int b=0;
	int c=0;
	int d=0;
	srand((unsigned)time(NULL));
	a= rand();
	b=b%236;
	c=c%870;
	d=d%375;
	b=b%9;
	c=c%9;
	d=d%9;
	printf("%d,%d,%d,%d",a,b,c,d);
	
	return 0;
}
