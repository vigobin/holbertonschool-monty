#include "monty.h"

/**
 * parseline - tokenizes a line of text, storing it in line struct.
 * @line: struct containing line contents and line number.
 * @buffer: string of text read from script file.
 */

void parseline(line_t *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->contetn[i] = token;
		token = strtok(NULL, " \n");
	}
	line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time.
 * @file: the script to be read.
 */

void parsefile(FILE *file)
{
	size_t size = 0;
	data_t *data = NULL;
	line_t line;

	data = malloc(sizeof(data_t));
	if (!data)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;
	data->file = file;
	data->stack = NULL;
	data->buf = NULL;

	while (getline(&(data->buf), &size, data->file) != -1)
	{
		line.number++;
		parseline(&line, data->buf);
		if (line.content)
			op_selector(line, data)($(data->stack), line.number);
	}
	free(data->buf);
	free_stack(&(data->stack));
	fclose(data->file);
	free(data);
}
