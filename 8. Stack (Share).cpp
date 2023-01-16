/*
栈的基本操作
InitStack(&S)       //初始化一个空栈
StackEmpty(S)       //判断一个栈是否为空，若为空返回true，否则返回false
Push(&S, x)         //进栈，若栈S未满，则将x加入使之成为新的栈顶
Pop(&s, &x)         //出栈，若栈S非空，则弹出栈顶元素，并用x返回
GetTop(S, &x)       //读栈顶元素，若栈S非空，则用x返回栈顶元素
DestroyStack(&s)    //销毁栈，并释放栈S占用的存储空间
*/
#include <iostream>
using namespace std;

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int top[2];
} ShStack;

void InitStack(ShStack &S) {
    S.top[0] = -1;
    S.top[1] = MaxSize;
}

bool StackEmpty(ShStack S) {
    if(S.top[0] == -1 && S.top[1] == MaxSize)
        return true;
    else
        return false;
}

bool Push(ShStack &S, int i, ElemType x) {
    if(i < 0 || i > 1)
        return false;
    if(S.top[0] == S.top[1] - 1)
        return false;
    switch(i) {
        case 0 :
            S.data[++S.top[0]] = x;
            break;
        case 1 :
            S.data[--S.top[1]] = x;
    }
    return true;
}

bool Pop(ShStack &S, int i, ElemType &x) {
    if(i < 0 || i > 1)
        return false;
    switch(i) {
        case 0 :
            if(S.top[0] == -1)
                return false;
            x = S.data[S.top[0]--];
            break;
        case 1 :
            if(S.top[1] == MaxSize)
                return false;
            x = S.data[S.top[1]++];
    }
    return true;
}