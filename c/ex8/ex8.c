#include<stdio.h>
int main(){
    int areas[]={10,12,13,14,20};
    char name[]="YCN";
    char full_name[]={'Y','a','n','g',' ','.',
        'C','h','a','o',
        'N','a','n'};
    printf("The size of an int:%ld\n",sizeof(int));
    printf("The size of ares(int[]):%ld\n",sizeof(areas));
    printf("The number of ints in ares:%ld\n",sizeof(areas)/sizeof(int));
    printf("The first area is %d,the 2nd %d.\n",areas[0],areas[10]);
    printf("The size of a char:%ld\n",sizeof(char));
    printf("The size of name(char[]):%ld\n",sizeof(name));
    printf("The number of chars:%ld\n",sizeof(name)/sizeof(char));
    printf("The size of full_name(char[]):%ld\n",sizeof(full_name));
    printf("The number of chars:%ld\n",sizeof(full_name)/sizeof(char));
    printf("name=\"%s\" and full_name=\"%s\"\n",name,full_name);
    return 0;
}