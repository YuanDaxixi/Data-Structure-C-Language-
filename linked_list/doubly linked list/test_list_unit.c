/*
 *  test for single linked list
 *
 *  (C)    2015-4    Yuanda Zhang
 */

/*
 *  modified    2014-5    Yuanda Zhang
 */

#include <stdio.h>
#include "doubly_linked_list.h"

#define MAX 20

static int is_same(Elem node_value, Elem data);
static void print(pDListNode node);
static int is_bigger(Elem node_value, Elem data);

void test_new_node_back(DLinkedList *p_list);
void test_new_node_front(DLinkedList *p_list);
void test_delete_node(DLinkedList *p_list, pDListNode node);
void test_free_list(DLinkedList *p_list);
void test_insert_node_back(DLinkedList *p_list, pDListNode src, pDListNode dst);
void test_invert_list(DLinkedList *p_list);
void test_seek_by_value(DLinkedList *p_list);
void test_combine_two_list(DLinkedList *p_list_primary, DLinkedList *p_list_scndry);
void test_sort_on_list(DLinkedList *p_list);
void test_get_list_len(DLinkedList *p_list);

int main(void)
{
	DLinkedList num_list, num_list_son;

	init_list(&num_list);
	//init_list(&num_list_son);
	//test_new_node_back(&num_list);
	//test_new_node_front(&num_list);
	test_get_list_len(&num_list);
	//test_delete_node(&num_list, NULL);
	//test_insert_node_back(&num_list, NULL, NULL);
	//test_invert_list(&num_list);
	//test_seek_by_value(&num_list);
	//test_combine_two_list(&num_list, &num_list_son);
	test_sort_on_list(&num_list);
	test_free_list(&num_list);
	return 0;
}

void test_new_node_back(DLinkedList *p_list)
{
	pDListNode trace_node;
	int i;

	printf("/********************\\\n");
	printf("## test_new_node_back ##\n");
	for ( i = 0; i < MAX; i++ )
	{
		trace_node = new_node_back(p_list);
		assign_value(trace_node, &i, sizeof(i));
	}
	print_list(p_list, print);
	printf("\\********************/\n\n");
}

void test_new_node_front(DLinkedList *p_list)
{
	pDListNode trace_node;
	int i;

	printf("/********************\\\n");
	printf("## test_new_node_front ## \n");
	for ( i = 0; i < MAX; i++ )
	{
		trace_node = new_node_front(p_list);
		assign_value(trace_node, &i, sizeof(i));
	}
	print_list(p_list, print);
	printf("\\********************/\n\n");
}

void test_delete_node(DLinkedList *p_list, pDListNode node)
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

void test_free_list(DLinkedList *p_list)
{
	printf("/********************\\\n");
	printf("## test_free_list ##\n");
	free_list(p_list);
	printf("head->%p\n" "tail->%p\n", p_list->head, p_list->tail);
	printf("\\********************/\n\n");
}

void test_insert_node_back(DLinkedList *p_list, pDListNode src, pDListNode dst)
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

void test_invert_list(DLinkedList *p_list)
{
	printf("/********************\\\n");
	printf("## test_insert_node_back ##\n");
	invert_list(p_list);
	print_list(p_list, print);
	printf("\\********************/\n\n");
}
void test_seek_by_value(DLinkedList *p_list)
{
	int data;

	printf("/********************\\\n");
	printf("## test_seek_by_value ##\n");
	printf("Enter the value:");
	while ( scanf("%d", &data) == 1 )
	{
		printf("address: %p\n", seek_by_value(p_list, &data, is_same));
		printf("Enter the value:");
	}
	printf("\\********************/\n\n");
}

void test_combine_two_list(DLinkedList *p_list_primary, DLinkedList *p_list_scndry)
{
	printf("/********************\\\n");
	printf("## test_combine_two_list ##\n");
	combine_two_list(p_list_primary, p_list_scndry);
	print_list(p_list_primary, print);
	printf("\\********************/\n\n");
}

void test_sort_on_list(DLinkedList *p_list)
{
	printf("/********************\\\n");
	printf("## test_sort_on_list ##\n");
	sort_on_list(p_list, is_bigger);
	print_list(p_list, print);
	printf("\\********************/\n\n");
}

void test_get_list_len(DLinkedList *p_list)
{

	printf("/********************\\\n");
	printf("## test_get_list_len ##\n");
	printf("Length: %d\n", get_list_len(p_list));
	printf("\\********************/\n\n");
}

static int is_same(Elem node_value, Elem data)
{
	return  *(int*)node_value == *(int*)data;
}

static void print(pDListNode node)
{
	printf("%d\n", *(int*)(node->data));
}

static int is_bigger(Elem node_value, Elem data)
{
	return *(int*)node_value > *(int*)data;
}