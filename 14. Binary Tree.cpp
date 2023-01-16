#include <iostream>
using namespace std;

//顺序存储
// #define MaxSize 100
// typedef int ElemType;
// struct TreeNode {
//     ElemType value; //结点中的数据元素
//     bool isEmpty;   //结点是否为空
// } t[MaxSize];   //可以让第一个位置空缺，保证数组下标和结点编号一致

//初始化时所有结点标记为空
// for(int i = 0; i < MaxSize; i++) {
//     t[i].isEmpty = true;
// }

// 链式存储
struct ElemType {
    int value;
};
typedef struct BiTNode {
    ElemType data;      //数据域
    BiTNode * lchild, * rchild; //左、右孩子指针
    BiTNode * parent;
} BiTNode, * BiTree;

void InsertRootNode(BiTree root) {
    root = new BiTNode;
    root->data.value = 1;
    root->lchild = nullptr;
    root->rchild = nullptr; 
}

void InserNewNode(BiTree root) {
    BiTNode * p = new BiTNode;
    p->data.value = 2;
    p->lchild = nullptr;
    p->rchild = nullptr;
    root->lchild = p;
}

void vist(BiTNode * T) {
    cout << T->data.value << endl;
}

//先序遍历
void PreOrder(BiTree T) {
    if(T != nullptr) {
        vist(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T) {
    if(T != nullptr) {
        InOrder(T->lchild);
        vist(T);
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T) {
    if(T != nullptr) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        vist(T);
    }
}

//求树的深度
int treeDepth(BiTree T) {
    if(T == nullptr)
        return 0;
    else {
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        return l > r ? l + 1 : r + 1;
    }
}

struct LinkNode {
    BiTNode * data;
    LinkNode * next;
};

struct LinkQueue {
    LinkNode * front, * rear;
};

void InitQueue(LinkQueue Q) {
    Q.rear = Q.front = new LinkNode;
    Q.front->next = nullptr;
}

void EnQueue(LinkQueue &Q, BiTree p) {
    LinkNode * s = new LinkNode;
    s->data = p;
    s->next = Q.rear->next;
    Q.rear->next = s;
    Q.rear = s;
}   

BiTNode * DeQueue(LinkQueue &Q) {
    LinkNode * q = Q.front->next;
    BiTNode * p = new BiTNode;
    p = q->data;
    Q.front->next = q->next;
    if(q == Q.rear)
        Q.rear = Q.front;
    delete(q);
    return p;
}

bool IsEmpty(LinkQueue Q) {
    if(Q.rear == Q.front)
        return false;
    else
        return true;
}

//层次遍历
void LevelOrder(BiTree T) {
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, T);
    BiTree p;
    while(!IsEmpty(Q)) {
        p = DeQueue(Q);
        vist(p);
        if(p->lchild)
            EnQueue(Q, p->lchild);
        if(p->rchild)
            EnQueue(Q, p->rchild);
    }
}
