#include "monty.h"


/**
 * node_add - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line_n: line number of of the opcode.
 */

void node_add(stack_t **new_node, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp_node = head;
	head = *new_node;
	head->next = tmp_node;
	tmp_node->prev = head;
}


/**
 * print - prints a nodes
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: line number .
 */
void print(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp_node;

	(void) line_n;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		printf("%d\n", tmp_node->n);
		tmp_node = tmp_node->next;
	}
}

/**
 * pop - deletes node .
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: line number.
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL)
		error_message_v2(7, line_n);

	tmp_node = *stack;
	*stack = tmp_node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp_node);
}

/**
 * print_top - Prints the top node.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: line number of  the opcode.
 */
void print_top(stack_t **stack, unsigned int line_n)
{
	if (stack == NULL || *stack == NULL)
		error_message_v2(6, line_n);
	printf("%d\n", (*stack)->n);
}
