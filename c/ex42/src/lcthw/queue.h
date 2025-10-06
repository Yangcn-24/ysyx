#ifndef lcthw_queue_h
#define lcthw_queue_h
#include<stdlib.h>
#include<lcthw/dbg.h>
typedef struct QueueNode{
	struct QueueNode *next;
	void *value;
} QueueNode;
typedef struct Queue{
	struct QueueNode *peek;
	struct QueueNode *last;
	int count;
} Queue;
#define Queue_peek(A) ((A)->peek!=NULL?(A)->peek->value:NULL)
#define Queue_last(A) ((A)->last!=NULL?(A)->last->value:NULL)
#define Queue_count(A) (A)->count

#define Queue_create() calloc(1,sizeof(Queue))

#define Queue_destroy(A)  QueueNode *node=NULL;\
	QUEUE_FOREACH(A,B){\
		node=B;\
		if(B->next){\
			free(node);\
		}\
	}\
	free(A);
#define Queue_clear() QUEUE_FOREACH(A,B){\
	free(B->value);}
	
#define Queue_send(A,B) QueueNode *node=calloc(1,sizeof(QueueNode));\
	if((A->peek==NULL)&&(A->last==NULL)){\
		node->value=B;\
		A->peek=A->last=node;\
	}\
	else {\
		node->next=A->peek;\
		node->value=B;\
		A->peek=node;\
	}\
	A->count=A->count+1;
//#define Stack_pop(A) A->peek=A-peek->next;\
	A->count=A->count-1;


//#define Stack_print(A) if(A->count=0) printf("NULL\n");\
	else {STACK_FOREACH(A,cur){\
		if(cur!=NULL) printf("%s\n",(char *)cur->value);\
		else printf("NULL\n");}\
		printf("------\n");}

#define QUEUE_FOREACH(A,B) QueueNode *B=NULL;\
	for(B=A->peek;B!=NULL;B=B->next) 

char *Queue_recv(Queue *queue){\
	char *res=queue->last->value;\
	if(queue->count==1){\
		queue->last=queue->peek=NULL;\
	}\
	else {QUEUE_FOREACH(queue,cur)\
		{\
			if(cur->next==queue->last){\
				cur->next=NULL;\
				queue->last=cur;\
			}\
		}\
	}\
	queue->count=queue->count-1;\
	return res;\
}
#endif
