#include<stdio.h>
int main(){
    int distance=100;
    float power=2.345;
    double super_power=56789.4532;
    char initial='A';
    char first_name[]="Zed";
    char last_name[]="Shaw";

    printf("You are %d niles away.\n",distance);
    printf("You are %x niles away.\n",distance);//16進制
    printf("You are %o niles away.\n",distance);//8進制
    puts("");					  //打印空字符
    printf("You have %.7f levels of power.\n",power);
    printf("You have %.10f awesome super power.\n",super_power);
    printf("I have an initial %c.\n",initial);
    printf("I have a first name %s.\n",first_name);
    printf("I have a last name %s.\n",last_name);
    printf("My whole name is %s %c. %s.\n",
        first_name,initial,last_name);
    return 0;

}
/*
打印數字的方法：
	%d：有符號十進制整數
	%u：無符號十禁止整數
	%f：浮點數
	%lf:雙精度浮點數
	%x：無符號十六進制整數
	%o：無符號八進制整數
*/
