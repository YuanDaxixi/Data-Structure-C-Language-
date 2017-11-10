/*
 *  single linked list(with guard) implementation
 *
 *
 *  (C)    2015-4    Yuanda Zhang
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* p_list is a structure that holds the head and tail of the list */
int init_list(LinkedList *p_list)
{
	p_list->head = malloc(sizeof(ListNode));

	if ( p_list->head != NULL )
	{
		p_list->tail = p_list->head;
		p_list->head->next = NULL;
		p_list->length = 0;
	}

	return (int)(p_list->head);
}

pListNode new_node_back(LinkedList *p_list)
{
	p_list->tail->next = malloc(sizeof(ListNode));
	p_list->tail = p_list->tail->next;
	p_list->tail->next = NULL;
	p_list->length++;

	return p_list->tail;
}

pListNode new_node_front(LinkedList *p_list)
{
	pListNode new_node = malloc(sizeof(ListNode));

	if ( new_node != NULL )
	{
		new_node->next = p_list->head->next;
		p_list->head->next = new_node;
		p_list->length++;
	}

	return new_node;
}

pListNode get_prev_node(LinkedList *p_list, pListNode node)
{
	pListNode prev;

	for ( prev = p_list->head; prev->next != node && prev != NULL; prev = prev->next )
		continue;

	return prev;
}

void insert_node_back(LinkedList *p_list, pListNode src_node, pListNode dst_node)
{
	pListNode prev_of_src;

	if ( src_node != NULL && dst_node != NULL && 
             src_node != p_list->head &&
	     src_node != dst_node)
	{
		prev_of_src = get_prev_node(p_list, src_node);
		prev_of_src->next = src_node->next;
		src_node->next = dst_node->next;
		dst_node->next = src_node;
		p_list->tail = (src_node == p_list->tail) ? prev_of_src : p_list->tail;        //if the node moved is tail...
		p_list->tail = (dst_node == p_list->tail) ? src_node : p_list->tail;           //if the node moved toward is tail...
	}
}

pListNode delete_node(LinkedList *p_list, pListNode node)
{
	pListNode prev_node;

	prev_node = get_prev_node(p_list, node);
	if ( prev_node != NULL && node != NULL)
	{
		prev_node->next = node->next;
		p_list->tail = (node == p_list->tail) ? prev_node : p_list->tail;        //if the node deleted is tail...
		free(node->data);
		free(node);
		p_list->length--;
	}

	return prev_node;
}

void free_list(LinkedList *p_list)
{
	pListNode death = p_list->head;
	
	while ( death->next != NULL )
		death = delete_node(p_list, death->next);        //when death->next is NULL, the return value is NULL
	free(p_list->head);
	p_list->head = NULL;
	p_list->tail = NULL;
	p_list->length = 0;
}

pListNode seek_by_value(LinkedList *p_list, Elem data, 
	             int (*cmp)(pListNode node, Elem data) )
{
	pListNode target_node = p_list->head;
	pListNode ret = NULL;

	while ( target_node->next != NULL )
	{
		target_node = target_node->next;
		if ( cmp(target_node, data) )
			ret = target_node;
	}

	return ret;
}

int assign_value(pListNode node, Elem data, size_t count)
{
	node->data = malloc(count);
	if ( node->data )
		memcpy(node->data, data, count);

	return (int)node->data;
}

void invert_list(LinkedList *p_list)
{
	pListNode trace_node = p_list->head->next;

	while ( trace_node != NULL && trace_node->next != NULL )
		insert_node_back(p_list, trace_node->next, p_list->head);
}

void print_list(LinkedList *p_list, void (*print)(pListNode))
{
	pListNode print_node = p_list->head;

	while ( print_node->next != NULL )
	{
		print_node = print_node->next;
		print(print_node);
	}
}

void combine_two_list(LinkedList *p_list_primary, LinkedList *p_list_scndry)
{
	p_list_primary->tail->next = p_list_scndry->head->next;
	p_list_primary->length += p_list_scndry->length;
	free(p_list_scndry->head);
	p_list_scndry->head = NULL;
	p_list_scndry->tail = NULL;
}