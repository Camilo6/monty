#include "monty.h"

/**
 * get_op - look for the feature that's needed
 * @head: pointer to the list stack
 * @bf: is a buffer
 * @lin_m: unused variable
 * Return: address of the new node
 */

stack_t *(*get_op(char *bf, stack_t **head, unsigned int lin_m))(stack_t **head, unsigned int line_number)
{
	instruction_t selector[] = {
		{"sub", sub},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"pop", pop},
		{"pint", pint},
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *compare;
	int i = 0;

	while (selector[i].opcode != NULL)
	{
		compare = (selector[i]).opcode;
		if (strcmp(bf, compare) == 0)
		{
			return (*(selector[i]).f);
		}
		i++;
	}

	fprintf(stderr, "%d: unknown instruction %s\n", lin_m, bf);
	free(head);
	exit(EXIT_FAILURE);

}
