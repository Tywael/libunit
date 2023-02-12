#include "libunit.h"
#include "tests.h"

int function_launcher(void)
{
	t_unit_test *testlist = 0;

	load_test(&testlist, "a test function", &a_test_function);
	load_test(&testlist, "another test function", &another_test_function);
    load_test(&testlist, "crash test function", &crash_test_function);
	return(launch_tests(&testlist));
}
