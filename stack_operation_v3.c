#include "monty.h"

/**
 * mul - multiplies the top two elements.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_n: the line number.
 */
void mul_nod(stack_t **stack, unsigned int line_n)
{
	int totall;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_message_v2(8, line_n, "mul");

	(*stack) = (*stack)->next;
	totall = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = totall;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod - calculates the mod of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: the line n.
 */
void mod_nod(stack_t **stack, unsigned int line_n)
{
	int totall;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		error_message_v2(8, line_n, "mod");


	if ((*stack)->n == 0)
		error_message_v2(9, line_n);
	(*stack) = (*stack)->next;
	totall = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = totall;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
