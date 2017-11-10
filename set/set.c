/*
 *  set
 *
 *
 *
 *  (C)    2015-5    Yuanda Zhang
 */
#include "set.h"

int init_set(pSet set)
{
	return init_list(set);
}

pSetElem add_elem(pSet set, ElemInfo added_elem)
{
	pSetElem new_elem = NULL;

	if ( seek_elem(set, &added_elem) == NULL )
	{
		new_elem = new_node_back(set);
		assign_value(new_elem, &added_elem, sizeof(added_elem));
	}

	return new_elem;
}

pSet union_set(pSet pri_set, pSet scnd_set)
{
	pSet union_set = malloc(sizeof(Set));
	pSetElem temp_elem;
	pElemInfo temp_elem_data;

	if ( init_set(union_set) != 0 )
	{
		temp_elem = list_head(pri_set);
		while ( is_valid_node(temp_elem, pri_set) )
		{
			temp_elem = next_list_node(temp_elem);
			temp_elem_data = data_elem(temp_elem);
			add_elem(union_set, *temp_elem_data);
		}

		temp_elem = list_head(scnd_set);
		while ( is_valid_node(temp_elem, scnd_set) )
		{
			temp_elem = next_list_node(temp_elem);
			temp_elem_data = data_elem(temp_elem);
			if ( seek_elem(union_set, temp_elem_data) == NULL )
				add_elem(union_set, *temp_elem_data);
		}
	}

	return union_set;
}

pSet intersect_set(pSet pri_set, pSet scnd_set)
{
	pSet inter_set = malloc(sizeof(Set));
	pSetElem temp_elem;
	pElemInfo temp_data;

	if ( init_set(inter_set) != 0 )
	{
		temp_elem = list_head(pri_set);
		while ( is_valid_node(temp_elem, pri_set) )
		{
			temp_elem = next_list_node(temp_elem);
			temp_data = data_list_node(temp_elem, pElemInfo);
			if ( seek_elem(scnd_set, temp_data) != NULL )
				add_elem(inter_set, *temp_data);
		}
	}

	return inter_set;
}

int equal_set(pSet pri_set, pSet scnd_set)
{
	pSetElem temp;
	int ret = 1;

	if ( pri_set->length == scnd_set->length )
	{
		temp = list_head(pri_set);
		while ( is_valid_node(temp, pri_set) )
		{
			temp = next_list_node(temp);
			if ( seek_elem(scnd_set, data_elem(temp)) == NULL )
			{
				ret = 0;
				break;
			}
		}
	}
	else
		ret = 0;

	return ret;
}

int delete_elem(pSet set, pSetElem target_elem)
{
	return delete_node(set, target_elem);
}

void delete_set(pSet set)
{
	free_list(set);
}

pSetElem seek_elem(pSet set, pElemInfo seek_value)
{
	/*pSetElem temp;
	pSetElem ret = NULL;

	temp = list_head(set);
	while ( is_valid_node(temp, set) )
	{
		temp = next_list_node(temp);
		if ( data_elem(temp)->num == seek_value->num )
		{
			ret = temp;
			break;
		}
	}

	return ret;*/
	return seek_by_value(set, seek_value, compare);
}

static int compare(void *tar, void *value)
{
	return ((pElemInfo)(tar))->num == ((pElemInfo)(value))->num;
}

void print_set(pSet set)
{
	print_list(set, print);
}

static void print(pSetElem elem)
{
	ElemInfo temp = *data_elem(elem);

	printf("elem num:%d\n", temp.num);
}