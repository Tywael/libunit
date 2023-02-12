#include "libunit.h"

int a_test_function(void);
int another_test_function(void);

int strlen_launcher(void)
{
	t_unit_test *testlist = 0;

	load_test(&testlist, "a test function", &a_test_function);
	load_test(&testlist, "another test function", &another_test_function);
	load_test(&testlist, "a test function", &a_test_function);
	load_test(&testlist, "another test function", &another_test_function);
	load_test(&testlist, "a test function", &a_test_function);
	load_test(&testlist, "another test function", &another_test_function);
	return(launch_tests(&testlist));
}
