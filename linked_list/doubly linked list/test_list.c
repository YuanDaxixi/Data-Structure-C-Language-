/*
 *  test for single linked list
 *
 *  (C)    2015-4    Yuanda Zhang
 */

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

#define flush_buffer() while ( getchar() != '\n' )continue

#define flush_surface() flush_buffer();system("cls")

static void wel_info(void);
static void select_func(void);
static void bye_bye(void);
static void func_list(void);

static void seal_init_list(DLinkedList *p_list);
static void seal_new_node_back(DLinkedList *p_list);
static void seal_insert_node_back(DLinkedList *p_list);
static void seal_seek_by_value(DLinkedList *p_list);
static void seal_assign_value(DLinkedList *p_list);
static void seal_delete_node(DLinkedList *p_list);
static void seal_invert_list(DLinkedList *p_list);
static void seal_print_list(DLinkedList *p_list);
static void seal_sort_list(DLinkedList *p_list);
static void seal_free_list(DLinkedList *p_list);

static int is_same(Elem node_value, Elem);
static void print(pDListNode node);
static int is_bigger(Elem node_value, Elem);

int main(void)
{
	wel_info();
	select_func();
	bye_bye();

	return 0;
}

static void wel_info(void)
{
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");
	printf("Welcome to the test for doubly linked list interface.\n");
	printf("Number shown below to choose function.\n\n");
}

static void func_list(void)
{
	putchar('\n');
	printf("       1.create a new list       ""       2.add new nodes       \n\n");
	printf("       3,insert a node           ""       4.seek a node         \n\n");
	printf("       5.assign value to node    ""       6.invert the list     \n\n");
	printf("       7.print the list          ""       8.sort the list       \n\n");
	printf("       9.delete a node           ""       0.delete the list   \n\n\n");
	printf("Any other character leading to quit,now please enter a number above:");
}

static void select_func(void)
{
	int option;
	DLinkedList num_list = {NULL,NULL};

	while ( 1 )
	{
		func_list();
		if ( scanf("%d", &option) == 0 || option < 0 || option > 9 )
			break;
		flush_buffer();

		switch ( option ){
		case 1:
			seal_init_list(&num_list); break;
		case 2:
			seal_new_node_back(&num_list); break;
		case 3:
			seal_insert_node_back(&num_list); break;
		case 4:
			seal_seek_by_value(&num_list); break;
		case 5:
			seal_assign_value(&num_list); break;
		case 6:
			seal_invert_list(&num_list); break;
		case 7:
			seal_print_list(&num_list); break;
		case 8:
			seal_sort_list(&num_list); break;
		case 9:
			seal_delete_node(&num_list); break;
		case 0:
			seal_free_list(&num_list); break;
		default:
			break;
		}

		flush_surface();
		printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");
	}
}

static void bye_bye(void)
{
	printf("\n\nIt must be a amazing journey in a doubly linked list!\n");
	printf("If you find any BUG,dial 110 for help.\n");
	printf("Having a good day,byebye!!!\n");
	printf("\n****************************TEST_DOUBLY_LINKED_SHIT****************************\n");
	system("pause");
}

static void seal_init_list(DLinkedList *p_list)
{
	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head != NULL )
		printf("You initialized the list before,go to do something else.\n");
	else if ( p_list != NULL )
		if ( init_list(p_list) )
			printf("I have initialized the list for you,now you may operate on it.\n");
		else
			printf("initilization fails,but it's not my ungeilivable but windows!\n");
	else
		printf("Holy shit!What a fucking pointer you give me!\n");
	printf("Press ENTER back to menu,don't stay here like a idiot.");
}

static void seal_new_node_back(DLinkedList *p_list)
{
	int node_cnt = 0;
	int i = 0;

	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("Tell me,how many new nodes do you want? Write it down:");
		if ( scanf("%d", &node_cnt) != 1 || node_cnt <= 0 )
		{
			printf("Hey young man,enter a postive number,it's not fun!\n");
			printf("Your petty trick doesn't work on me,nothing would be added.\n");
		}
		for ( i = 0; i < node_cnt; i++ )
			if ( new_node_back(p_list) == NULL )
			{
				printf("Oh!The blamed windows must BUG again,fail to add nodes.\n");
				break;
			}
		flush_buffer();
	}

	if ( i != 0 && i == node_cnt )
		printf("Congratulations!Nodes you asked have been added.Thank me!\n");

	printf("ENTER is waiting for you all the time.");
}

