#include "libunit.h"

int a_test_function(void);
int another_test_function(void);

int strlen_launcher(void)
{
	ft_putstr_fd("strlen_launcher\n", 1);
	t_unit_test *testlist;

	load_test(&testlist, "a test function", &a_test_function);
	load_test(&testlist, "another test function", &another_test_function);
	return(launch_tests(&testlist));
}
