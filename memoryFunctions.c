#include "monty.h"
/**
* _calloc - tw strings concatenator
* @nmemb: element numbers
* @size: element types
* Return: final pointer
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *pointer = NULL;
unsigned int i;
if (nmemb == 0 || size == 0)
{
return (NULL);
}
pointer = malloc(nmemb * size);
if (pointer == NULL)
{
return (NULL);
}
for (i = 0; i < (nmemb * size); i++)
{
*((char *)(pointer) +i) = 0;
}
return (pointer);
}
/**
* _realloc - changes the size and copies contents
* @ptr: malloc pointer
* @old_size: old number bytes
* @new_size: new number Bytes
* Return: final pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *pointer = NULL;
unsigned int i;

if (new_size == old_size)
return (ptr);
if (ptr == NULL)
{
pointer = malloc(new_size);
if (!pointer)
return (NULL);
return (pointer);
}
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (new_size > old_size)
{
pointer = malloc(new_size);
if (!pointer)
return (NULL);
for (i = 0; i < old_size; i++)
pointer[i] = *((char *)ptr + i);
free(ptr);
}
else
{
pointer = malloc(new_size);
if (!pointer)
return (NULL);
for (i = 0; i < new_size; i++)
pointer[i] = *((char *)ptr + i);
free(ptr);
}
return (pointer);
}
