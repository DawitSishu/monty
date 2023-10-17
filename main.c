#include "monty.h"
global_t vglo;
/**
* free_vglo - global variable freeier
*/
void free_vglo(void)
{
free_dlistint(vglo.head);
free(vglo.buffer);
fclose(vglo.fd);
}
/**
* start_vglo - global variables initiator
* @fd: file descriptor
*/
void start_vglo(FILE *fd)
{
vglo.lifo = 1;
vglo.cont = 1;
vglo.arg = NULL;
vglo.head = NULL;
vglo.fd = fd;
vglo.buffer = NULL;
}

/**
* check_input - checker for file opening and stuff
* @argc: count of arguments
* @argv: vector of arguments
* Return: file structs
*/
FILE *check_input(int argc, char *argv[])
{
FILE *file_doc;
if (argc == 1 || argc > 2)
{
dprintf(2, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file_doc = fopen(argv[1], "r");
if (file_doc == NULL)
{
dprintf(2, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
return (file_doc);
}
/**
* main - Entry point
* @argc: count of arguments
* @argv: vector of arguments
* Return: 0 and success
*/
int main(int argc, char *argv[])
{
void (*f)(stack_t **stack, unsigned int line_number);
FILE *file_doc;
size_t size = 256;
ssize_t numberof_line = 0;
char *f_liner[2] = {NULL, NULL};
file_doc = check_input(argc, argv);
start_vglo(file_doc);
numberof_line = getline(&vglo.buffer, &size, file_doc);
while (numberof_line != -1)
{
f_liner[0] = _strtoky(vglo.buffer, " \t\n");
if (f_liner[0] && f_liner[0][0] != '#')
{
f = get_opcodes(f_liner[0]);
if (!f)
{
dprintf(2, "L%u: ", vglo.cont);
dprintf(2, "unknown instruction %s\n", f_liner[0]);
free_vglo();
exit(EXIT_FAILURE);
}
vglo.arg = _strtoky(NULL, " \t\n");
f(&vglo.head, vglo.cont);
}
numberof_line = getline(&vglo.buffer, &size, file_doc);
vglo.cont++;
}
free_vglo();
return (0);
}
