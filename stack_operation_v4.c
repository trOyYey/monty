#include "monty.h"

/**
 * print_character - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: the line number.
 */

void print_character(stack_t **stack, unsigned int line_n)
{
	int ASCII;

	if (stack == NULL || *stack == NULL)
		error_message_v3(11, line_n);

	ASCII = (*stack)->n;
	if (ASCII < 0 || ASCII > 127)
		error_message_v3(10, line_n);
	printf("%c\n", ASCII);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: the line number .
 */

void print_string(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	int ASCII;
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp_node = *stack;
	while (tmp_node != NULL)
	{
		ASCII = tmp_node->n;
		if (ASCII <= 0 || ASCII > 127)
			break;
		printf("%c", ASCII);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node to the bottom.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: the line number.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	(*stack)->prev = tmp_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: the line number .
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int line_n)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp_node = *stack;

	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *stack;
	tmp_node->prev->next = NULL;
	tmp_node->prev = NULL;
	(*stack)->prev = tmp_node;
	(*stack) = tmp_node;
}
