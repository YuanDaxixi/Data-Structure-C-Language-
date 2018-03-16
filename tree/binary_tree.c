/*
 *  binary tree implemetation
 *
 *
 *  (C)    2018-3    Yuanda
 */

#include "binary_tree.h"

void inorder_walk(pBitree root)
{
    if (root)
    {
        inorder_walk(root->lchild);
        printf("%d", root->key);
        inorder_walk(root->rchild);
    }
}

void preorder_walk(pBitree root)
{
    if (root)
    {
        printf("%d", root->key);
        preorder_walk(root->lchild);
        preorder_walk(root->rchild);
    }
}

void postorder_walk(pBitree root)
{
    if (root)
    {
        preorder_walk(root->lchild);
        preorder_walk(root->rchild);
        printf("%d", root->key);
    }
}

pBitree tree_search(const pBitree root, int key)
{
    while (root)
    {
        if (key == root->key)
            break;
        else if (key > root->key)
            root = root->rchild;
        else
            root = root->lchild;
    }
    return root;
}

pBitree tree_min_node(pBitree root)
{
    while (root->lchild)
        root = root->lchild;
    return root;
}

pBitree tree_max_node(pBitree root)
{
    while (root->rchild)
        root = root->rchild;
    return root;
}

pBitree tree_successor(pBitree node_x)
{
    pBitree papa;

    if (node_x->rchild)
        return tree_min_node(node_x->rchild);

    papa = node_x->p;
    while (papa && papa->lchild != node_x)
    {
        node_x = papa;
        papa = papa->p;
    }
    return papa;
}

pBitree tree_predecessor(pBitree node_x)
{
    pBitree papa;

    if (node_x->lchild)
        return tree_max_node(node_x->lchild);

    papa = node_x->p;
    while (papa && papa->rchild != node_x)
    {
        node_x = papa;
        papa = papa->p;
    }
    return papa;
}

void tree_insert(pTree tree, pBitree node_x)
{
    pBitree papa = NULL;
    pBitree hole = tree->root;

    while (hole)
    {
        papa = hole;
        if (node_x->key >= hole->key)
            hole = hole->rchild;
        else
            hole = hole->lchild;
    }

    (tree->lenght)++;
    node_x->p = papa;
    if (papa == NULL)
        tree->root = node_x;
    else if (node_x->key < papa->key)
        papa->lchild = node_x;
    else
        papa->rchild = node_x;
}

void tree_delete(pTree tree, pBitree node_x)
{
    pBitree suc;

    if (node_x->lchild == NULL)
        transplant(tree, node_x, node_x->rchild);
    else if (node_x->rchild == NULL)
        transplant(tree, node_x, node_x->lchild);
    else// find node_x's successor(a successor must not have left child)
    {
        suc = tree_successor(node_x);
        if (suc->p != node_x)
        {
            transplant(tree, suc, suc->rchild);
            suc->rchild = node_x->rchild;
            suc->rchild->p = suc;
        }
        transplant(tree, node_x, suc);
        suc->lchild = node_x->lchild;
        suc->lchild->p = suc;
    }
    free(node_x->info);
    free(node_x);
    (tree->lenght)--;
}

void transplant(pTree tree, pBitree node_x, pBitree node_y)
{
    if (node_x->p == NULL)
        tree->root = node_y;
    else if (node_x == node_x->p->lchild)
        node_x->p->lchild = node_y;
    else
        node_x->p->rchild = node_y;
    if (node_y != NULL)
        node_y->p = node_x->p;
}

void ruin_tree(pTree tree)
{
    if (tree->root)
    {
        free_tree(tree->root);
        tree->root = NULL;
        tree->lenght = 0;
    }
}

static void free_tree(pBitree root)
{
    free_tree(root->lchild);
    free_tree(root->rchild);
    free(root->info);
    free(root);
}

pBitree tree_new_node(Bitree value, size_t size)
{
    pBitree new_log = (pBitree)malloc(sizeof(Bitree));
    if (new_log)
        memcpy(new_log, &value, size);
    return new_log
}