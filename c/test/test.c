#include<stdio.h>
int main(){
    char *file_name="text.txt";
    char *data="Hello Linux!\n";
    FILE *fp;

    fp=fopen(file_name,"w");
    if(!fp) {
        printf("cant open this file");
    }
    fprintf(fp,"%s",data);
    if(fflush(fp)==0){
        printf("Successful!\n");
    }
    else printf("Fail!");
    fclose(fp);
    return 0;
}