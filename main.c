#include "main.h"

/**
 * main - run code
 * @argc: arguments number
 * @argv: argument vector
 * 
 * Return: 0
 */

int main(void)
{
char *lineptr = NULL;
char **argv;
size_t n = 0;
ssize_t chars_n;
while (1)
{
if (isatty(0))
write(STDOUT_FILENO, "$ ", 2);
chars_n = getline(&lineptr, &n, stdin);
if (chars_n == -1)
{
free(lineptr);
exit(0);
}
argv = toknize(lineptr);
if (!argv[0])
{
free_argv(argv);
continue;
}
if (check_builtin(argv))
{
_builtin(argv);
}
else
{
exec_cmd(argv);
}
free_argv(argv);
}
free(lineptr);
return (0);
}