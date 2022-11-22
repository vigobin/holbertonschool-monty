#include "monty.h"

/**
 * op_selector - selects the correct function for the corresponding opcode
 *
 * @str: opcode command
 * Return: function pointer
 */


void (*op_selector(char *str))(stack_t **stack, unsigned int line_number)
{
        instruction_t ops[] = {
                {"push", push},
                {"pall", pall},
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}
        };
        unsigned int i = 0;

        while (ops[i].opcode && strcmp(str, ops[i].opcode) != 0)
                i++;
        if (ops[i].opcode == NULL)
                return (NULL);
        return (ops[i].f);
}
