#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100
typedef int ElemType;

// 双亲表示法（顺序存储）
typedef struct {
    ElemType data;
    int parent;
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;

// 孩子表示法（顺序+链式存储）
struct CTNode {
    int child;
    struct CTNode * next;
};
typedef struct {
    ElemType data;
    struct CTNode * fistChild;
} CTBox;
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n, r;   //结点数和根的位置
} CTree;

//孩子兄弟表示法（链式存储）
typedef struct CSNode {
    ElemType data;      //数据域
    CSNode * firstchild, * nextsibling;     //第一个孩子和右兄弟指针
} CSNode, * CSTree;

