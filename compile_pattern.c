#include "globbing.h"

size_t		get_compiled_size(char *pattern)
{
	size_t i;
	size_t size;

	i = 0;
	size = 0;
	while (pattern[i])
	{
		if (pattern[i] == '[')
			if (is_valid_bracket(pattern, &i) == 1)
			{
				size++;
				continue ;
			}
		size++;
		i++;
	}

t_gtoken **compile_pattern(char *pattern)
{
	t_gtoken **compiled;
	size_t compiled_size;

	compiled_size = get_compiled_size(pattern);
	compiled = NULL;
}
