#include<stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
    int i=0;
    argv[0]="ycn";
    for(i;i<argc;i=i+1){
        printf("arg %d: %s\n",i,argv[0]);
    }

    char *states[]={
        "California","Oregon","Washington","Texas"		
    };
    states[0]=argv[0];
    int num_states=4;
    for(i=0;i<num_states;i++){
        printf("state %d: %s,bytes:%ld\n",i,states[i],strlen(states[i]));
    }
    printf("%s\n",states[1]);
    return 0;


}
