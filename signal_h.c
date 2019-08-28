#include "shell.h"

/**
 * signal_check - function that check if the signal correct
 * @sig: - integer signal
 */
void signal_check(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n(o o) ", 7);
}

/**
 * signal_h - change signal to be caught
 * Return: nothing
 */
void signal_h(void)
{
	signal(SIGINT, signal_check);
}
