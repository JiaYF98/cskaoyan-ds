// #include <iostream>
// using namespace std;

// struct Stack {
//     long long data[1010];
//     long long top;
//     long long location;
//     long long sum[1010];
// };

// void InitStack(Stack &S) {
//     S.top = 0;
//     S.location = 0;
// }

// void Insert(Stack &S, long long x) {
//     for(int i = S.top; i > S.location; i--) {
//         S.data[i] = S.data[i - 1];
//         S.sum[i] = S.sum[i - 1] + x;
//     }
//     S.data[S.location] = x;
//     if(S.location > 0)
//         S.sum[S.location] = S.sum[S.location - 1] + x;
//     else
//         S.sum[S.location] = x;
//     S.location++;
//     S.top++;
// }

// void Delete(Stack &S) {
//     if(S.location != 0) {
//         long long x = S.data[--S.location];
//         for(int i = S.location; i < S.top - 1; i++) {
//             S.data[i] = S.data[i + 1];
//             S.sum[i] = S.sum[i + 1] - x;
//         }
//         S.top--;
//     }
// }

// long long getMax(Stack S, long long k) {
//     if(S.location == 0)
//         return 0;
//     long long max = S.sum[0];
//     for(int i = 0; i < k && i < S.location; i++) {
//         if(S.sum[i] > max)
//             max = S.sum[i];
//     }
//     return max;
// }

// void operate(char op, Stack &S) {
//     switch(op) {
//         case 'I' :
//             long long x;
//             cin >> x;
//             Insert(S, x);
//             break;
//         case 'D' :
//             Delete(S);
//             break;
//         case 'L' :
//             if(S.location != 0)
//                 S.location--;
//             break;
//         case 'R' :
//             if(S.location != S.top)
//                 S.location++;
//             break;
//         case 'Q' :
//             long long k;
//             cin >> k;
//             cout << getMax(S, k) << endl;
//             break;
//     }
// }

// int main() {
//     Stack S;
//     InitStack(S);
//     int N;
//     cin >> N;
//     char op;
//     for(int i = 0; i < N; i++) {
//         cin >> op;
//         operate(op, S);
//     }
//     return 0;
// }

// #include <iostream>
// #include <stack>
// #include <algorithm>
// using namespace std;
// #define MAX_N 1000
// long long sum[MAX_N + 5];
// long long f[MAX_N + 5];
// int main() {
//     int n;
//     f[0] = 0x8000000000000000LL;
//     stack<long long> s1, s2;
//     char op;
//     cin >> n;
//     while(n--) {
//         cin >> op;
//         switch (op) {
//             case 'I' :
//                 long long x;
//                 cin >> x;
//                 s1.push(x);
//                 int index = s1.size();
//                 sum[index] = sum[index - 1] + x;
//                 f[index] = max(f[index - 1], sum[index]);
//                 break;
//             case 'D' :
//                 if(!s1.empty())
//                     s1.pop();
//                 break;
//             case 'L' :
//                 if(s1.empty())
//                     break;
//                 s2.push(s1.top());
//                 s1.pop();
//                 break;
//             case 'R' :
//                 if(s2.empty())
//                     break;
//                 s1.push(s2.top());
//                 s2.pop();
//                 int ind = s1.size();
//                 sum[ind] = sum[ind - 1] + x;
//                 f[ind] = max(f[ind - 1], sum[ind]);
//                 break;
//             case 'Q' :
//                 int k;
//                 cin >> k;
//                 cout << f[k] << endl;
//                 break;
//         }
//     }
// }


#include <iostream>
#include <string>
using namespace std;

typedef struct BTNode {
    int weight;
    BTNode * left, * right;
} BTNode, * BTree;

void Order(BTree T, int &WPL, int deep) {
    if(T == nullptr)
        return;
    else if(T->left == nullptr && T->right == nullptr)
        WPL += deep * T->weight;
    else {
        Order(T->left, WPL, deep + 1);
        Order(T->right, WPL, deep + 1);
    }
}

int GetWPL(BTree T) {
    int WPL = 0;
    Order(T, WPL, 0);
    return WPL;
}
