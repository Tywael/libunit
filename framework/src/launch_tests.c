#include "libunit.h"
#include "utils.h"

static void do_test(t_unit_test *testlist)
{
	testlist->result = testlist->test_function();
}

static void print_result(t_unit_test *testlist)
{
	ft_putstr_fd("strlen : ", 1);
	ft_putstr_fd(testlist->test_name, 1);
	ft_putstr_fd(" : ", 1);
	if (testlist->result == OK)
		ft_putstr_fd("[OK]\n", 1);
	else if (testlist->result == KO)
		ft_putstr_fd("[KO]\n", 1);
}

int launch_tests(t_unit_test **testlist)
{
	ft_putstr_fd("launch_tests\n", 1);
	iter_list(*testlist, &do_test);
	iter_list(*testlist, &print_result);
	ft_putstr_fd("end launch_tests\n", 1);
	return (0);
}
