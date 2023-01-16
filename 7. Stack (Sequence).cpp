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
    int top;
} SqStack;

// void InitStack(SqStack &S) {            //初始化空栈
//     S.top = -1;
// }

// bool StackEmpty(SqStack S) {            //判断栈是否为空
//     if(S.top == -1)
//         return true;
//     else
//         return false;
// }

// bool Push(SqStack &S, ElemType x) {     //进栈
//     if(S.top == MaxSize - 1)
//         return false;
//     else
//         S.data[++S.top] = x;
//     return true;
// }

// bool Pop(SqStack &S, ElemType &x) {     //出栈
//     if(S.top == -1)
//         return false;
//     else
//         x = S.data[S.top--];
// }

// bool GetTop(SqStack S, ElemType &x) {   //读栈顶元素
//     if(S.top == -1)
//         return false;
//     else
//         x = S.data[S.top];
//         return true;
// }

void InitStack(SqStack &S) {
    S.top = 0;
}

bool StackEmpty(SqStack S) {
    if(S.top == 0)
        return true;
    else
        return false;
}

bool Push(SqStack &S, ElemType x) {
    if(S.top == MaxSize - 1)
        return false;
    else
        S.data[S.top++] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if(!S.top)
        return false;
    else
        x = S.data[--S.top];
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if(!S.top)
        return false;
    else
        x = S.data[--S.top];
    return false;
}