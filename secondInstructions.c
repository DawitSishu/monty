#include "monty.h"

/**
* _queue - sets the format of the data to a queue (FIFO)
* @doubly: head of the linked list
* @cline: line number;
*/
void _queue(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;
vglo.lifo = 0;
}

/**
* _stack - sets the format fo the data to a stack (LIFO)
* @doubly: linked list head
* @cline: number of line
*/
void _stack(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;
vglo.lifo = 1;
}

/**
* _add - adds the top two elements of the stack
* @doubly: linked list head
* @cline: number of line
*/
void _add(stack_t **doubly, unsigned int cline)
{
int num = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, num++)
;
if (num < 2)
{
dprintf(2, "L%u: can't add, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = (*doubly)->next;
hlper->n += (*doubly)->n;
_pop(doubly, cline);
}

/**
* _nop - doesn't do anythinhg
* @doubly: linked list head
* @cline: number of line
*/
void _nop(stack_t **doubly, unsigned int cline)
{
(void)doubly;
(void)cline;
}

/**
* _sub - subtracts the top element to the second top element of the stack
* @doubly: linked list head
* @cline: number of line
*/
void _sub(stack_t **doubly, unsigned int cline)
{
int num = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, num++)
;
if (num < 2)
{
dprintf(2, "L%u: can't sub, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = (*doubly)->next;
hlper->n -= (*doubly)->n;
_pop(doubly, cline);
}
