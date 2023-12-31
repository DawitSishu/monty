#include "monty.h"

/**
* get_opcodes - selects opacode executor
* @opc: passed down opacode
* Return: pointer to opacode executor
*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
instruction_t instructs[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"queue", _queue},
{"stack", _stack},
{"add", _add},
{"nop", _nop},
{"sub", _sub},
{"mul", _mul},
{"div", _div},
{"mod", _mod},
{"pchar", _pchar},
{"pstr", _pstr},
{"rotl", _rotl},
{"rotr", _rotr},
{NULL, NULL}
};
int i;
for (i = 0; instructs[i].opcode; i++)
{
if (_strcmp(instructs[i].opcode, opc) == 0)
break;
}
return (instructs[i].f);
}
