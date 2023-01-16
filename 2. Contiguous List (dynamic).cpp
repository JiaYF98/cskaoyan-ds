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
using namespace std;

const int InitSize = 50;
struct SeqList {
    int * data;
    int length;
    int MaxSize;
};

void InitList(SeqList &L) {                             //初始化表
    // L.data = (int *)malloc(sizeof(int) * InitSize);
    L.data = new int[InitSize];
    L.length = 0;
    L.MaxSize = InitSize;
}

bool ListInsert(SeqList &L, int location, int element) {
    if(location < 1 || location > L.length + 1)
        return false;
    if(L.length >= L.MaxSize)
        return false;
    for(int i = L.length; i >= location; i--)
        L.data[i] = L.data[i - 1];
    L.data[location - 1] = element;
    L.length++;
    return true;
}

void IncreaseSize(SeqList &L, int len) {                //增加表长
    int * p = L.data;
    // L.data = (int *)malloc(sizeof(int) * (L.MaxSize + len));
    L.data = new int[L.MaxSize + len];
    for(int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize += len;
    free(p);
}

int Length(SeqList L) {
    return L.length;
}

void Print(SeqList L) {
    for(int i = 0; i < L.length; i++) {
        if(i)
            cout << " " << L.data[i];
        else
            cout << L.data[i];
    }
}

int main() {
    SeqList L;
    InitList(L);
    int location, element;
    for(int i = 0; i < 5; i++) {
        cin >> location >> element;
        ListInsert(L, location, element);
    }
    cout << L.MaxSize << endl;
    Print(L);
    int len;
    cin >> len;
    IncreaseSize(L, len);
    for(int i = 0; i < 3; i++) {
        cin >> location >> element;
        ListInsert(L, location, element);
    }
    cout << L.MaxSize << endl;
    Print(L);
    return 0;
}