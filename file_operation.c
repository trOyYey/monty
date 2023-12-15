#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * access_file - open file to access it's content
 * @file_name: file name
 * Return: void
 */

void access_file(char *file_name)
{
	FILE *file_content = fopen(file_name, "r");

	if (file_name == NULL || file_content == NULL)
		error_message_v1(2, file_name);

	scan_file(file_content);
	fclose(file_content);
}

/**
 * scan_file - look inside file
 * @file_content: pointer to file descriptor
 * Return: void
 */

void scan_file(FILE *file_content)
{
	int line_n, mode = 0;
	char *BUFFER = NULL;
	size_t lenght = 0;

	for (line_n = 1; getline(&BUFFER, &lenght, file_content) != -1; line_n++)
	{
		mode = parse(BUFFER, line_n, mode);
	}
	free(BUFFER);
}

/**
 * match_operation - matches the appropriate function for the operation code
 * @opcode: operation code
 * @arguments: arguments of the operation code
 * @mode: storage mode, 1 for queue and 0 for stack
 * @line_n: line number
 * Return: void
 */

void match_operation(char *opcode, char *arguments, int line_n, int mode)
{
	int i;
	int tag;

	instruction_t operation_list[] = {
		{"push", node_add},
		{"pall", print},
		{"pint", print_top},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nod},
		{"mul", mul_nod},
		{"mod", mod_nod},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (tag = 1, i = 0; operation_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, operation_list[i].opcode) == 0)
		{
			call_operation(operation_list[i].f, opcode, arguments, line_n, mode);
			tag = 0;
		}
	}
	if (tag == 1)
		error_message_v1(3, line_n, opcode);
}

/**
 * parse - tokenize each line to match the operation code
 * @BUFFER: line inside the file
 * @line_n: line number
 * @mode: 1 for queue 0 for stack
 * Return: mode
 */

int parse(char *BUFFER, int line_n, int mode)
{
	char *operation_code, *arguments;
	const char *delim = "\n ";

	if (BUFFER == NULL)
		error_message_v1(4);

	operation_code = strtok(BUFFER, delim);
	if (operation_code == NULL)
		return (mode);
	arguments = strtok(NULL, delim);

	if (strcmp(operation_code, "stack") == 0)
		return (0);
	if (strcmp(operation_code, "queue") == 0)
		return (1);

	match_operation(operation_code, arguments, line_n, mode);
	return (mode);
}

/**
 * call_operation - calls for the matched operation
 * @function: pointer to function
 * @op: operation code string
 * @arguments: numbers as string
 * @line_n: line number
 * @mode: 1 for queue ,0 for stacks
 */

void call_operation(op_func function, char *op
		, char *arguments, int line_n, int mode)
{
	stack_t *node;
	int tag;
	int i;

	tag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (arguments != NULL && arguments[0] == '-')
		{
			arguments = arguments + 1;
			tag = -1;
		}
		if (arguments == NULL)
			error_message_v1(5, line_n);
		for (i = 0; arguments[i] != '\0'; i++)
		{
			if (isdigit(arguments[i]) == 0)
				error_message_v1(5, line_n);
		}
		node = New_node(atoi(arguments) * tag);
		if (mode == 0)
			function(&node, line_n);
		if (mode == 1)
			queue_add(&node, line_n);
	}
	else
		function(&head, line_n);
}
