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
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
    // int size;
    // int tag;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
    // Q.size = 0;
    // Q.tag = 0;
}


bool QueueEmpty(SqQueue Q) {
    if(Q.rear == Q.front)
    // if(Q.size == 0)
    // if(Q.rear == Q.front && tag == 0)
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if(Q.front == (Q.rear + 1) % MaxSize)
    // if(Q.size == MaxSize)
    // if(Q.rear == Q.front && Q.tag == 1)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    // Q.size++;
    // Q.tag = 1;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if(QueueEmpty)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    // Q.size--;
    // Q.tag = 0;
    return true;
}

/*
若 rear 指向队尾元素
入队操作：
Q.rear = (Q.rear + 1) % MaxSize;
Q.data[Q.rear] = x;
出队操作：
x = Q.data[Q.front];
Q.front = (Q.front + 1) % MaxSize;
判空：
(Q.rear + 1) % MaxSize = Q.front;
判满：
(Q.rear + 2) % MaxSize = Q.front;
*/