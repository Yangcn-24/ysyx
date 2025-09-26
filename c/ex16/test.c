#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
struct Person{
    char *name;
    int age;
    int height;
    int weight;
};
struct Person Person_create(char *name,int age,int height,int weight)
{
	struct Person who;
    who.name=name;
    who.age=age;
    who.height=height;
    who.weight=weight;
    return who;
}

void Person_print(struct Person who)
{
    printf("%s is at memory location %p:\n",who.name,&who);
    printf("Name:%s\n",who.name);
    printf("\tAge\t:\t%d\n",who.age);
    printf("\tHeight\t:\t%d\n",who.height);
    printf("\tWeight\t:\t%d\n",who.weight);
}
int main()
{
    struct Person Joe=Person_create("Joe Alex",32,64,140);
    struct Person Frank=Person_create("Frank Blank",20,72,180);
    Person_print(Joe);
    Person_print(Frank);
    Joe.age+=20;
    Person_print(Joe);
    return 0;
}

