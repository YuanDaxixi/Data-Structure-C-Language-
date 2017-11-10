/*
*  test for set
*
*
*
*  (C)    2015-5    Yuanda Zhang
*/

#include "set.h"

int main(void)
{
	Set set_a;
	Set set_b;
	pSet pset_c;
	pSet pset_d;
	ElemInfo temp;

	init_set(&set_a);
	init_set(&set_b);
	temp.num = 1;
	add_elem(&set_a, temp);
	temp.num = 2;
	add_elem(&set_a, temp);
	add_elem(&set_b, temp);
	pset_c = union_set(&set_a, &set_b);
	pset_d = intersect_set(&set_a, &set_b);

	printf("set a:\n");
	print_set(&set_a);
	printf("set b:\n");
	print_set(&set_b);
	printf("set c:\n");
	print_set(pset_c);
	printf("set d:\n");
	print_set(pset_d);
	if ( equal_set(&set_a, pset_c) == 1 )
		printf("set a is same as set c\n");
	if ( equal_set(&set_a, pset_d) == 0 )
		printf("set a is not same as set d\n");

	delete_set(&set_a);
	delete_set(&set_b);
	delete_set(pset_c);
	delete_set(pset_d);
	free(pset_c);
	free(pset_d);

	return 0;
}