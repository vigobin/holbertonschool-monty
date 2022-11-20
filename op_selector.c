#include "monty.h"

/**
 *
 *
 *
 *
 *
 */

void(*op_selector(line_t, data_t *))(stack_t **.unsigned int)
{
	unsigned int i = 0;
	instruction_t ops [] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, line.content[0]) == 0)
		{
			push_check(line, meta, ops[i].opcode);
			if (arg.flag == 1 &&
			strcmp(ops[i].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (qpush);
			}
			free(line.content);
			return (ops[i].f);
		}

		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	line.content[0]);
	free(line.content);
	free(data->buf);
	free_stack(&(data->stack));
	fclose(data->file);
	free(data);
	exit(EXIT_FAILURE);
}
