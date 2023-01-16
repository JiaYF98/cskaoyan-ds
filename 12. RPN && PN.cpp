#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 50
typedef char ElemType;
struct Stack {
    ElemType data[MaxSize];
    int top;
};

void InitStack(Stack &S) {
    S.top = -1;
}

bool isOperate(char str) {
    if(str == '+' || str == '-' || str == '*' || str == '/')
        return true;
    else
        return false;
}

bool isPush_RPN(char c1, char c2) {
    if((c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-') || c2 == '(')
        return true;
    else
        return false;
}

bool isPush_PN(char c1, char c2) {
    if((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/'))    //当前运算符的优先级小于栈顶运算符的优先级时不能直接压入栈中
        return false;
    else
        return true;
}

bool Push(Stack &S, ElemType x) {
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

ElemType Pop(Stack &S) {
    return S.data[S.top--];
}

bool StackEmpty(Stack S) {
    if(S.top == -1)
        return true;
    else
        return false;
}

ElemType GetTop(Stack S) {
    return S.data[S.top];
}

void RPN(char str[]) {
    Stack S;
    InitStack(S);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] == '(')
            Push(S, str[i]);
        else if(str[i] == ')') {
            while(GetTop(S) != '(')
                cout << Pop(S);
            S.top--;                    //跳过左括号
        }
        else if(isOperate(str[i])) {
            if(StackEmpty(S) || isPush_RPN(str[i], GetTop(S))) {    //如果栈为空或者栈顶运算符的优先级低于当前运算符，将该运算符压入栈中
                Push(S, str[i]);
            }
            else{
                while(!StackEmpty(S) && !isPush_RPN(str[i], GetTop(S)))
                    cout << Pop(S);
                Push(S, str[i]);        //栈中比当前运算符优先级高或者相等的运算符都出栈后，将该运算符压入栈中
            }
        }
        else
            cout << str[i];
    }
    while(!StackEmpty(S))
        cout << Pop(S);
}

void PN(char str[]) {
    Stack S1, S2;
    InitStack(S1);
    InitStack(S2);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {     //前缀表达式从后向前遍历
        if(str[i] == ')')
            Push(S1, str[i]);
        else if(str[i] == '(') {
            while(GetTop(S1) != ')')
                Push(S2, Pop(S1));
            S1.top--;
        }
        else if(isOperate(str[i])) {
            if(StackEmpty(S1) || isPush_PN(str[i], GetTop(S1)))
                Push(S1, str[i]);
            else {
                while(!StackEmpty(S1) && !isPush_PN(str[i], GetTop(S1)))    //当 S1 非空，且当前运算符不能压入栈中时
                    Push(S2, Pop(S1));                                      //弹出 S1 顶端运算符并压入 S2 中
                Push(S1, str[i]);                                           //将当前运算符压入栈中
            }
        }
        else
            Push(S2, str[i]);
    }
    while(!StackEmpty(S1))
        Push(S2, Pop(S1));
    while(!StackEmpty(S2))
        cout << Pop(S2);
}

int main() {
    char str[MaxSize];
    cin >> str;
    RPN(str);
    cout << endl;
    PN(str);
    return 0;
}