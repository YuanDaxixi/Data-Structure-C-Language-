/*
 *  stack interface with guard
 *
 *
 *  (C)    2014-5    Yuanda Zhang
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *  data in the stack, using void* make the situation common
 */
#ifndef __DOUBLY_LIST_H__
typedef void * Elem;
#endif

/* definition of stack */
typedef struct stack{
	Elem data;
	struct stack *next;
}StackNode;

typedef StackNode *pStackNode;

/* data structure to save top, bottom and length of stack */
typedef struct{
	pStackNode top;
	pStackNode bottom;
	int       length;
}Stack;

/*
 * function:        initialize the stack(create guard node,and bottom and top point to guard)
 * return:          return 0 if fail
 * parameter:       the stack
 * call:            none
 * called by:       none
 */
int init_stack(Stack *p_stack);

/*
 * function:        assign value to a node
 * return:          return 0 if fail
 * parameter:       1.stack node; 2.void pointer of data; 3.byte of data
 * call:            none
 * called by:       push_stack
 */
int assign_value_stack(pStackNode node, Elem src_data, size_t count);

/* 
 * function:        delete the whole stack,set bottom and top NULL,length 0
 * return:          none
 * parameter:       the stack
 * call:            none
 * called by:       none
 */
void delete_stack(Stack *p_stack);


/*
 * function:        get the length of stack
 * return:          length
 * parameter:       the stack
 * call:            none
 * called by:       pop_stack, get_top_data
 */
int get_stack_len(Stack *p_stack);

/*
 * function:        get the previous node address
 * return:          the address of previous node
 * parameter:       1.the stack; 2.target node
 * call:            none
 * called by:       pop_stack
 */
pStackNode get_prev_node(Stack *p_stack, pStackNode node);

/*
 * function:        pop data of top node
 * return:          return void pointer to the data
 * parameter:       stack
 * call:            get_stack_len
 * called by:       none
 */
const Elem get_top_data(Stack *p_stack);

/*
 * function:        push a node into stack
 * return:          return 0 if fail
 * parameter:       1.the stack; 2.source data; 3.byte of data
 * call:            assign_value
 * called by:       none
 */
//int push_stack(Stack *p_stack, Elem src_data, size_t count);

/*
 * function:        pop top node
 * return:          return the length of stack
 * parameter:       1.stack; 2. void pointer to save top data; 3.byte of data
 * call:            get_stack_len, get_prev_node
 * called by:       none
 */
//int pop_stack(Stack *p_stack, Elem data_loader, size_t count);

// import address of src_data, this function allocates space to save src_data
#define _push_prototype(type)                                   \
int push_##type(Stack *p_stack, type *src_data)                 \
{                                                               \
	pStackNode new_node = malloc(sizeof(StackNode));        \
	if ( new_node == NULL )                                 \
		;                                               \
	else                                                    \
	{                                                       \
		new_node->next = NULL;                          \
		p_stack->top->next = new_node;                  \
		p_stack->top = new_node;                        \
		p_stack->length++;                              \
		assign_value_stack(new_node, (Elem)src_data, sizeof(type));\
	}                                                       \
	return (int)new_node;                                   \
}

#define _pop_prototype(type)                                    \
type pop_##type(Stack *p_stack)                                 \
{                                                               \
	pStackNode prev_node;                                   \
	type data_loader = (type)(0);                           \
	                                                        \
	if ( get_stack_len(p_stack) == 0 )                      \
		;                                               \
	else                                                    \
	{                                                       \
		data_loader = *((type *)p_stack->top->data);    \
		prev_node = get_prev_node(p_stack, p_stack->top);\
		free(p_stack->top->data);                       \
		free(p_stack->top);                             \
		p_stack->top = prev_node;                       \
		p_stack->top->next = NULL;                      \
		p_stack->length--;                              \
	}                                                       \
	                                                        \
	return data_loader;                                     \
}

#endif
