#include "monty.h"

/**
* _push - element to stack pusher
* @doubly: linked list head
* @cline: number of line
*/
void _push(stack_t **doubly, unsigned int cline)
{
int n, i;
if (!vglo.arg)
{
dprintf(2, "L%u: ", cline);
dprintf(2, "usage: push integer\n");
free_vglo();
exit(EXIT_FAILURE);
}
for (i = 0; vglo.arg[i] != '\0'; i++)
{
if (!isdigit(vglo.arg[i]) && vglo.arg[i] != '-')
{
dprintf(2, "L%u: ", cline);
dprintf(2, "usage: push integer\n");
free_vglo();
exit(EXIT_FAILURE);
}
}
n = atoi(vglo.arg);
if (vglo.lifo == 1)
add_dnodeint(doubly, n);
else
add_dnodeint_end(doubly, n);
}

/**
* _pall - all value in stack printer
* @doubly: linked list head
* @cline: number of line
*/
void _pall(stack_t **doubly, unsigned int cline)
{
stack_t *hlper;
(void)cline;
hlper = *doubly;
while (hlper)
{
printf("%d\n", hlper->n);
hlper = hlper->next;
}
}

/**
* _pint - vale of top stack printer
* @doubly: linked list head
* @cline: number of line
*/
void _pint(stack_t **doubly, unsigned int cline)
{
(void)cline;
if (*doubly == NULL)
{
dprintf(2, "L%u: ", cline);
dprintf(2, "can't pint, stack empty\n");
free_vglo();
exit(EXIT_FAILURE);
}
printf("%d\n", (*doubly)->n);
}

/**
* _pop - top element from stack remover
* @doubly: linked list head
* @cline: number of line
*/
void _pop(stack_t **doubly, unsigned int cline)
{
stack_t *hlper;
if (doubly == NULL || *doubly == NULL)
{
dprintf(2, "L%u: can't pop an empty stack\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = *doubly;
*doubly = (*doubly)->next;
free(hlper);
}

/**
* _swap - two elements in a stack swapper
* @doubly: linked list head
* @cline: number of line
*/
void _swap(stack_t **doubly, unsigned int cline)
{
int num = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, num++)
;
if (num < 2)
{
dprintf(2, "L%u: can't swap, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = *doubly;
*doubly = (*doubly)->next;
hlper->next = (*doubly)->next;
hlper->prev = *doubly;
(*doubly)->next = hlper;
(*doubly)->prev = NULL;
}
