#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElemType;
struct Node {
    ElemType data;
    int next;
};

typedef struct {
    ElemType data;
    int next;
} SLinkList[MaxSize];

void testSLinkList() {
    Node a[MaxSize];
}