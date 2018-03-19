/*
 *  tests for binary tree
 *
 *
 *  (C)    2018-3    Yuanda
 */

#include "binary_tree.h"

#define LEN 15

void construct_array(int array[], int size);
void test_tree_insert(pTree tree, int array[], int size);
void test_tree_search(pTree tree, int array[], int size);
void test_tree_min_max(pTree tree);
void test_tree_cessor(pTree tree);
void test_tree_delete(pTree tree, int array[], int size);
void test_ruin_tree(pTree tree);

int main(void)
{
    int array[LEN];
    Tree tree;

    construct_array(array, LEN);
    tree_initial(&tree);

    test_tree_insert(&tree, array, LEN);

    inorder_walk(tree.root);
    printf("*****************\n");
    preorder_walk(tree.root);
    printf("*****************\n");
    postorder_walk(tree.root);

    test_tree_search(&tree, array, LEN);

    test_tree_min_max(&tree);

    test_tree_cessor(&tree);

    test_tree_delete(&tree, array, LEN);

    test_ruin_tree(&tree);
    system("pause");
    return 0;
}

void construct_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = i;
}

void test_tree_insert(pTree tree, int array[], int size)
{
    int *left_array = NULL;
    int *right_array = NULL;
    pBitree new_node = NULL;
    Bitree value = { NULL, 0, NULL, NULL, NULL };
    if (size > 0)
    {
        value.key = array[size / 2];
        new_node = tree_new_node(value, sizeof(value));
        tree_insert(tree, new_node);
        left_array = array;
        right_array = array + size / 2 + 1;
        test_tree_insert(tree, left_array, (size - 1) / 2);
        test_tree_insert(tree, right_array, (size - 1) / 2);
    }
    printf("tree length:%d\n\n", tree->length);
}

void test_tree_search(pTree tree, int array[], int size)
{
    pBitree temp_node;

    for (int i = 0; i < size; i++)
    {
        temp_node = tree_search(tree->root, array[i]);
        printf("node->key:%2d\tarray[%d]:%2d\n", temp_node->key, i, array[i]);
    }
    temp_node = tree_search(tree->root, -1);
    printf("No match:%p\n", temp_node);
}

void test_tree_min_max(pTree tree)
{
    pBitree temp_node = NULL;

    temp_node = tree_min_node(tree->root);
    printf("min: %d\n", temp_node->key);
    temp_node = tree_max_node(tree->root);
    printf("max: %d\n", temp_node->key);
}

void test_tree_cessor(pTree tree)
{
    pBitree temp_node = NULL;

    temp_node = tree_successor(tree->root);
    printf("root's successor: %d\n", temp_node->key);
    temp_node = tree_predecessor(tree->root);
    printf("root's predecessor: %d\n", temp_node->key);
}
void test_tree_delete(pTree tree, int array[], int size)
{
    pBitree temp_node = NULL;

    for (int i = 0; i < size; i++)
    {
        temp_node = tree_search(tree->root, array[size/2]);
        if (temp_node)
            tree_delete(tree, temp_node);
    }
    printf("tree length: %d\n", tree->length);
    inorder_walk(tree->root);
}

void test_ruin_tree(pTree tree)
{
    ruin_tree(tree);
    printf("root: %p\n", tree->root);
    printf("length: %d\n", tree->length);
}