static void seal_insert_node_back(DLinkedList *p_list)
{
	int i;
	int src_index, dst_index;
	pDListNode src, dst;

	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("Enter the source and destination index:");
		if ( scanf("%d %d", &src_index, &dst_index) == 2 && src_index > 0 && dst_index >= 0)
		{
			for ( src = p_list->head, i = 0; i < src_index && src != p_list->tail; i++ )
				src = src->next;
			for ( dst = p_list->head, i = 0; i < dst_index && dst != p_list->tail; i++ )
				dst = dst->next;

			if ( src == p_list->tail || dst == p_list->tail )
			{
				printf("You enter so big a index that the list crys.\n");
			}
			else
			{
				insert_node_back(p_list, src, dst);
				printf("Success in inserting,back to the menu.\n");
			}
		}
		else
		{
			printf("You may have enterd something not numbers or wrong index.\n");
			printf("source index must >0,and destination must >=0.\n");
		}
		flush_buffer();
	}

	printf("When you are confused,press ENTER.");
}

static void seal_seek_by_value(DLinkedList *p_list)
{
	int data;
	pDListNode p_node;

	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("Enter a number I find it in the node.\n");
		if ( scanf("%d", &data) != 1 )
		{
			printf("Number pleaese,How fool you are!\n");
		}
		else
		{
			p_node = seek_by_value(p_list, &data, is_same);
			if ( p_node == NULL )
				printf("I can't find the number in the list.You must do someting wrong.\n");
			else
				printf("The address of node saving the value is %p,you may find by it.\n", p_node);
		}
		flush_buffer();
	}

	printf("Find the address? Anyway,now you need ENTER.");
}

static void seal_assign_value(DLinkedList *p_list)
{
	int data;
	pDListNode node;

	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else if ( p_list->head->next == p_list->tail )
	{
		printf("There is no node in the list,your action is dangerous!\n");
	}
	else
	{
		printf("At the beginning,I announce a bad new that you can only assign value to the last node.\n");
		printf("If you are not satisfied with the decision,come to bite me.\n");
		printf("And if you have any discontentment,speak out:");
		while ( getchar() != '\n' )continue;
		printf("OK,it seems you accept my proposal(rule),to show my generosity,I teach you a trick\n");
		printf("You may move the node to the end then assign value.Enter number:");

		if ( scanf("%d", &data) != 1 )
		{
			printf("Why there are so many people like going against me!Only NUMBER!!!\n");
		}
		else
		{
			node = p_list->tail->prev;
			if ( assign_value(node, &data, sizeof(data)) == 0 )
				printf("God knows what mistake occurs.Mission failure.\n");
			else
				printf("Mission complete,I'm so capable!\n");
		}
		flush_buffer();
	}

	printf("Get out here! ENTER is the door.");
}

static void seal_delete_node(DLinkedList *p_list)
{
	int i, index;
	pDListNode node = p_list->head;

	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("Enter node index, I delete it:");
		while ( scanf("%d", &index) == 1 )
		{
			for ( i = 0; i < index && node != NULL; i++ )
				node = node->next;
			if ( delete_node(p_list, node) == NULL )
				printf("Your index is not legal,go self-examining for a day.\n");
			node = p_list->head;
			printf("Want to delete other nodes? Enter something not numbers to quit\n");
			printf("or enter index, I delete it:");
		}
		flush_buffer();
	}

	printf("You just attempted to kill nodes,so their brothers are looking for you.ENTER to escape.");
}

static void seal_invert_list(DLinkedList *p_list)
{
	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else if ( p_list->head->next == p_list->tail )
	{
		printf("There is no node in the list,you invert air?\n");
	}
	else
	{
		invert_list(p_list);
		printf("Clever I success doing another thing.\n");
		printf("Now your list's buttocks is head,head is buttocks.\n");
	}

	printf("Don't know what to do next? Why not knock ENTER?");
}

static void seal_print_list(DLinkedList *p_list)
{
	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
		printf("Only ENTER could save you.");
	}
	else
	{
		printf("Want to see the whole list? I can help you,see...\n");
		print_list(p_list, print);
		if ( p_list->head->next == p_list->tail )
			printf("You must be very sad now,because the list is empty! Try ENTER to show someting.");
		else
			printf("see enough? Press ENTER to continue.\n");	
	}
}

static void seal_sort_list(DLinkedList *p_list)
{
	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("My friend,I implement insert sort on the list,have interest to see?\n");
		sort_on_list(p_list, is_bigger);
		print_list(p_list,print);
		if ( p_list->head->next == p_list->tail )
			printf("Aha! See that? Nothing there!\n");
		else
			printf("Aha! See that? Unbelievable!\n");
	}

	printf("I'm tired of sorting,ENTER please.");
}

static void seal_free_list(DLinkedList *p_list)
{
	system("cls");
	printf("****************************TEST_DOUBLY_LINKED_LIST****************************\n\n");

	if ( p_list->head == NULL || p_list->tail == NULL )
	{
		printf("Your request is refused for the list having not been initialized.\n");
	}
	else
	{
		printf("My little poor list,this evil human abandons you,time to say good bye.\n");
		free_list(p_list);
		printf("On your demand I deleted the list,now go away,I don't want to see you again.\n");
	}

	printf("ENTER...");
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