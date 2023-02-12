#include "libunit.h"

static void append_node(t_unit_test *testlist, t_unit_test *new)
{
	while (testlist->next)
	{
		testlist = testlist->next;
	}
	testlist->next = new;
}

void load_test(t_unit_test **testlist, const char * name, int (*function_test)(void))
{
	t_unit_test *new;

	ft_putstr_fd("load_test\n", 1);
	new = malloc(sizeof(t_unit_test));
	new->test_name = ft_strdup(name);
	new->test_function = function_test;
	new->next = 0;
	if (*testlist == 0)
		*testlist = new;
	else
		append_node(*testlist, new);
}
