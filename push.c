#include "monty.h"

stack_t *(*get_op(char *buffer, stack_t **list, __attribute__((unused))unsigned int line_number))(stack_t
**stack, unsigned int line_number)
{
    instruction_t selector[] = {
        {"push", push},
        {"pall",pall},
        {NULL, NULL}
    };
    int i = 0;
    while (i < 2)
    {
        if (selector[i].opcode[0] == buffer[0])
        {
            /* return that value */
            return (selector[i].f);
        }
        i++;
    }
    free(list);
    exit(EXIT_FAILURE);
}
stack_t *push(stack_t **list,
          unsigned int line_number __attribute__((unused)))
{
    stack_t *new_node;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(list);
        exit(EXIT_FAILURE)
    *list = new_node;
    return (list);
}
