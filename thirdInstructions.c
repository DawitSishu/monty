#include "monty.h"

/**
* _div - divides top by buttom
* @doubly: linked list head
* @cline: number of line
*/
void _div(stack_t **doubly, unsigned int cline)
{
int count = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, count++)
;
if (count < 2)
{
dprintf(2, "L%u: can't div, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
if ((*doubly)->n == 0)
{
dprintf(2, "L%u: division by zero\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = (*doubly)->next;
hlper->n /= (*doubly)->n;
_pop(doubly, cline);
}

/**
* _mul - multiplies top by buttom
* @doubly: linked list head
* @cline: number of line
*/
void _mul(stack_t **doubly, unsigned int cline)
{
int count = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, count++)
;
if (count < 2)
{
dprintf(2, "L%u: can't mul, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = (*doubly)->next;
hlper->n *= (*doubly)->n;
_pop(doubly, cline);
}

/**
* _mod - rest of the division computer
* @doubly: linked list head
* @cline: number of line
*/
void _mod(stack_t **doubly, unsigned int cline)
{
int count = 0;
stack_t *hlper = NULL;
hlper = *doubly;
for (; hlper != NULL; hlper = hlper->next, count++)
;
if (count < 2)
{
dprintf(2, "L%u: can't mod, stack too short\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
if ((*doubly)->n == 0)
{
dprintf(2, "L%u: division by zero\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
hlper = (*doubly)->next;
hlper->n %= (*doubly)->n;
_pop(doubly, cline);
}
/**
* _pchar - print first element char
* @doubly: linked list head
* @cline: number of line
*/
void _pchar(stack_t **doubly, unsigned int cline)
{
if (doubly == NULL || *doubly == NULL)
{
dprintf(2, "L%u: can't pchar, stack empty\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
if ((*doubly)->n < 0 || (*doubly)->n >= 128)
{
dprintf(2, "L%u: can't pchar, value out of range\n", cline);
free_vglo();
exit(EXIT_FAILURE);
}
printf("%c\n", (*doubly)->n);
}

/**
* _pstr - stack string printer
* @doubly: linked list head
* @cline: number of line
*/
void _pstr(stack_t **doubly, unsigned int cline)
{
stack_t *hlper;
(void)cline;
hlper = *doubly;
while (hlper && hlper->n > 0 && hlper->n < 128)
{
printf("%c", hlper->n);
hlper = hlper->next;
}
printf("\n");
}
