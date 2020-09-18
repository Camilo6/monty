#include "monty.h"
/**
 * free_s - frees the stack
 * @stack: pointer to the stack
 * Return: Nothing
 */
void frees(stack_t **stack)
{
	stack_t *head;
	stack_t *tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
