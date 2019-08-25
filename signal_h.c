#include "shell.h"

/**
 * signal_check - function that checks the signal
 * @sig: Signal
 * Return: nothing
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
