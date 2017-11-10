/*
 *  set
 *
 *
 *
 *  (C)    2015-5    Yuanda Zhang
 */
 
#ifndef __SET_H__
#define __SET_H__

#include "doubly_linked_list.h"

typedef DLinkedList Set;
typedef Set *pSet;
typedef DListNode SetElem;
typedef SetElem *pSetElem;

typedef struct{
	int num;
}ElemInfo;
typedef ElemInfo *pElemInfo;

#define data_elem(set_elem)     data_list_node(set_elem, pElemInfo)

/*
 * function:  initialize set(do as doubly linked list does)
 * return:    0 if fail
 * parameter: address of set
 * call:      none
 * called by: none
 */
 int init_set(pSet set);
 
/*
 * function:  add a elem to set
 * return:    address of the added elem, NULL means the set already has this elem or something wrong
 * parameter: 1.set; 2.the elem to be added
 * call:      seek_elem;
 * called by: union_set, intersect_set
 */
 pSetElem add_elem(pSet set, ElemInfo added_elem);
 
/*
 * function:  union
 * return:    address of new set, NULL means failure
 * parameter: 1.primary set; 2.secondary set
 * call:      init_set, add_elem
 * called by: none
 */
 pSet union_set(pSet pri_set, pSet scnd_set);
 
/*
 * function:  intersection
 * return:    address of new set, NULL means failure
 * parameter: 1.primary set; 2.secondary set
 * call:      init_set, add_elem
 * called by: none
 */
 pSet intersect_set(pSet pri_set, pSet scnd_set);
 
 /*
 * function:  judge if two sets are same
 * return:    return 1 if same, 0 means not same
 * parameter: 1.primary set; 2.secondary set
 * call:      none
 * called by: none
 */
 int equal_set(pSet pri_set, pSet scnd_set);
 
/*
 * function:  delete a elem from the set
 * return:    return 1 if succeed, 0 means fail
 * parameter: 1.set; 2.elem to be deleted
 * call:      none
 * called by: delete_set
 */
 int delete_elem(pSet set, pSetElem target_elem);
 
/*
 * function:  delete the set
 * return:    none
 * parameter: the set
 * call:      delete_elem
 * called by; none
 */
 void delete_set(pSet set);
 
/*
 * function:  seek elem into the set by seek_value
 * return:    address of found set elem, NULL means not finding
 * parameter: 1.the set; 2.seek_value
 * call:      none
 * called by; add_elem
 */
 pSetElem seek_elem(pSet set, pElemInfo seek_value);

/*
 * function:  print the set
 * return:    none
 * parameter: address of set
 * call:      none
 * called by; none
 */
 void print_set(pSet set);

 // for print_list function pointer
 static void print(pSetElem elem);
 // for seek_by_value function pointer
 static int compare(void *tar, void *value);

#endif
