#include "monty.h"

/**
 * 
 * 
 * 
 */

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void) line_number;


	while (head != NULL)
	{
		printf("LLEGA");
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}