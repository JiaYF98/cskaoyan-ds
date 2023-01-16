#include <iostream>
#include <cstring>
using namespace std;

#define MaxSize 10
struct Stack {
    char data[MaxSize];
    int top;
};

void InitStack(Stack &S) {
    S.top = -1;
}

bool StackEmpty (Stack S) {
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(Stack &S, char b) {
    if(S.top == MaxSize - 1) {
        cout << "超出栈的上限" << endl;
        return false;
    }
    S.data[++S.top] = b;
    return true;
}

bool Pop(Stack &S, char &topelem) {
    if(S.top == -1)
        return false;
    topelem = S.data[S.top--];
    return true;
}

bool BracketCheck(char str[]) {
    Stack s;
    InitStack(s);
    int length = strlen(str);
    char topelem;
    for(int i = 0; i < length; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            if(!Push(s, str[i]))
                return false;
        }
        else {
            if(StackEmpty(s))
                return false;
            Pop(s, topelem);
            if(str[i] == ')' && topelem != '(')
                return false;
            if(str[i] == ']' && topelem != '[')
                return false;
            if(str[i] == '}' && topelem != '{')
                return false;
        }
    }
    return StackEmpty(s);
}

char str[MaxSize];
int main() {
    cin >> str;
    if(BracketCheck(str))
        cout << "true";
    else
        cout << "false";
}