#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point for the intrepreter
 * @argc: number of arguments
 * @argv: the arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
		error_message_v1(1);
	access_file(argv[1]);
	free_allocated_nodes();
	return (0);
}
