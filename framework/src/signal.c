//
// Created by tywael on 2/12/23.
//

#include "libunit.h"

int catch_res(int signal)
{
    int status;

    if (WIFEXITED(signal))
        return WEXITSTATUS(signal);
    if (WIFSIGNALED(signal))
    {
        status = WTERMSIG(signal);
        if (status == SIGBUS)
            return (3);
        if (status == SIGSEGV)
            return (2);
        if (status == SIGABRT)
            return (4);
        if (status == SIGFPE)
            return (5);
        if (status == SIGPIPE)
            return (6);
        if (status == SIGILL)
            return (7);
    }
    return (-1);
}