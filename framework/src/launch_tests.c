#include "libunit.h"
#include "utils.h"

static void do_test(t_unit_test *testlist)
{
    pid_t pid;
    int sig;
    int res;

    testlist->result = unknown;
    pid = fork();
    if (!pid) {
        res = testlist->test_function();
        if (res == 1)
            exit(1);
        exit(0);
    }
    else
    {
        pid = wait(&sig);
        if (!pid)
            return ;
        testlist->result = catch_res(sig);
    }
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
    else if (testlist->result == sigsegv)
        ft_putstr_fd("[SEGV]\n", 1);
    else if (testlist->result == sigbus)
        ft_putstr_fd("[BUS]\n", 1);
    else if (testlist->result == sigabrt)
        ft_putstr_fd("[ABRT]\n", 1);
    else if (testlist->result == sigfpe)
        ft_putstr_fd("[FPE]\n", 1);
    else if (testlist->result == sigpip)
        ft_putstr_fd("[PIP]\n", 1);
    else if (testlist->result == sigill)
        ft_putstr_fd("[ILL]\n", 1);
    else
        ft_putstr_fd("\n", 1);
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
