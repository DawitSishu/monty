#include "monty.h"

/**
*add_dnodeint_end - note at the end of list adder
*@head: linked list head
*@n: store data
*
*Return: a linked list
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *temp_ptr, *hlper;
if (head == NULL)
return (NULL);
temp_ptr = malloc(sizeof(stack_t));
if (!temp_ptr)
{
dprintf(2, "Error: malloc failed\n");
free_vglo();
exit(EXIT_FAILURE);
}
temp_ptr->n = n;
if (*head == NULL)
{
temp_ptr->next = *head;
temp_ptr->prev = NULL;
*head = temp_ptr;
return (*head);
}
hlper = *head;
while (hlper->next)
hlper = hlper->next;
temp_ptr->next = hlper->next;
temp_ptr->prev = hlper;
hlper->next = temp_ptr;
return (hlper->next);
}

/**
*add_dnodeint - node at the begining
*@head: linked list head
*@n: store data
*
*Return: a linked list
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *temp_ptr;
if (head == NULL)
return (NULL);
temp_ptr = malloc(sizeof(stack_t));
if (!temp_ptr)
{
dprintf(2, "Error: malloc failed\n");
free_vglo();
exit(EXIT_FAILURE);
}
temp_ptr->n = n;
if (*head == NULL)
{
temp_ptr->next = *head;
temp_ptr->prev = NULL;
*head = temp_ptr;
return (*head);
}
(*head)->prev = temp_ptr;
temp_ptr->next = (*head);
temp_ptr->prev = NULL;
*head = temp_ptr;
return (*head);
}

/**
* free_dlistint - linked list freer
* @head: linked list head
*/
void free_dlistint(stack_t *head)
{
stack_t *temp_ptr;
while ((temp_ptr = head) != NULL)
{
head = head->next;
free(temp_ptr);
}
}
