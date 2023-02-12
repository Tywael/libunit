#include "libunit.h"
#include "utils.h"

static void do_test(t_unit_test *testlist)
{
	testlist->result = testlist->test_function();
}

static void print_result(t_unit_test *testlist)
{
	ft_putstr_fd("function : ", 1);
	ft_putstr_fd(testlist->test_name, 1);
	ft_putstr_fd(" : ", 1);
	if (testlist->result == OK)
		ft_putstr_fd("[OK]\n", 1);
	else if (testlist->result == KO)
		ft_putstr_fd("[KO]\n", 1);
}

static void free_node(t_unit_test *testlist)
{
	free(testlist->test_name);
	free(testlist);
}

static void last_line(t_unit_test *testlist)
{
	int	tests;
	int success;

	tests = 0;
	success = 0;
	while (testlist && ++tests && (testlist->result || ++success))
		testlist = testlist->next;
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(success, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(tests, 1);
	ft_putstr_fd(" tests checked\n", 1);
}

int launch_tests(t_unit_test **testlist)
{
	iter_list(*testlist, &do_test);
	iter_list(*testlist, &print_result);
	last_line(*testlist);
	iter_list(*testlist, &free_node);
	return (0);
}
