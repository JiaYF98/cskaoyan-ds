/*
队列的基本操作：
InitQueue(&Q)：初始化队列，构造一个空队列Q
DestroyQueue(&Q)：销毁队列。销毁并释放队列Q所占用的内存空间
EnQueue(&Q)：入队，若队列Q未满，将x加入，使之成为新的队尾
DeQueue(&Q, &x)：出队，若队列Q非空，删除队头元素，并用x返回
GetHead(Q, &x)：读队头元素，若队列非空，则将队头元素赋值给x
队列元素个数：(rear - front + MaxSize) % MaxSize
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define MaxSize 50
typedef int ElemType;
struct LinkNode{
    ElemType data;
    LinkNode * next;    
};
struct LinkQueue {
    LinkNode * front, * rear;
};

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    // Q.front = Q.rear = new LinkNode;
    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q) {
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode * s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if(Q.rear == Q.front)
        return false;
    LinkNode * p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}

//不带头结点
// void InitQueue(LinkQueue &Q) {
//     Q.front = Q.rear = NULL;
// }

// bool isEmpty(LinkQueue &Q) {
//     if(Q.front == NULL)
//         return true;
//     else
//         return false;
// }
// void EnQueue(LinkQueue &Q, ElemType x) {
//     LinkNode * s = (LinkNode *)malloc(sizeof(LinkNode));
//     s->data = x;
//     s->next = NULL;
//     if(Q.front == NULL) {
//         Q.front = s;
//         Q.rear = s;
//     }
//     else {
//         Q.rear->next = s;
//         Q.rear = s;
//     }
// }

// bool DeQueue(LinkQueue &Q, ElemType &x) {
//     if(Q.front == NULL)
//         return false;
//     LinkNode * p = Q.front;
//     x = p->data;
//     Q.front = p->next;
//     if(Q.front == Q.rear)
//         Q.front = Q.rear =NULL;
//     free(p);
//     return true;
// }