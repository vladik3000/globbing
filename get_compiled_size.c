//
// Created by Fidelia Mallister on 11/7/20.
//
#include "globbing.h"
#include <unistd.h>

static int			gcs_if_backslash(const char *pattern, size_t *i,
							size_t *size)
{
	if (pattern[*i] == '\\')
	{
		if (pattern[*i + 1])
			*i += 2;
		*size += 1;
		return (1);
	}
	return (0);
}

size_t				get_compiled_size(const char *pattern)
{
	size_t i;
	size_t size;
	size_t len;

	i = 0;
	size = 0;
	len = 0;
	while (pattern[i])
	{
		if (gcs_if_backslash(pattern, &i, &size) == 1)
			continue ;
		if (pattern[i] == '[')
		{
			i++;
			size++;
			if ((len = is_valid_bracket(pattern, i)) != 1)
			{
				i += len;
				continue ;
			}
		}
		size++;
		i++;
	}
	return (size);
}
