#include "libunit.h"

int crash_test_function(void)
{
	ft_putstr_fd("another_test_function\n", 1);
    char *ptr;
    ptr = NULL;
    *ptr = 60;
	return (1);
}
