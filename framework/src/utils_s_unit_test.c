#include "libunit.h"

void iter_list(t_unit_test *testlist, void (*f)(t_unit_test *))
{
	while (testlist)
	{
		f(testlist);
		testlist = testlist->next;
	}
}
