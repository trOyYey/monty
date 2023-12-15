#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_n: line number.
 */

void nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}


/**
 * swap - swaps top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: line number.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	stack_t *tmp_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_message_v2(8, line_n, "swap");
	tmp_node = (*stack)->next;
	(*stack)->next = tmp_node->next;
	if (tmp_node->next != NULL)
		tmp_node->next->prev = *stack;
	tmp_node->next = *stack;
	(*stack)->prev = tmp_node;
	tmp_node->prev = NULL;
	*stack = tmp_node;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top.
 * @line_n: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_n)
{
	int totall;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_message_v2(8, line_n, "add");

	(*stack) = (*stack)->next;
	totall = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = totall;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - subtract the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: line number.
 */
void sub_nodes(stack_t **stack, unsigned int line_n)
{
	int totall;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_message_v2(8, line_n, "sub");


	(*stack) = (*stack)->next;
	totall = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = totall;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div - divides the top two elements.
 * @stack: Pointer to a pointer pointing to top node .
 * @line_n: the line number.
 */
void div_nod(stack_t **stack, unsigned int line_n)
{
	int totall;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_message_v2(8, line_n, "div");

	if ((*stack)->n == 0)
		error_message_v2(9, line_n);
	(*stack) = (*stack)->next;
	totall = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = totall;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
