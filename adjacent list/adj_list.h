/*
 *  adjacent list implemented by doubly linked list
 *
 *
 *  (C)    2014-4    Yuanda Zhang
 */
 
#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__

#include "doubly_linked_list.h"

typedef DLinkedList AdjList;
typedef DLinkedList EdgeList;
typedef DListNode GraNode;
typedef DListNode GraEdge;

// data structure for edge
typedef struct edge{
	int          power;
	GraNode      *from;
	GraNode      *to;
}Edge;

// data structure for node
typedef struct{
	int      num;
	int      visited;
	EdgeList edge_list;
}Node;

#define  adjlist_head(adj_list)                list_head(adj_list)            
#define  adjlist_tail(adj_list)                list_tail(adj_list)
#define  edgelist_head(edge_list)              list_head(edge_list)
#define  edgelist_tail(edge_list)              list_head(edge_list) 
#define  next_gra_node(gra_node)               next_list_node(gra_node)       
#define  prev_gra_node(gra_node)               prev_list_node(gra_node)         
#define  data_gra_node(gra_node)               ( (Node*)((gra_node)->data) )
#define  is_valid_edge(gra_node, edge_list)     is_valid_node(gra_node, edge_list)
#define  next_gra_edge(gra_edge)               next_list_node(gra_edge)
#define  prev_gra_edge(gra_edge)               prev_list_node(gra_edge)
#define  data_gra_edge(gra_edge)               ( (Edge*)((gra_edge)->data) )

#define  gra_node_num(node)                   ( (node)->num )
#define  is_node_visited(node)                ( (node)->visited )
#define  get_edgelist(node)                   ( &(node)->edge_list )

#define  edge_power(edge)                     ( (edge)->power )
#define  edge_from(edge)                      ( (edge)->from )
#define  edge_to(edge)                        ( (edge)->to )

/*
 * function:  initialize adjacent list(does same thing as doubly linked list does)
 * return:    return 0 if fail
 * parameter: the adjacent list
 * call:      none;
 * called by: none;
 */
int init_gra(AdjList *adj_list);

/*
 * function:  initialize adjacent list(does same thing as doubly linked list does)
 * return:    return 0 if fail
 * parameter: the adjacent list
 * call:      none;
 * called by: none;
 */
int init_edge_list(EdgeList *edge_list);
 
/*
 * function:  add a new node at the end of the graph
 * return:    the address of the new node, NULL means failure
 * parameter: 1.the adjacent list; 2.number of the node
 * call:      none
 * called by: none
 */
GraNode* add_gra_node(AdjList *adj_list, int num);
 
/*
 * function:  add a new edge at the end of the edge list
 * return:    the address of the new edge, NULL means failure
 * parameter: 1.the adjacent list; 2.source node; 3.destination node; 4.power of edge
 * call:      none
 * called by: none
 */
GraEdge* add_gra_edge(AdjList *adj_list, int from, int to, int power);
 
/*
 * function:  delete all the space allocated for the graph
 * return:    none
 * parameter: the adjacent list
 * call:      none
 * called by: none
 */
void delete_gra(AdjList *adj_list);
 
/*
 * function:  sort node in ascending order
 * return:    none
 * parameter: 1.the adjacent list; 2.function to compare
 * call:      none
 * called by: none
 */
void sort_gra_node(AdjList *adj_list, int(*is_bigger)(Elem, Elem));
 
 /*
 * function:  sort edge in ascending order
 * return:    none
 * parameter: 1.the edge list; 2.function to compare
 * call:      none
 * called by: none
 */
void sort_gra_edge(EdgeList *edge_list, int(*is_bigger)(Elem, Elem));
 
/*
 * function:  seek a node by its number in the graph
 * return:    the target node's address, NULL means not found
 * parameter: 1.the adjacent list; 2.number of node
 * call:      none
 * called by: none
 */
GraNode* seek_node(AdjList *adj_list, int num);
 
/*
 * function:  traverse the graph and do something handler does
 * return:    none
 * parameter: 1.the adjacent list; 2.function pointer
 * call:      none
 * called by: none
 */
void traverse_gra(AdjList *adj_list, void(*handler)(GraNode *));

#endif
