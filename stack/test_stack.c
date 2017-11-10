#include "stack.h"

#define MAX 10

typedef struct{
	int value;
}TestData;

_push_prototype(TestData);
_pop_prototype(TestData);

int main(void)
{
	Stack stack_papa;
	TestData slave;
	int i;

	init_stack(&stack_papa);

	for ( i = 0; i < MAX; i++ )
	{
		slave.value = i;
		push_TestData(&stack_papa, &slave);
	}
	for ( i = 0; i < MAX; i++ )
		printf("The value of top: %d\n", pop_TestData(&stack_papa).value);

	delete_stack(&stack_papa);

	return 0;
}