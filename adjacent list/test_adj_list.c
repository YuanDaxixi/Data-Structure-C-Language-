/*
 *  doubly linked list(with guard) implementation
 *
 *
 *  (C)    2015-4    Yuanda Zhang
 */
 
#include "adj_list.h"

#define MAX 10

int is_bigger(Elem, Elem);
void print_node(GraNode *);

int main(void)
{
	AdjList graph;
	int i, from, to, power;
	
	init_gra(&graph);
	for ( i = 0; i < MAX; i++)
	{
		scanf("%d %d %d", &from, &to, &power);
		add_gra_edge(&graph, from, to, power );
	}
	sort_gra_node(&graph, is_bigger);
	traverse_gra(&graph, print_node);
	delete_gra(&graph);
	system("pause");
	
	return 0;
}

int is_bigger(Elem prev, Elem key)
{
	return ((Node *)prev)->num > ((Node *)key)->num;
}

void print_node(GraNode *tar)
{
	Node *temp = tar->data;
	
	printf("num:%d\n", temp->num);
}
