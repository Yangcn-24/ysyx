#ifndef lcthw_stack_h
#define lcthw_stack_h
#include<stdlib.h>

typedef struct StackNode{
	struct StackNode *next;
	void *value;
} StackNode;
typedef struct Stack{
	struct StackNode *peek;
	int count;
} Stack;
#define Stack_peek(A) ((A)->peek!=NULL?(A)->peek->value:NULL)

#define Stack_count(A) (A)->count

#define Stack_create() calloc(1,sizeof(Stack))

#define Stack_destroy(A)  StackNode *node=NULL;\
	STACK_FOREACH(A,B){\
		node=B;\
		if(B->next){\
			free(node);\
		}\
	}\
	free(A);
#define Stack_clear() STACK_FOREACH(A,B){\
	free(B->value);}
	
#define Stack_push(A,B) StackNode *node=calloc(1,sizeof(StackNode));\
	node->next=A->peek;\
	node->value=B;\
	A->peek=node;\
	A->count=A->count+1;

//#define Stack_pop(A) A->peek=A-peek->next;\
	A->count=A->count-1;
char *Stack_pop(Stack *stack){\
	char *val=stack->peek->value;\
	stack->peek=stack->peek->next;\
	stack->count=stack->count-1;\
	return val;
}

//#define Stack_print(A) if(A->count=0) printf("NULL\n");\
	else {STACK_FOREACH(A,cur){\
		if(cur!=NULL) printf("%s\n",(char *)cur->value);\
		else printf("NULL\n");}\
		printf("------\n");}

#define STACK_FOREACH(A,B) StackNode *B=NULL;\
	for(B=A->peek;B!=NULL;B=B->next) 
#endif
