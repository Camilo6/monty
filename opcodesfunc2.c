#include "monty.h"

/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @head: ponter to the list stack
 * @line_number: number line
 * Return: node swapped
 */

stack_t *swap(stack_t **head, unsigned int line_number)
{
	stack_t *sw = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	sw = (*head)->next;
	(*head)->next = sw->next;
	(*head)->prev = sw;
	sw->next = *head;
	sw->prev = NULL;
	(*head)->next->prev = *head;
	*head = sw;
	return (sw);
}

/**
 * nop - opcode nop doesn't anything
 * @stack: is a stack
 * @line_number: line number in the file
 * Return: stack
 */

stack_t *nop(stack_t **stack, unsigned int line_number)
{
	stack_t *st = *stack;
	(void) line_number;
	return (st);
}

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stack: ponter to the list stack
 * @line_number: number line@stack
 * Return: stack edited
 */
stack_t *sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *current_node = *stack;

	if (!current_node || !current_node->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}

	diff = (current_node->next->n) - (current_node->n);
	abs(diff);
	current_node->next->n = diff;
	pop(stack, 0);
	return (*stack);
}
stack_t *mul(stack_t **stack, unsigned int line_number)
{
	int mul = 0;
	stack_t *current_node = *stack;

	if (!current_node || !current_node->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}

	mul = (current_node->next->n) * (current_node->n);
	current_node->next->n = mul;
	pop(stack, 0);
	return (*stack);

}
