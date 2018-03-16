/*
 *  binary tree implemetation
 *
 *
 *  (C)    2018-3    Yuanda
 */

#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *Info;

// definition of the binary tree
typedef struct bitree {
    Info info;
    int key;
    struct bitree *p;
    struct bitree *lchild;
    struct bitree *rchild;
}Bitree;

typedef Bitree *pBitree;

typedef struct tree {
    pBitree root;
    unsigned int lenght;
}Tree;

typedef Tree *pTree;

#define load_info(node, type)    ( (type)((node)->info) )

/*
 * inorder tree walk: left-child-->self-->right-child
 * <root> root of the binary tree
 */
void inorder_walk(pBitree root);

/*
 * preorder tree walk: self-->left-child-->right-child 
 * <root> root of the binary tree
 */
void preorder_walk(pBitree root);

/*
 * postorder tree walk: left-child-->right-child-->self
 * <root> root of the binary tree
 */
void postorder_walk(pBitree root);

/*
 * search the binary tree for <key> and return the corrsponding node
 * return the right node address or NULL(when failed)
 * <root> root of the binary tree
 * <key> the value searched, 'key' is a attribute of the Bitree structure
 */
pBitree tree_search(const pBitree root, int key);

/*
 * find the node whose 'key' attribute is minimum of the tree
 * and return this node
 * <root> root of the tree
 */
pBitree tree_min_node(pBitree root);

/*
 * find the node whose 'key' attribute is maximum of the tree
 * and return this node
 * <root> root of the tree
 */
pBitree tree_max_node(pBitree root);

/*
 * given a tree node_x, find his successor, who is the least
 *node whose key is larger than nodex's
 * return the successor
 * <node_x> a binary tree node and we want to find his successor
 */
pBitree tree_successor(pBitree node_x);

/*
 * given a tree node_x, find his predecessor, who is the largest
 *node whose key is less than nodex's
 * return the predecessor
 * <node_x> a binary tree node and we want to find his predecessor
 */
pBitree tree_predecessor(pBitree node_x);

/*
 * insert node_x into the binary SEARCH tree
 * <tree> the tree
 * <node_x> the node to be searched
 */
void tree_insert(pTree tree, pBitree node_x);

/*
 * delete node_x from the tree
 * <tree> the tree
 * <node_x> the node to be deleted
 */
void tree_delete(pTree tree, pBitree node_x);

/*
 * using node_y replace node_x in the tree
 * <tree> the tree
 * <node_x> a node of the tree to be abandoned
 * <node_y> a node (of the tree or not) to be leveled up 
 */
void transplant(pTree tree, pBitree node_x, pBitree node_y);

/*
 * free the whole tree's space
 * <root> root of the tree
 */
static void free_tree(pBitree root);

/*
 * delete the whole tree, free space and set ALL to 0/null
 * <tree> the tree
 */
void ruin_tree(pTree tree);

/*
 * create a new binary tree node with <value> 
 * return the address of this new node
 * <value> assign <value> to the new node
 * <size> size of the <value>
 */
pBitree tree_new_node(Bitree value, size_t size);

#endif