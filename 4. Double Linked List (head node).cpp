#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    DNode * prior;
    DNode * next;
} DNode, * DLinkList;

bool InitDLinkList(DLinkList &L) {
    L = (DLinkList)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool InsertNextDNode(DNode * p, ElemType e) {
    if(p == NULL)
        return false;
    DNode * s = (DNode *)malloc(sizeof(DNode));
    if(s == NULL)
        return false;
    s->data = e;
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextDNode(DNode * p) {
    if(p == NULL || p->next == NULL)
        return false;
    DNode * q = p->next;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}

