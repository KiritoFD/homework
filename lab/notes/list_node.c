#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体定义
struct node {
    int data;
    struct node *next;
};

// 创建新节点
struct node *createNode(int data) {
    // 分配节点内存空间
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    // 初始化节点数据和指针
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入节点
void insertAtHead(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (newNode!= NULL) {
        newNode->next = *head;
        *head = newNode;
    }
}

// 在链表尾部插入节点
void insertAtTail(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 遍历链表并打印节点数据
void traverseList(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 删除链表中指定值的节点
void deleteNode(struct node **head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct node *prev = *head;
    struct node *curr = (*head)->next;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr!= NULL) {
        prev->next = curr->next;
        free(curr);
    }
}

// 释放链表内存
void freeList(struct node *head) {
    struct node *temp;
    while (head!= NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}