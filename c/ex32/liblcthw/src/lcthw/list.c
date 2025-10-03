#include <lcthw/list.h>
#include <lcthw/dbg.h>

List *List_create()
{
    return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}


void List_clear(List *list)
{
    LIST_FOREACH(list, first, next, cur) {
        free(cur->value);
    }
}


void List_clear_destroy(List *list)
{
    List_clear(list);
    List_destroy(list);
}


void List_push(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->last == NULL) {
        list->first = node;
        list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }

    list->count++;

error:
    return;
}

void *List_pop(List *list)
{
    ListNode *node = list->last;
    return node != NULL ? List_remove(list, node) : NULL;
}

void List_unshift(List *list, void *value)
{
    ListNode *node = calloc(1, sizeof(ListNode));
    check_mem(node);

    node->value = value;

    if(list->first == NULL) {
        list->first = node;
        list->last = node;
    } else {
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
    }

    list->count++;

error:
    return;
}

void *List_shift(List *list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}

void *List_remove(List *list, ListNode *node)
{
    void *result = NULL;

    check(list->first && list->last, "List is empty.");
    check(node, "node can't be NULL");

    if(node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if(node == list->first) {
        list->first = node->next;
        check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
        list->last->next = NULL;
    } else {
        ListNode *after = node->next;
        ListNode *before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->count--;
    result = node->value;
    free(node);

error:
    return result;
}
List *List_copy(List *list)
{
	check(list!=NULL,"List cannot be NULL");
	List *result=List_create();
	check_mem(result);
	LIST_FOREACH(list, first, next, cur){
		List_push(result, cur->value);
	}
	return result;
error:
	if(result!=NULL)
		List_clear_destroy(result);
	return NULL;
	
}

List *List_link(List *list1,List *list2)
{
	check(list1!=NULL && list2!=NULL, "Lists cannot be NULL");
	List *result=List_create();
	check_mem(result);
	{
	LIST_FOREACH(list1, first, next, cur1){
		List_push(result, cur1->value);
	}
	}
	{
	LIST_FOREACH(list2, first, next, cur2){
		List_push(result, cur2->value);
	}
	}
	List_destroy(list1);
	List_destroy(list2);
	return result;
error:
	if(result)
		List_clear_destroy(result);
	return NULL;
}

List *List_break(List *list,int index)
{
	check(list!=NULL,"List cannot be NULL");
	check(index>0&&index<list->count,"Invalid break index");
	List *list1=List_create();
	check_mem(list1);
	List *list2=List_create();
	check_mem(list2);
	int i=0; 
	LIST_FOREACH(list, first, next, cur){
		if(i<index) 
			List_push(list1, cur->value);
		else 
			List_push(list2, cur->value);
		i++;
	}
	check(list1!=NULL,"list1 is NULL");
	check(list2!=NULL,"list2 is NULL");
	check((list1->count==index)&&(list2->count==list->count-index),"Fail to break");
	
	ListNode *cur_node=list->first;
	while(cur_node!=NULL){
		ListNode *next_node=cur_node->next;
		free(cur_node);
		cur_node=next_node;
	}
	list->first=list1->first;
	list->last=list1->last;
	list->count=list1->count;
	free(list1);
	return list2;
error:
	if(list1!=NULL)
		List_clear_destroy(list1);
	if(list2!=NULL)
		List_clear_destroy(list2);
	return NULL;
}

void List_print(List *list)
{
	if(list==NULL){
		printf("List if NULL\n");
	}
	printf("count : %d\n",list->count);
	LIST_FOREACH(list, first, next, cur){
		if(cur->value==NULL)
			printf("(null)");
		else
			printf("%s\n",(char*)(cur->value));
	}
	printf("-----\n");
}
