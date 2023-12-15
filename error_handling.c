#include "monty.h"

/**
 * error_message_v1 - prints different error massages
 * @error_flag: numeric flag of the error
 */

void error_message_v1(int error_flag, ...)
{
	va_list ag;
	char *op;
	int line_n;

	va_start(ag, error_flag);
	switch (error_flag)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_n = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_allocated_nodes();
	exit(EXIT_FAILURE);
}

/**
 * error_message_v2 - prints more errors
 * @error_code: number code of the error
 */

void error_message_v2(int error_flag, ...)
{
	va_list ag;
	char *op;
	int line_n;

	va_start(ag, error_flag);
	switch (error_flag)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_n = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_allocated_nodes();
	exit(EXIT_FAILURE);
}
/**
 * error_message_v3 - handles string related errors
 * @error_flag: numeric error value
 */

void error_message_v3(int error_flag, ...)
{
	va_list ag;
	int line_n;

	va_start(ag, error_flag);
	line_n = va_arg(ag, int);
	switch (error_flag)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
			break;
		default:
			break;
	}
	free_allocated_nodes();
	exit(EXIT_FAILURE);
}
