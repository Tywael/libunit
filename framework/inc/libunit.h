//
// Created by tywael on 2/10/23.
//

#ifndef LIBUNIT_LIBUNIT_H
#define LIBUNIT_LIBUNIT_H

#include <stdlib.h>
#include "../libft/inc/libft.h"

/* enumation result */
enum e_result
{
	OK,
	KO,
};
typedef enum e_result t_result;

/* structure unit_test */
struct s_unit_test
{
  int    (*test_function)(void);
  char    *test_name;

  enum e_result result;

  struct s_unit_test *next;
};
typedef struct s_unit_test t_unit_test;

/* load_test */
void load_test(t_unit_test **testlist, const char * name, int (*function_test)(void));

/* launch_test */
int launch_tests(t_unit_test **testlist);

#endif //LIBUNIT_LIBUNIT_H
