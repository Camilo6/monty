#include "monty.h"

/**
 * pall - print all
 * @stack: ponter to the list stack
 * @line_number: unused variable
 * Return: the address of the first node
 */
stack_t *pall(stack_t **stack,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;

	if (*stack == NULL)
	{
		return (NULL);
	}

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

	return (*stack);
}

/**
 * get_op - adds a node with the value token on the stack
 * @head: ponter to the list stack
 * @line_number: unused variable
 * Return: address of the new node
 */

stack_t *push(stack_t **head,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *new_date;

	new_date = malloc(sizeof(stack_t));
	if (new_date == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(head);
		exit(EXIT_FAILURE);
	}
	new_date->n = Number_entered;
	new_date->prev = NULL;
	new_date->next = *head;

	if (*head != NULL)
		(*head)->prev = new_date;

	/* head points to the new node */
	*head = new_date;

	return (new_date);
}

/**
 * pop - removes the top element of the stack
 * @head: ponter to the list stack
 * @line_number: unused variable
 * Return: node free
 */

stack_t *pop(stack_t **head,
	      unsigned int line_number __attribute__((unused)))
{
	stack_t *new = *head;

	if (*head == NULL)
	{
		return (0);
	}
	if ((*head)->next == NULL)
	{
		free(new);
		*head = NULL;
		return (0);
	}
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(new);
	return (new);
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: ponter to the list stack
 * @line_number: unused variable
 * Return: stack
 */

stack_t *pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	return (tmp);
}

/**
 * add - adds the top two elements of the stack.
 * @stack: ponter to the list stack
 * @line_number: number line@stack
 * Return: stack edited
 */
stack_t *add(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *current_node = *stack;

	if (!current_node || !current_node->next)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}

	sum = (current_node->n) + (current_node->next->n);
	current_node->next->n = sum;
	pop(stack, 0);
	return (*stack);

}
