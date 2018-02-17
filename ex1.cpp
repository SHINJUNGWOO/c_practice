#include <stdio.h>
#include <time.h>

int fall()
{
	int get=0;
	clock_t();
	get==clock()/2;
	printf("%d",get);
	if(get==100)
	{
		return 0;
	}
	else
	{
		fall();
	}
	
	
}


int main()
{
	while(fall!=0){
		fall();
	}
}


