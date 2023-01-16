/*
线性表的基本操作：
InitList(&L)            //初始化表
DestroyList(&L)         //销毁链表
ListInsert(&L, i, e)    //插入操作
ListDelete(&L, i, &e)   //删除操作
LocateElem(L, e)        //按值查找操作
GetElem(L, i)           //按位查找操作
length(L)               //求表长
PrintList(L)            //输出操作
Empty(L)                //判空操作
*/
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;
typedef struct LNode {
    ElemType data;
    LNode * next;
} LNode, * LinkList;


/*************************链表的基本操作*************************/

//初始化链表
bool InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    return true;
}

void PrintLinkList(LinkList L) {
    LNode * p = L;
    p = p->next;
    if(p == NULL)
        cout << "The LinkList is empty!" << endl;
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int Length(LinkList L) {
    LNode * p = L;
    int len = 0;
    while(p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}


/*************************链表的查找操作*************************/

//按位查找，返回第 i 个元素（带头结点）
LNode * GetElem(LinkList L, int location) {
    if(location < 0)
        return NULL;
    LNode * p = L;
    int i = 0;
    while(p != NULL && i < location) {
        p = p->next;
        i++;
    }
    return p;
}

//王道书版本按位查找
// LNode * GetElem(LinkList L, int location) {
//     if(location < 0)
//         return NULL;
//     if(location == 0)
//         return L;
//     LNode * p = L->next;
//     int i = 1;
//     while(p != NULL && i < location) {
//         p = p->next;
//         i++;
//     }
//     return p;
// }

//按值查找
LNode * LocateElem(LinkList L, ElemType element) {
    LNode * p = L->next;
    while(p != NULL && p->data != element)
        p = p->next;
    return p;
}


/*************************结点的插入操作*************************/

//在指定结点的后面插入结点
bool InserNextNode(LNode * p, ElemType element) {
    if(p == NULL)       // i 值不合法
        return false;
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    p->next = s;        //将结点 s 连到 p 之后
    s->data = element;
    return true;        //插入成功
}

//已知头结点，从头开始插入，最坏/平均时间复杂度为 O(n)
bool ListInsert(LinkList &L, int location, ElemType element) {
    return InserNextNode(GetElem(L, location - 1), element);
}

//指定结点的前插操作, 时间复杂度O(1)
bool InsertNode(LNode * p, ElemType element) { 
    if(p == NULL)
        return false;
    LNode * s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)
        return false;
    s->next = p->next;
    s->data = p->data;
    p->next = s;
    p->data = element;
    return true;
}

//指定结点的前插操作的王道书写法
bool InsertNode(LNode * p, LNode * s) {
    if(p == NULL || s == NULL)
        return false;
    ElemType temp = s->data;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = temp;
    return true;
}


/*************************结点的删除操作*************************/

//删除指定结点的下一结点
bool DeleteNextNode(LNode * p, ElemType &element) {
    if(p == NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode * q = p->next;
    p->next = q->next;
    element = q->data;
    // element = p->next->data;
    // p->next = p->next->next;
    free(q);
    cout << "The element being deleted is " << element;
    return true;
}

//按位序删除（带头结点）。时间复杂度为O(n)
bool ListDelete(LinkList &L, int location, ElemType &element) {
    return DeleteNextNode(GetElem(L, location - 1), element);
}

//删除指定位置的结点。时间复杂度为 O(1)；有局限性，如果 p 是最后一个结点，那只能从表头开始依次寻找 p 的前驱结点，时间复杂度为 O(n)
bool DeleteNode(LNode * p) {
    if(p == NULL)
        return false;
    LNode * q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}


/*************************链表的建立操作*************************/
//尾插法建立单链表，时间复杂度 O(n)
LinkList List_TailInsert(LinkList &L) {
    ElemType x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode * s, * r = L;     //r 为表尾指针
    cin >> x;               //输入结点的值
    while(x != 9999) {      //输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;              //r 指向新的表尾结点
        cin >> x;
    }
    r->next = NULL;         //尾结点指针置空
    return L;
}

//头插法建立单链表，时间复杂度 O(n)
LinkList List_HeadInsert(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode * s;
    ElemType x;
    cin >> x;
    while(x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

int main() {
    return 0;
}