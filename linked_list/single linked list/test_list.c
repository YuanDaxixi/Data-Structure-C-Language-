/*
 *  test for single linked list
 *
 *  (C)    2015-4    Yuanda Zhang
 */

#include <stdio.h>
#include "Linked_List.h"

#define MAX 20

void test_new_node_back(LinkedList *p_list);
void test_new_node_front(LinkedList *p_list);
void test_get_prev_node(LinkedList *p_list, pListNode node);
void test_delete_node(LinkedList *p_list, pListNode node);
void test_free_list(LinkedList *p_list);
void test_insert_node_back(LinkedList *p_list, pListNode src, pListNode dst);
void test_invert_list(LinkedList *p_list);
void test_seek_by_value(LinkedList *p_list);
void test_combine_two_list(LinkedList *p_list_primary, LinkedList *p_list_scndry);

static int is_same(pListNode node, Elem);
static void print(pListNode node);

int main(void)
{
	LinkedList num_list, num_list_son;

	init_list(&num_list);
	init_list(&num_list_son);
	test_new_node_back(&num_list);
	//test_new_node_back(&num_list_son);
	//test_new_node_front(&num_list);
	test_get_prev_node(&num_list, NULL);
	//test_delete_node(&num_list, NULL);
	//test_insert_node_back(&num_list, NULL, NULL);
	//test_invert_list(&num_list);
	test_seek_by_value(&num_list);
	//test_combine_two_list(&num_list, &num_list_son);
	test_free_list(&num_list);
	return 0;
}

void test_new_node_back(LinkedList *p_list)
{
	pListNode trace_node;
	int test_data;
	int i;

	printf("/********************\\\n");
	printf("## test_new_node_back ##\n");
	for ( i = 0; i < MAX; i++ )
	{
		test_data = i + 1;
		trace_node = new_node_back(p_list);
		assign_value(trace_node, &test_data, sizeof(test_data));
	}
	print_list(p_list,print);
	printf("\\********************/\n\n");
}

void test_new_node_front(LinkedList *p_list)
{
	pListNode trace_node;
	int test_data;
	int i;

	printf("/********************\\\n");
	printf("## test_new_node_front ## \n");
	for ( i = 0; i < MAX; i++ )
	{
		test_data = i + MAX;
		trace_node = new_node_front(p_list);
		assign_value(trace_node, &test_data, sizeof(test_data));
	}
	print_list(p_list, print);
	printf("\\********************/\n\n");
}

void test_get_prev_node(LinkedList *p_list, pListNode node)
{
	int i, index;
	node = p_list->head;

	printf("/********************\\\n");
	printf("## test_get_prev_node ##\n");
	printf("Enter index, I give you the previous:");
	while ( scanf("%d", &index) )
	{
		for ( i = 0; i < index; i++ )
			node = node->next;
		printf("value: %p\n", get_prev_node(p_list, node));
		node = p_list->head;
		printf("Enter index, I give you the previous:");
	}
	printf("\\********************/\n\n");
}

void test_delete_node(LinkedList *p_list, pListNode node)
{
	int i, index;
	node = p_list->head;

	printf("/********************\\\n");
	printf("## test_delete_node ##\n");
	printf("Enter index, I delete it:");
	while ( scanf("%d", &index) )
	{
		for ( i = 0; i < index; i++ )
			node = node->next;
		delete_node(p_list, node);
		print_list(p_list, print);
		node = p_list->head;
		printf("Enter index, I delete it:");
	}


	printf("\\********************/\n\n");
}

void test_free_list(LinkedList *p_list)
{
	printf("/********************\\\n");
	printf("## test_free_list ##\n");
	free_list(p_list);
	printf("head->%p\n" "tail->%p\n", p_list->head, p_list->tail);
	printf("\\********************/\n\n");
}

void test_insert_node_back(LinkedList *p_list, pListNode src, pListNode dst)
{
	int src_index, dst_index;
	int i;

	printf("/********************\\\n");
	printf("## test_insert_node_back ##\n");
	printf("Enter the source and destination index:");
	while ( scanf("%d %d", &src_index, &dst_index) == 2 )
	{
		for ( src = p_list->head, i = 0; i < src_index; i++ )
			src = src->next;
		for ( dst = p_list->head, i = 0; i < dst_index; i++ )
			dst = dst->next;
		insert_node_back(p_list, src, dst);
		print_list(p_list, print);
		printf("Enter the source and destination index:");
	}
	printf("\\********************/\n\n");
}

void test_invert_list(LinkedList *p_list)
{
	printf("/********************\\\n");
	printf("## test_insert_node_back ##\n");
	invert_list(p_list);
	print_list(p_list, print);
	printf("\\********************/\n\n");
}
void test_seek_by_value(LinkedList *p_list)
{
	int data;

	printf("/********************\\\n");
	printf("## test_seek_by_value ##\n");
	printf("Enter the value:");
	while ( scanf("%d", &data) == 1 )
	{
		printf("value: %p\n", seek_by_value(p_list, data, is_same));
		printf("Enter the value:");
	}
	printf("\\********************/\n\n");
}

void test_combine_two_list(LinkedList *p_list_primary, LinkedList *p_list_scndry)
{
	printf("/********************\\\n");
	printf("## test_combine_two_list ##\n");
	combine_two_list(p_list_primary, p_list_scndry);
	print_list(p_list_primary, print);
	printf("\\********************/\n\n");
}

static int is_same(pListNode node, Elem data)
{
	return  *( (int*)(node->data) ) == *(int*)data;
}

static void print(pListNode node)
{
	printf("%d\n", *(int*)(node->data));
}