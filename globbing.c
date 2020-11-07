#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "globbing.h"

int		match(const char *pattern, const char *string)
{
	t_len		len;
	size_t		string_len;
	t_compiled	*compiled;

	compiled = compile_pattern(pattern);
	string_len = strlen(string);
	init_len(&len);
	while (len.px < compiled->size || len.nx < string_len)
	{
		if (is_px_less_size(compiled, &len, string, string_len) == 1)
			continue ;
		if (0 < len.nextnx && len.nextnx <= string_len)
		{
			len.px = len.nextpx;
			len.nx = len.nextnx;
			continue ;
		}
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("usage: ./match [pattern] [string]\n");
		return (-1);
	}
	match(av[1], av[2]) ? printf("it's a match!\n") : printf("not match\n");
	return (0);
}
