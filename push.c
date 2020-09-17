#include "monty.h"

/**
 * push - adds a node with the value token on the stack
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: address of the new node
 */

stack_t *(*get_op(char *buffer, stack_t **head,  __attribute__((unused))unsigned int line_number))(stack_t
**stack, unsigned int line_number)
{
	instruction_t selector[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *compare;
	int i = 0;

	while (selector[i].opcode != NULL)
	{
		compare = (selector[i]).opcode;
		if (strcmp(buffer, compare) == 0)
		{
			return (*(selector[i]).f);
		}
		i++;
	}

	free(head);
	exit(EXIT_FAILURE);

}
stack_t *push(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node;

	/* Create new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	/* Initialize the new node with the value of token */
	new_node->n = Number_entered;
	/* New node is placed at the beginning of the list */
	new_node->prev = NULL;
	new_node->next = *stack;

	/* If new node is not alone, update the following one */
	if (*stack != NULL)
		(*stack)->prev = new_node;

	/* head points to the new node */
	*stack = new_node;

	return (new_node);
}
