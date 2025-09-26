#include<stdio.h>
#include "add.h"
#include "minus.h"
int main(int argc,char *argv[])
{
	int a=15;
	int b=10;
	int res1=add(a,b);
	int res2=minus(a,b);
	printf("a + b = %d\n",res1);
	printf("a - b = %d\n",res2);
	return 0;
}
