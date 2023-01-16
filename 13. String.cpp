/*
串的基本操作：
StrAssign(&T, chars)：赋值操作。把串 T 赋值为 chars
StrCopy(&T, S)：复制操作。由串 S 复制得到串 T
StrEmpty(S)：判空操作。若 S 为空串，则返回 TRUE，否则返回 FALSE
StrCompare(S, T)：比较操作。若 S > T，则返回值 > 0；若 S = T，则返回值 = 0；若 S < T，则返回值 < 0
StrLength(S)：求串长。返回串 S 的元素个数
SubString(&Sub, S, pos, len)：求子串。用 Sub 返回串 S 的第 pos 个字符起长度为 len 的字串
Concat(&T, S1, S2)：串连接。用 T 返回由 S1 和 S2 连接而成的新串
Index(S, T)：定位操作。若主串 S 中存在与串 T 值相同的子串，则返回它在主串 S 中第一次出现的位置；否则函数值为 0
ClearString(&S)：清空操作。将 S 清为空串
DestroyString(&S)：销毁串。将串 S 销毁
*/

#include <iostream>
using namespace std;

//定长顺序存储表示
#define MAXLEN 255
struct SString {
    char ch[MAXLEN];
    int length;
};

//堆分配存储
struct HString {
    char * ch;
    int length;
};

//串的链式存储
typedef struct StringNode {
    char ch;    //每个结点存 1 个字符
    // char ch[4]; //每个结点存多个字符
    StringNode * next;
} StringNode, * String;

bool SubString(SString &Sub, SString S, int pos, int len) {
    //子串范围越界
    if(pos + len -1 > S.length)
        return false;
    for(int i = pos; i < pos + len; i++)
        Sub.ch[i - pos + 1] = S.ch[i];  //ch[0]废弃不用
    Sub.length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for(int i = 1; i <= S.length && i <= T.length; i++) {
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

int StrLength(SString S) {
    return S.length;
}

int Index(SString S, SString T) {   //定位操作
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString Sub;    //用于暂存子串
    while(i <= n - m + 1) {
        SubString(Sub, S, i, m);
        if(StrCompare(Sub, T) != 0) i++;
        else return i;  //返回子串在主串中的位置
    }
    return 0;   //S 中不存在与 T 相等的子串
}

//朴素模式匹配算法
//设主串长度为 n, 模式串长度为 m, 则最坏时间复杂度为 O(mn), 最好时间复杂度为 O(n)
int index(SString S, SString T) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if(S.ch[i] == T.ch[i])
            i++, j++;   //继续比较后继字符
        else {
            i = i - j + 2;
            j = 1;      //指针后退重新开始匹配
        }
    }
    if(j > T.length)
        return i - T.length;
    else return 0;
}

// KMP算法
// 设主串长度为 n, 模式串长度为 m, 则最坏时间复杂度为 O(m + n)
void get_next(SString T, int next[]) {
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            i++, j++;
            next[i] = j;
        }
        else
            j = next[i];
    }
}

int KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j])
            i++, j++;
        else
            j = next[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}

//改进KMP算法
void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.length) {
        if(j == 0 || T.ch[i] == T.ch[j]) {
            i++, j++;
            if(T.ch[i] != T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}

int KMP(SString S, SString T, int nextval[]) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if(j == 0 || S.ch[i] == T.ch[j])
            i++, j++;
        else
            j = nextval[j];
    }
    if(j > T.length)
        return i - T.length;
    else
        return 0;
}