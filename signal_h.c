#include "shell.h"

void signal_check(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n(o o) ", 7);
}

/**
 * set_to_catch - change signal to be caught
 * Return: nothing
 */
void signal_h(void)
{
	signal(SIGINT, signal_check);
}
