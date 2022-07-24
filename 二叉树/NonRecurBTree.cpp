//
// Created by yzm-dev on 2022/5/23.
//

#include <iostream>

using namespace std;
const int MAXSIZE = 30; // 栈的最大长度
// 二叉树的改进，非递归遍历
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

void PreOrderNonRecursion(BTNode *node) {
    if (node) {
        BTNode *Stack[MAXSIZE];
        int top = -1;
        BTNode *p;
        Stack[++top] = node;//根节点入栈
        while (top != -1) {//栈空循环退出，遍历结束
            p = Stack[top--];//出栈并输出定点结点
            Visit(p);
            //栈顶结点右孩子存在则入栈
            if (p->rchild != nullptr) Stack[++top] = p->rchild;
            //栈顶结点左孩子存在则入栈
            if (p->lchild != nullptr) Stack[++top] = p->lchild;
        }
    }
}

void InOrderNonRecursion(BTNode *node) {
    if (node) {
        BTNode *Stack[MAXSIZE];
        int top = -1;
        BTNode *p = node;
        while (top != -1 || p != nullptr) {
            while (p != nullptr) { //左孩子存在左孩子进站
                Stack[++top] = p;
                p = p->lchild;
            }
            if (top != -1) { //在栈不空的情况下出栈并输出结点
                p = Stack[top--];
                Visit(p);
                p = p->rchild;
            }
        }
    }
}

void PostOrderNonRecursion(BTNode *node) {
    if (node) {
        // 定义两个栈
        BTNode *Stack1[MAXSIZE];
        BTNode *Stack2[MAXSIZE];
        int top1 = -1, top2 = -1;
        BTNode *p;
        Stack1[++top1] = node;
        while (top1 != -1) {
            p = Stack1[top1--];
            Stack2[++top2] = p; // 和先序遍历的区别，输出为Stack2
            if (p->lchild != nullptr) Stack1[++top1] = p->lchild;
            if (p->rchild != nullptr) Stack1[++top1] = p->rchild;
        }
        while (top2 != -1) {
            // 出栈序列即为后序遍历
            p = Stack2[top2--];
            Visit(p);
        }
    }
}

int main() {
    cout << "创建一颗树，用“#”表示空树: ";
    BiTree tree;
    CreateBiTree(tree); //先序递归创建二叉树 如: ABC##DE##F##GH###
    cout << "先序非递归遍历：";//先序递归遍历：ABCDEFGH
    PreOrderNonRecursion(tree);
    cout << endl;
    cout << "中序非递归遍历：";//中序递归遍历：CBEDFAHG
    InOrderNonRecursion(tree);
    cout << endl;
    cout << "后序非递归遍历：";//后序递归遍历：CEFDBHGA
    PostOrderNonRecursion(tree);
    return 0;
}
