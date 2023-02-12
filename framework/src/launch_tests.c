#include "libunit.h"

static void do_test(t_unit_test *testlist)
{
	while (testlist)
	{
		testlist->result = testlist->test_function();
		testlist = testlist->next;
	}
}

static void print_result(t_unit_test *testlist)
{
	while (testlist)
	{
		ft_putstr_fd("strlen : ", 1);
		ft_putstr_fd(testlist->test_name, 1);
		ft_putstr_fd(" : ", 1);
		if (testlist->result == OK)
			ft_putstr_fd("[OK]\n", 1);
		else if (testlist->result == KO)
			ft_putstr_fd("[KO]\n", 1);
		testlist = testlist->next;
	}
}

int launch_tests(t_unit_test **testlist)
{
	ft_putstr_fd("launch_tests\n", 1);
	do_test(*testlist);
	print_result(*testlist);
	ft_putstr_fd("end launch_tests\n", 1);
	return (0);
}
