#include <stdio.h>
#include <stdlib.h>
#define TreeElementType int
#define NoInfo 0

typedef struct TreeNode{
    TreeElementType Data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
typedef TreeNode* PtrToTreeNode;
typedef PtrToTreeNode Tree;
typedef PtrToTreeNode BinTree;

#include </home/ran/Documents/dataStructure/Tree/Queue.c>
void Tree_inorderTraversal(Tree t)
{
    if(t){
        Tree_inorderTraversal(t->left);
        printf("%d ", t->Data);
        Tree_inorderTraversal(t->right);
    }
}

void Tree_preorderTraversal(Tree t)
{
    if(t){
        printf("%d ", t->Data);
        Tree_preorderTraversal(t->left);
        Tree_preorderTraversal(t->right);
    }
}

void Tree_postorderTraversal(Tree t)
{
    if(t){
        Tree_postorderTraversal(t->left);
        Tree_postorderTraversal(t->right);
        printf("%d ", t->Data);
    }
}

void Tree_levelorderTraversal(Tree t)
{
    Queue q = Queue_create();
    PtrToQueueNode tmp;
    if(t){
        Queue_add(q, t);
    }
    while(!Queue_isempty(q)){
        tmp = Queue_delete(q);
        if(tmp->Data->left){
            Queue_add(q, tmp->Data->left);
        }
        if(tmp->Data->right){
            Queue_add(q, tmp->Data->right);
        }
        printf("%d ", tmp->Data->Data);
        free(tmp);
    }
}

Tree Tree_create()
{
    PtrToQueueNode tmp;
    TreeElementType d;
    Tree out, node;
    Queue q = Queue_create();
    
    scanf("%d", &d);
    out = (Tree)malloc(sizeof(TreeNode));
    out->Data = d;
    out->left = NULL;
    out->right = NULL;
    Queue_add(q, out);
    while(!Queue_isempty(q)){
        TreeElementType l, r;
        tmp = Queue_delete(q);
        node = tmp->Data;
        free(tmp);

        scanf("%d", &l);
        scanf("%d", &r);

        if(l != NoInfo){
            node->left = (PtrToTreeNode)malloc(sizeof(TreeNode));
            node->left->Data = l;
            node->left->left = NULL;
            node->left->right = NULL;
            Queue_add(q, node->left);
        }else{
            node->left = NULL;
        }

        if(r != NoInfo){
            node->right = (PtrToTreeNode)malloc(sizeof(TreeNode));
            node->right->Data = r;
            node->right->left = NULL;
            node->right->right = NULL;
            Queue_add(q, node->right);
        }else{
            node->right = NULL;
        }

    }
    return out;
}

void BinTree_insert(BinTree bt, TreeElementType d)
{
    if(!bt->left && !bt->right){
        bt->Data = d;
        bt->left = (PtrToTreeNode)malloc(sizeof(TreeNode));
        bt->right= (PtrToTreeNode)malloc(sizeof(TreeNode));
    }else{
        if(d < bt->Data){
            bt->left->Data = d;
            bt->left->left = (PtrToTreeNode)malloc(sizeof(TreeNode));
            bt->left->right = (PtrToTreeNode)malloc(sizeof(TreeNode));
        }else if(d > bt->Data){
            bt->right->Data = d;
            bt->right->left= (PtrToTreeNode)malloc(sizeof(TreeNode));
            bt->right->right= (PtrToTreeNode)malloc(sizeof(TreeNode));
        }
    }
}

BinTree BinTree_create(void)
{
    return (BinTree)malloc(sizeof(TreeNode));
}
