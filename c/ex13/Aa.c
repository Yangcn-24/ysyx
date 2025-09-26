#include<stdio.h>
int main(int argc,char *argv[]){
	char c=argv[1][0];
	if(c>='a'&&c<='z')
		printf("%c\n",c-32);
	else if(c>='A'&&c<='Z')
		printf("%c\n",c+32);
	else printf("%c\n",c);
	return 0;

}
