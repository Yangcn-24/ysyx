#include <unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
    int i = 0;

    while(i < 5) {
        usleep(3000);
    }
	printf("hello world\n");
    return 0;
}
