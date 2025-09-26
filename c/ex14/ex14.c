#include <stdio.h>
#include <ctype.h>
#include <string.h>
// forward declarations
/* int can_print_it(char ch);
void print_letters(char arg[]);
 */
/* int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}
 */
/*
isdigit 數字
isalnum字母或數字
isxdigit十六進制數字
islower小寫字母
isupper大寫字母
isspace空白字符
ispunct標點符號
isprint可打印字符
isgraph圖形字符
iscntrl控制字符
*/
void print_letters(char arg[])
{
    int i = 0;

    for(i = 0; i<strlen(arg); i++) {
        char ch = arg[i];

        if(isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}


void print_arguments(int argc, char *argv[])
{
    int i;

    for(i = 1; i < argc; i++) {
        print_letters(argv[i]);
    }
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
