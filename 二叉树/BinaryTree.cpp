//
// Created by yzm-dev on 2022/5/23.
//

#include <iostream>

using namespace std;

//二叉树定义
typedef struct BTNode {
    char data;
    struct BTNode *lchild, *rchild;//左右孩子
} BTNode, *BiTree;

//先序递归创建二叉树 如: ABC##DE##F##GH###
void CreateBiTree(BiTree &T) {
    char ch;
    if ((ch = getchar()) == '#')T = nullptr;//其中getchar（）为逐个读入标准库函数
    else {
        T = new BTNode;//产生新的子树
        T->data = ch;//由getchar（）逐个读入来
        CreateBiTree(T->lchild);//递归创建左子树
        CreateBiTree(T->rchild);//递归创建右子树
    }
}

void Visit(BTNode *node) {
    if (node) { //当结点不为空的时候执行
        cout << node->data;
    }
}

//先序递归遍历二叉树
void PreOrder(BTNode *node) {
    if (node) {
        Visit(node);
        PreOrder(node->lchild);
        PreOrder(node->rchild);
    }
}

//中序遍历二叉树
void InOrder(BTNode *node) {
    if (node) {
        InOrder(node->lchild);//中序遍历左子树
        Visit(node);
        InOrder(node->rchild);//中序遍历右子树
    }
}

//后序递归遍历二叉树
void PostOrder(BTNode *node) {
    if (node) {
        PostOrder(node->lchild);//后序递归遍历左子树
        PostOrder(node->rchild);//后序递归遍历右子树
        Visit(node);
    }
}

//层序遍历
void LevelOrder(BTNode *node) {
    int front = 0, rear = 0;
    int QueMaxSize = 30;//循环队列最大长度
    BTNode *queue[QueMaxSize];
    BTNode *p;
    if (node) { // 非空树
        queue[rear] = node; //根节点入队
        rear = (rear + 1) % QueMaxSize;
        while (rear != front) { // 当前队列不为空
            p = queue[front];
            front = (front + 1) % QueMaxSize;
            Visit(p);
            if (p->lchild != nullptr) { //结点左孩子不为空入队
                queue[rear] = p->lchild;
                rear = (rear + 1) % QueMaxSize;
            }
            if (p->rchild != nullptr) { //结点右孩子不为空入队
                queue[rear] = p->rchild;
                rear = (rear + 1) % QueMaxSize;
            }
        }
    }
}

int main() {
    cout << "创建一颗树，用“#”表示空树: ";
    BiTree tree;
    CreateBiTree(tree); //先序递归创建二叉树 如: ABC##DE##F##GH###
    cout << "先序递归遍历：";//先序递归遍历：ABCDEFGH
    PreOrder(tree);
    cout << endl;
    cout << "中序递归遍历：";//中序递归遍历：CBEDFAHG
    InOrder(tree);
    cout << endl;
    cout << "后序递归遍历：";//后序递归遍历：CEFDBHGA
    PostOrder(tree);
    cout << endl;
    cout << "层序递归遍历：";//层序递归遍历：ABGCDHEF
    LevelOrder(tree);
    return 0;
}