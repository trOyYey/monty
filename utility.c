#include "monty.h"

/**
 * New_node - creates new node
 * @n: data number inside the node
 * Return: pointer to node, or NULL
 */

stack_t *New_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_message_v1(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
 * free_allocated_nodes - Frees nodes in the stack.
 */

void free_allocated_nodes(void)
{
	stack_t *tmp_node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp_node = head;
		head = head->next;
		free(tmp_node);
	}
}

/**
 * queue_add - adds node to queue
 * @new_node: new node pointer
 * @line_n: line number
 */

void queue_add(stack_t **new_node
		, __attribute__((unused))unsigned int line_n)
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
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;

	tmp_node->next = *new_node;
	(*new_node)->prev = tmp_node;
}
