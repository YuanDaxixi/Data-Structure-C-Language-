/*
 *  stack interface with guard
 *
 *
 *  (C)    2014-5    Yuanda Zhang
 */

#include "stack.h"

int init_stack(Stack *p_stack)
{
	p_stack->bottom = malloc(sizeof(StackNode));
	p_stack->top = p_stack->bottom;
	p_stack->bottom->data = NULL;
	p_stack->bottom->next = NULL;
	p_stack->length = 0;

	return (int)p_stack->bottom;
}

int assign_value_stack(pStackNode node, Elem src_data, size_t count)
{
	node->data = malloc(count);
	if ( node->data )
		memcpy(node->data, src_data, count);

	return (int)node->data;
}

void delete_stack(Stack *p_stack)
{
	pStackNode death;
	pStackNode next = p_stack->bottom;

	for ( death = next; death != NULL; death = next )
	{
		next = death->next;
		free(death->data);
		free(death);
	}
	p_stack->bottom = NULL;
	p_stack->top = NULL;
	p_stack->length = 0;
}

int get_stack_len(Stack *p_stack)
{
	return p_stack->length;
}

pStackNode get_prev_node(Stack *p_stack, pStackNode node)
{
	pStackNode prev;

	for ( prev = p_stack->bottom; prev != NULL && prev->next != node; prev = prev->next )
		continue;

	return prev;
}

const Elem get_top_data(Stack *p_stack)
{
	return get_stack_len(p_stack) > 0 ? p_stack->top->data : NULL;
}

//int push_stack(Stack *p_stack, Elem src_data, size_t count)
//{
//	pStackNode new_node = malloc(sizeof(StackNode));
//	
//	if ( new_node == NULL )
//		;
//	else
//	{
//		new_node->next = NULL;
//                p_stack->top->next = new_node;
//		p_stack->top = new_node;
//		p_stack->length++;
//		assign_value_stack(new_node, src_data, count);
//	}
//	
//	return (int)new_node;
//}

//int pop_stack(Stack *p_stack, Elem data_loader, size_t count)
//{
//	pStackNode prev_node;
//
//	if ( get_stack_len(p_stack) == 0 )
//		;
//	else
//	{
//		memcpy(data_loader, p_stack->top->data, count);
//		prev_node	 = get_prev_node(p_stack, p_stack->top);
//		free(p_stack->top->data);
//		free(p_stack->top);
//		p_stack->top = prev_node;
//		p_stack->top->next = NULL;
//		p_stack->length--;
//	}
//
//	return p_stack->length;
//}
