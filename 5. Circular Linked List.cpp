#include <iostream>
using namespace std;

typedef int ElemType; 
typedef struct LNode {
    ElemType data;
    LNode * next;
} LNode, * LinkList;

bool InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = L;
    return true;
}

bool Empty(LinkList L) {
    if(L->next == L)
        return true;
    else
        return false;
}

bool isTail(LinkList L, LNode * p) {
    if(p->next == L)
        return true;
    else
        return false;
}

typedef struct DNode {
    ElemType data;
    DNode * prior;
    DNode * next;
} DNode, * DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DLinkList)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}

bool Empty(DLinkList L) {
    if(L->next == L)
        return true;
    else
        return false;
}

bool isTail(DLinkList L, DNode * p) {
    if(p->next == L)
        return true;
    else
        return false;
}

bool InsertNextDNode(DNode * p,  DNode * s) {
    if(p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode * p) {
    if(p == NULL)
        return false;
    DNode * q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}