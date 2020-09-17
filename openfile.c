#include "monty.h"
/**
 * abrirarchivo - this function validate the status of the file
 * @file: file to open
 */
void abrirarchivo(char *file)
{
	char *buffer = NULL, *opcode, *Number_string;
	size_t size = 1;
	FILE *monty;
	unsigned int line_number = 0, i = 0;
	ssize_t get = 0;
	stack_t *stc = NULL;

	monty = fopen(file, "r");
	if (monty == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (get != EOF)
	{
		Number_entered = 1, i = 0;
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
			return;
		} line_number++;
		opcode = strtok(buffer, " \n");
		if (strcmp(opcode, "push") == 0)
		{
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
					fprintf(stderr,	"L%d: usage: push integer\n",
						line_number);
					free(buffer);
					free(stc);
					fclose(monty);
					exit(EXIT_FAILURE);
				}
			} Number_entered = atoi(Number_string);
		} get_op(opcode, &stc, line_number)(&stc, line_number);
	} free(buffer); 
	free(stc);
	fclose(monty);
}
