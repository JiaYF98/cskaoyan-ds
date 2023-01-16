#include <iostream>
using namespace std;

// struct ElemType {
//     int value;
// };

// typedef struct ThreadNode {
//     ElemType data;
//     ThreadNode * lchild, * rchild;
//     int ltag, rtag; //tag == 0,表示指针指向孩子, tag == 1,表示指针指向的是线索
// } ThreadNode, * ThreadTree;

// ThreadNode * pre = nullptr;

// void visit(ThreadNode * q) {
//     if(q->lchild == nullptr) {
//         q->lchild = pre;
//         q->ltag = 1;
//     }
//     if(pre && pre->rchild == nullptr) {
//         pre->rchild = q;
//         pre->rtag = 1;
//     }
//     pre = q;
// }

// //中序线索化
// //中序遍历二叉树，一边遍历一边线索化
// void InThread(ThreadTree T) {
//     if(T) {
//         InThread(T->lchild);
//         visit(T);
//         InThread(T->rchild);
//     }
// }

// //中序线索化二叉树
// void CreatInThread(ThreadTree T) {
//     pre = nullptr;
//     if(T) {
//         InThread(T);
//         if(pre->rchild == nullptr)       //中序遍历最后一个结点一定没有右孩子
//             pre->rtag = 1;
//     }
// }


// //先序线索化
// void PreThread(ThreadTree T) {
//     if(T) {
//         visit(T);
//         if(T->ltag == 0)
//             PreThread(T->lchild);
//         PreThread(T->rchild);
//     }
// }

// //先序线索化二叉树
// void CreatPreThread(ThreadTree T) {
//     pre = nullptr;
//     if(T) {
//         PreThread(T);
//         if(pre->rchild == nullptr)       //先序遍历最后一个结点一定是叶子结点
//             pre->rtag = 1;
//     }
// }

// //后序线索化
// void PostThread(ThreadTree T) {
//     if(T) {
//         PostThread(T->lchild);
//         PostThread(T->rchild);
//         visit(T);
//     }
// }

// //后序线索化二叉树
// void CreatPostThread(ThreadTree T) {
//     pre = nullptr;
//     if(T) {
//         PostThread(T);
//         if(pre->rchild == nullptr)
//             pre->rtag = 1;
//     }
// }


// //中序线索二叉树找中序后继
// //找到以 p 为根的子树中，第一个被中序遍历的结点
// ThreadNode * Fistnode(ThreadNode * p) {
//     //循环找到最左下结点（不一定是叶结点）
//     while(p->ltag == 0)
//         p = p->lchild;
//     return p;
// }

// //在中序线索二叉树中找到结点 p 的后继结点
// ThreadNode * InThreadNextnode(ThreadNode * p) {
//     //右子树最左下结点
//     if(p->rtag == 0)
//         return Fistnode(p->rchild);
//     else
//         return p->rchild;
// }

// //对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
// void Inorder(ThreadTree T) {
//     for(ThreadNode * p = Fistnode(T); p != nullptr; p = InThreadNextnode(p))
//         visit(p);
// }

// //中序线索二叉树找中序前驱
// //找到以 p 为根的子树中，最后一个被中序遍历的结点
// ThreadNode * Lastnode(ThreadNode * p) {
//     //循环找到最右下结点（不一定是叶结点）
//     while(p->rtag == 0)
//         p = p->rchild;
//     return p;
// }

// //在中序线索二叉树中找到结点 p 的前驱结点
// ThreadNode * InThreadPrenode(ThreadNode * p) {
//     //左子树最右下结点
//     if(p->ltag == 0)
//         return Lastnode(p->lchild);
//     else
//         return p->lchild;
// }

// //对中序线索二叉树进行逆向中序遍历
// void RevInorder(ThreadTree T) {
//     for(ThreadNode * p = Lastnode(T); p != nullptr; p = InThreadPrenode(p))
//         visit(p);
// }


// //先序线索二叉树找先序后继
// ThreadNode * PreThreadNextnode(ThreadNode * p) {
//     if(p->rtag == 0) {
//         if(p->lchild)
//             return p->lchild;
//         else
//             return p->rchild;
//     }
//     else
//         return p->rchild;
// }


// //后序线索二叉树找后序前驱
// ThreadNode * PostThreadPrenode(ThreadNode * p) {
//     if(p->ltag == 0) {
//         if(p->rchild)
//             return p->rchild;
//         else
//             return p->lchild;
//     }
//     else
//         return p;
// }

struct ElemType {
    int value;
};

typedef struct ThreadNode {
    ElemType data;
    ThreadNode * lchild, * rchild;
    int ltag, rtag;
} ThreadNode, * ThreadTree;

ThreadNode * pre = nullptr;

void visit(ThreadNode * q) {
    if(q->lchild == nullptr) {
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre && pre->rchild == nullptr) {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

void InThread(ThreadTree T) {
    ThreadTree(T->lchild);
    visit(T);
    ThreadTree(T->rchild);
}

void CreatInThread(ThreadTree T) {
    pre = nullptr;
    if(T) {
        InThread(T);
        pre->rtag = 1;
    }
}

void PreThread(ThreadTree T) {
    visit(T);
    if(T->ltag == 0)
        PreThread(T->lchild);
    PreThread(T->rchild);
}

void CreatPreThread(ThreadTree T) {
    pre = nullptr;
    if(T) {
        PreThread(T);
        pre->rtag = 1;
    }
}

void PostThread(ThreadTree T) {
    PostThread(T->lchild);
    PostThread(T->rchild);
    visit(T);
}

void CreatPostThread(ThreadTree T) {
    pre = nullptr;
    if(T) {
        PostThread(T);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

ThreadNode * Fistnode(ThreadNode * p) {
    while(p->ltag == 0)
        p = p->lchild;
    return p;
}

ThreadNode * InThreadNextnode(ThreadNode * p) {
    if(p->rtag = 0)
        return Fistnode(p->rchild);
    return p->rchild;
}

void Inorder(ThreadTree T) {
    for(ThreadNode * p = Fistnode(T); p != nullptr; p = InThreadNextnode(p))
        visit(p);
}

ThreadNode * Lastnode(ThreadNode * p) {
    while(p->rtag == 0)
        p = p->rchild;
    return p;
}

ThreadNode * InThreadPrenode(ThreadNode * p) {
    if(p->ltag == 0)
        return Lastnode(p->lchild);
    else
        return p->lchild;
}

void RevInorder(ThreadTree T) {
    for(ThreadNode * p = Lastnode(T); p != nullptr; p = InThreadPrenode(p))
        visit(p);
}

