/*
 *  doubly linked list(with guard) implementation
 *
 *
 *  (C)    2015-4    Yuanda Zhang
 */
 
#include "adj_list.h"

int init_gra(AdjList *adj_list)
{
	return init_list(adj_list);	
}

int init_edge_list(EdgeList *edge_list)
{
	return init_list(edge_list);	
}

GraNode* add_gra_node(AdjList *adj_list, int num)
{
	GraNode *temp = new_node_back(adj_list);
	Node data;
	
	if ( temp != NULL )
	{
		data.num = num;
		data.visited = 0;
		init_edge_list(&(data.edge_list));
		assign_value(temp, &data, sizeof(data));
	}
	
	return temp;
}
 
GraEdge* add_gra_edge(AdjList *adj_list, int from, int to, int power)
{
	GraEdge *temp;
	GraNode *src, *dst;
	Edge data;
	
	src = seek_node(adj_list, from);
	dst = seek_node(adj_list, to);
	if ( src == NULL )
		src = add_gra_node(adj_list, from);
	if ( dst == NULL )
		dst = add_gra_node(adj_list, to);
	
	temp = new_node_back( get_edgelist(data_gra_node(src)) );
	if ( temp != NULL )
	{
		data.power = power;
		data.from = src;
		data.to = dst;
		assign_value(temp, &data, sizeof(data));
	}

	return temp;
}
 
void delete_gra(AdjList *adj_list)
{
	GraNode *death_node = adjlist_head(adj_list);
	EdgeList *temp;
	
	while ( death_node->next != adj_list->tail )
	{
		death_node = death_node->next;
		temp = get_edgelist(data_gra_node(death_node));
		free_list(temp);
	}
	free_list(adj_list);
}

void sort_gra_node(AdjList *adj_list, int(*is_bigger)(Elem, Elem))
{
	sort_on_list(adj_list, is_bigger);
}
 
void sort_gra_edge(EdgeList *edge_list, int (*is_bigger)(Elem, Elem))
{
	sort_on_list(edge_list, is_bigger);	
}
 
GraNode* seek_node(AdjList *adj_list, int num)
{
	GraNode *target_node = adjlist_head(adj_list);
	GraNode *ret = NULL;

	while ( is_valid_node(target_node, adj_list) )
	{
		target_node = next_gra_node(target_node);
		if ( gra_node_num(data_gra_node(target_node)) == num )
		{
			ret = target_node;
			break;
		}
	}

	return ret;
}

void traverse_gra(AdjList *adj_list, void(*handler)(GraNode *))
{
	GraNode *main_route = adjlist_head(adj_list);
	GraEdge *scnd_route;
	EdgeList *temp;
	
	while ( is_valid_node(main_route, adj_list) )
	{
		main_route = next_gra_node(main_route);
		if ( !is_node_visited(data_gra_node(main_route)) )
			handler(main_route);
		data_gra_node(main_route)->visited = 1;
			
		temp = get_edgelist(data_gra_node(main_route));
		scnd_route = edgelist_head(temp);
		while ( is_valid_edge(scnd_route, temp) )
		{
			scnd_route = next_gra_edge(scnd_route);
			if ( !is_node_visited(data_gra_node(edge_to(data_gra_edge(scnd_route)))) )
				handler(((Edge *)(scnd_route->data))->to);
			data_gra_node( (edge_to(data_gra_edge(scnd_route))) )->visited = 1;
		}
	}
}
