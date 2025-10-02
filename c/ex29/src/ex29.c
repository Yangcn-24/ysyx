#include <stdio.h>
#include <ctype.h>
#include "dbg.h"


int print_a_message(const char *msg,int length)
{	
	int i;
    check(msg!=NULL,"Message cannot be NULL");
    check(length>=0,"Length must be non-negative");
    for(i = 0; i<length; i++) {
        printf("%c", msg[i]);
    }
    printf("\n");
    return 0;
error:
	return -1;
}


int uppercase(const char *msg,int length)
{
    int i = 0;
	check(msg!=NULL,"Message cannot be NULL");
	check(length>=0,"Length must be non-negative");
    // BUG: \0 termination problems
    for(i = 0; i<length; i++) {
        printf("%c", toupper(msg[i]));
    }

    printf("\n");
    return 0;
error:
	return -1;
}

int lowercase(const char *msg,int length)
{
    int i = 0;
	check(msg!=NULL,"Message cannot be NULL");
	check(length>=0,"Length must be non-negative");
    // BUG: \0 termination problems
    for(i = 0; i<length; i++) {
        printf("%c", tolower(msg[i]));
    }

    printf("\n");

    return 0;
error:
	return -1;
}

int fail_on_purpose(const char *msg,int length)
{
    return 1;
}
