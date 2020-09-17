#include "monty.h"

/* Initialize the global variable */
int Number_entered = 1;

/**
 * main - Interprets bytecode
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, *opcode, *Number_string;
	size_t size = 1;
	FILE *monty;
	unsigned int line_number = 0, i = 0;
	ssize_t get = 0;
	stack_t *stc;

	stc = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}


	/* Open File with the bytecodes */
	monty = fopen(argv[1], "r");
	if (monty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read file line by line */
	while (get != EOF)
	{
		Number_entered = 1;
		i = 0;
		if (buffer != NULL)
			free(buffer);
		buffer = NULL;

		get = getline(&buffer, &size, monty);

		if (get == -1)
		{
			free(buffer);
			if (stc != NULL)
				free(stc);
			fclose(monty);
			return (0);
		}

		/* Keep count of the number of lines */
		line_number++;

		/* Parse the first elements of the line */
		opcode = strtok(buffer, " \n");

		if (strcmp(opcode, "push") == 0)
		{
			/* Parse the second elements of the line */
			Number_string = strtok(NULL, " \n");

			if (Number_string == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
				free(buffer);
				free(stc);
				fclose(monty);
				exit(EXIT_FAILURE);
			}


			for (; Number_string[i] != '\0'; i++)
			{
				if (isdigit(Number_string[i]) == 0)
				{
					fprintf(stderr,
						"L%d: usage: push integer\n",
						line_number);
					free(buffer);
					free(stc);
					fclose(monty);
					exit(EXIT_FAILURE);
				}
			}

			Number_entered = atoi(Number_string);
		}
		get_op(opcode, &stc, line_number)(&stc, line_number);
	}
	/* Free memory and close the file */
	free(buffer);
	free(stc);
	fclose(monty);

	return (0);
}
