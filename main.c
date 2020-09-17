#include "monty.h"

/**
 * main - Start of the program
 * @argc: numbers of arguments
 * @argv: arguments vector
 * Return: 0
 */
int Number_entered = 0;

int main(int argc, char **argv)
{
	char *buffer = NULL, *opcode, *Number;
	stack_t *stc = NULL;
	size_t size = 1;
	FILE *monty;
	int i = 0;
	unsigned int line_num = 0;
	ssize_t get = 0;

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
		if (buffer != NULL)
			free(buffer);
		buffer = NULL;
		get = getline(&buffer, &size, monty);
		if (get == -1)
		{
			free(buffer);
			fclose(monty);
			exit(EXIT_FAILURE);
		}
		line_num++;
		opcode = strtok(buffer, " \n");
		if (strcmp(opcode, "push") == 0)
		{
			Number = strtok(NULL, " \n");
			if (Number == NULL)
			{
				fprintf(stderr,"L%d: usage: push integer",line_num);
				free(buffer);
				fclose(monty);
				exit(EXIT_FAILURE);
			}
			for(; Number[i] != '\0'; i++)
			{
				if(isdigit(Number[i]) == 0)
				{
					fprintf(stderr,"L%d: usage: push integer",line_num);
					free(buffer);
					fclose(monty);
					exit(EXIT_FAILURE);
				}
			}
			Number_entered = atoi(Number);
		}
		get_op(opcode, &stc, line_num);
	}
	/* Free memory and close the file */
	free(buffer);
	fclose(monty);
	return (0);
}
