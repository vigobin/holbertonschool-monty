#include "monty.h"

/**
 * pop - pop head value of stack.
 * @h: head of stack.
 * @ln: line number.
 */

void pop(stack_t **h, unsigned int ln)
{
	stack_t *temp = *h;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		isFail = 1;
		return;
	}
	*h = (*h)->next;
	free(temp);

}
/**
 * swap - swap 2 most recent nodes on stack
 *
 * @h: head of stack
 * @ln: line number
 * Return: void
 */
void swap(stack_t **h, unsigned int ln)
{
	stack_t *temp;
	int x;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		isFail = 1;
		return;
	}
	temp = (*h)->next;
	x = (*h)->n;
	(*h)->n = temp->n;
	temp->n = x;

}
