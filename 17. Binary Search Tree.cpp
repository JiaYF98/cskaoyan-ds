#include <iostream>
using namespace std;

typedef struct BSTNode {
    int key;
    BSTNode * lchild, * rchild;
} BSTNode, * BSTree;

//在二叉排序树中查找值为 key 的结点，最坏空间复杂度 O(1)
BSTNode * BST_Search(BSTree T, int key) {
    while(T != nullptr && key != T->key) {
        if(key < T->key)  T = T->lchild;
        else  T = T->rchild;
    }
    return T;
}

//在二叉排序树中查找值为 key 的结点（递归实现），最坏空间复杂度 O(h)
BSTNode * BSTSearch(BSTree T, int key) {
    if(T == nullptr)
        return nullptr;     //查找失败
    if(key == T->key)
        return T;           //查找成功
    else if(key < T->key)
        return BSTSearch(T->lchild, key);
    else if(key > T->key)
        return BSTSearch(T->rchild, key);
}

//在二叉排序树插入关键字为 k 的新结点（递归实现）
int BST_Insert(BSTree &T, int k) {
    if(T == nullptr) {
        T = new BSTNode;
        T->key = k;
        T->lchild = T->rchild = nullptr;
        return 1;
    }
    else if(k == T->key)
        return 0;
    else if(k < T->key)
        return BST_Insert(T->lchild, k);
    else
        return BST_Insert(T->rchild, k);
}

//二叉树的构造
//按照序列 str[] 中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T, int str[], int n) {
    T = nullptr;
    int i = 0;
    while(i < n) {
        BST_Insert(T, str[i]);
        i++;
    }
}