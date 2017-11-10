/*
 *  single linked list interface
 *	
 *  (C)    2015-4    Yuanda Zhang
 */

#ifndef __LIST_H__
#define __LIST_H__

typedef unsigned int size_t;

/* data in the linked list */
typedef void* Elem;

/* definition of linked list */
typedef struct list{
	Elem data;
	struct list *next;
}ListNode;

typedef ListNode *pListNode;

/* data structure stores the linked list's head pointer and tail pointer */
typedef struct{
	ListNode *head;
	ListNode *tail;
	size_t   length;
}LinkedList;


/*
 * function:        initialize the linked list
 * return:          return 0 if fail
 * parameter:       the list
 * call:            none
 * called by:       none
 */
int init_list(LinkedList *p_list);

/*
 * function:        add a new node to the linked list in the end 
 * return:          return the address of the new node(NULL means fail)
 * parameter:       the list
 * call:            none
 * called by:       none
 */
pListNode new_node_back(LinkedList *p_list);

/*
 * function:        add a new node to the linked list in the beginning(at the back of guard)
 * return:          return the address of the new node(NULL means fail)
 * parameter:       the list
 * call:            none
 * called by:       none
 */
pListNode new_node_front(LinkedList *p_list);

/*
 * function:        get the previous node of the given node
 * return:          return NULL if can't find, else return the address
 * parameter:       1. the list;  2. the node we want to find its previous
 * call:            none
 * called by:       insert_node_back; delete_node
 * others:          because of the return value, input NULL return tail, input guard, return NULL
 */
pListNode get_prev_node(LinkedList *p_list, pListNode node);

/*
 * function:        insert a existing node of the list to somewhere in the list 
 * return:          none
 * parameter:       1. the list;  2. the node moved;  3. the node moved toward
 * call:            get_prev_node
 * called by:       invert_list
 * others:          guard can't be moved
 */
void insert_node_back(LinkedList *p_list, pListNode src_node, pListNode dst_node);

/*
 * function:        delete a node from the list
 * return:          return NULL if fail, else return the address of previous node
 * parameter:       1. the list;  2. the node would be deleted
 * call:            get_prev_node
 * called by:       free_list
 * others:          guard node can't be deleted, so return NULL. free(NULL) is legal, so return tail
 */
pListNode delete_node(LinkedList *p_list, pListNode node);

/*
 * function:        free the space of all nodes including guard
 * return:          none
 * parameter:       1. the list
 * call:            delete_node
 * called by:       none
 */
void free_list(LinkedList *p_list);

/*
 * function:        seek node by given value
 * return:          return NULL if can't find the node, else return the address
 * parameter:       1. the list; 2. the data used to seek; 3.the function to compare
 * call:            none
 * called by:       none
 */
pListNode seek_by_value(LinkedList *p_list, Elem data, int (*cmp)(pListNode, Elem));

/*
 * function:       assign value to a node
 * return:         return 0 if fail
 * parameter:      1. the node; 2. void pointer of data; 3.byte of data
 * call:           none
 * called by:      none
*/
int assign_value(pListNode node, Elem data, size_t count);

/*
 * function:        invert the list
 * return:          none
 * parameter:       1. the list
 * call:            insert_node_back
 * called by:       none
 * description:     call insert_node_back to finish this work, in every iteration insert the "third" node 
 *                  (guard is first, we record the "second" so we can always get third readily) to guard's back.
 */
void invert_list(LinkedList *p_list);

/*
 * function:        print the list
 * return:          none
 * parameter:       1. the list; 2. the function to print list
 * call:            none
 * called by:       none
 */
void print_list(LinkedList *p_list, void (*print)(pListNode));

/*
 * function:        conbine two lists into one (connect the second to the primary's ass) and disable the second
 * return:          none
 * parameter:       1. the primary list;  2. the secondary list
 * call:            none
 * called by:       none
 */
void combine_two_list(LinkedList *p_list_primary, LinkedList *p_list_scndry);

#endif