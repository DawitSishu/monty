#include "monty.h"

/**
* _rotl - rotate elemnts to top and bottom
* @doubly: linkedd list head
* @cline: number of line
*/
void _rotl(stack_t **doubly, unsigned int cline)
{
stack_t *hlper1 = NULL;
stack_t *hlper2 = NULL;
(void)cline;

if (*doubly == NULL)
{
return;
}
if ((*doubly)->next == NULL)
{
return;
}
hlper1 = (*doubly)->next;
hlper2 = *doubly;
for (; hlper2->next != NULL; hlper2 = hlper2->next)
;
hlper1->prev = NULL;
hlper2->next = *doubly;
(*doubly)->next = NULL;
(*doubly)->prev = hlper2;
*doubly = hlper1;
}

/**
* _rotr - reverse he order of the star
* @doubly: linked list head
* @cline: number of line
*/
void _rotr(stack_t **doubly, unsigned int cline)
{
stack_t *hlper = NULL;
(void)cline;

if (*doubly == NULL)
{
return;
}
if ((*doubly)->next == NULL)
{
return;
}
hlper = *doubly;
for (; hlper->next != NULL; hlper = hlper->next)
;
hlper->prev->next = NULL;
hlper->next = *doubly;
hlper->prev = NULL;
(*doubly)->prev = hlper;
*doubly = hlper;
}
