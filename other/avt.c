//
// Created by fengyingcai on 2017/4/28.
//

/*
 * 平衡二叉树
 * */

typedef struct _AVLNode {
    int data;
    int bf;     // 平衡因子
    struct _AVLNode *lchild;  // 左子树
    struct _AVLNode *rchild; // 右子树
} AVLNode, *PAVLNode;

// 右旋转，提升左子树
void r_rotate(PAVLNode *ptree)
{
    PAVLNode tree = *ptree;
    PAVLNode lchild = tree->lchild;
    tree->lchild = lchild->rchild;
    lchild->rchild = tree;
    *ptree = lchild;
}

// 左旋转，提升右子树
void l_rotate(PAVLNode *ptree)
{
    PAVLNode tree = *ptree;
    PAVLNode rchild = tree->rchild;
    tree -> rchild = rchild->lchild;
    rchild->lchild = tree;
    *ptree = rchild;
}

// 对树进行左平衡
void left_blance(PAVLNode *ptree)
{
    PAVLNode tree = *ptree;
    PAVLNode lchild = tree->lchild;
    switch (lchild->bf){
        case 1:
            // 左高，LL 型
            r_rotate(ptree);
            tree->bf = lchild->bf = 0;
            break;
        case -1:
            // 右高，LR 型
            PAVLNode lrchild = lchild->rchild;
            switch (rd->bf) {
                case 1:
                    tree->bf = -1;
                    lchild->bf = 0;
                    break;
                case 0:
                    tree->bf = lchild->bf = 0;
                    break;
                case -1:
                    tree->bf = 0;
                    lchild->bf = 1;
                    break;
            }
            lrchild->bf = 0;
            l_rotate(&(tree->lchild));
            r_rotate(ptree);
    }
}


void insert_avl(PAVLNode *ptree, int data, int *taller)
{
    // 没有结点
    if (!ptree) {
        *ptree = (PAVLNode)calloc(1, sizeof(AVLNode));
        (*ptree)->data = data;
        (*ptree)->bf = 0;
        taller = 1;
    }
    else {
        PAVLNode tree = (*ptree);
        if (data < tree->data ){
            insert_avl(&(tree->lchild), data, taller);
            if (taller){
                //....
            }
        }
    }
}
