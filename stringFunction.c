#include "monty.h"
/**
* _strcmp - compare 2 strings
* @s1: sting-1 to be compared
* @s2: sting-2 to be compared
*
* Return: 0 if s1 and s2 are equals.
*/
int _strcmp(char *s1, char *s2)
{
int i;
for (i = 0; s1[i] == s2[i] && s1[i]; i++)
;
if (s1[i] > s2[i])
{
return (1);
}
if (s1[i] < s2[i])
{
return (-1);
}
return (0);
}

/**
* _sch - find a char in string
* @s: string to be searched
* @c: character to be found
*
* Return: 0 if failure, 1 if success
*/
int _sch(char *s, char c)
{
int count = 0;
while (s[count] != '\0')
{
if (s[count] == c)
{
break;
}
count++;
}
if (s[count] == c)
{
return (1);
}
else
{
return (0);
}
}

/**
* _strtoky - cut string to token on delimit
* @s: string to be cutted
* @d: base delimiter
*
* Return: first token partitions
*/
char *_strtoky(char *s, char *d)
{
static char *strr;
int i = 0, j = 0;
if (!s)
s = strr;
while (s[i] != '\0')
{
if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
{
strr = s + i + 1;
*strr = '\0';
s = s + j;
return (s);
}
else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
i++;
else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
{
strr = s + i + 1;
*strr = '\0';
strr++;
s = s + j;
return (s);
}
else if (_sch(d, s[i]) == 1)
{
j++;
i++;
}
}
return (NULL);
}
