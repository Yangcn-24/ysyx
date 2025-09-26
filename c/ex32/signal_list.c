#include <stdio.h>
#include <stdlib.h>
// 定义链表节点结构体
struct ListNode {
    int data;
    struct ListNode* next;
};
// 创建链表
struct ListNode* createList() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    return head;
}
// 在链表尾部插入一个节点
void insertNode(struct ListNode* head, int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    struct ListNode* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}
// 删除一个节点
void deleteNode(struct ListNode* head, int data) {
    struct ListNode* p = head->next;
    struct ListNode* pre = head;
    while (p != NULL) {
        if (p->data == data) {
            pre->next = p->next;
            free(p);
            return;
        }
        pre = p;
        p = p->next;
    }
}
// 遍历链表
void traverseList(struct ListNode* head) {
    struct ListNode* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main() {
    // 创建链表
    struct ListNode* head = createList();
   
    // 在链表尾部插入节点
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
   
    // 遍历链表
    traverseList(head);
   
    // 删除节点
    deleteNode(head, 3);
   
    // 遍历链表
    traverseList(head);
   
    return 0;
}