#include "monty.h"
int Number_entered = 1;
/**
 * main - Interprets bytecode
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
		if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	abrirarchivo(argv[1]);
	return (0);
}
