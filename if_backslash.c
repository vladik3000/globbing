//
// Created by Fidelia Mallister on 11/7/20.
//
#include "globbing.h"

int			if_backslash(size_t *k, t_gtoken **compiled,
							const char *pattern, size_t *j)
{
	if (pattern[*k] == '\\')
	{
		if (pattern[*k + 1])
		{
			(*k)++;
			compiled[*j]->type = REGULAR;
			compiled[*j]->c = pattern[*k];
			if (pattern[*k + 1])
				(*k)++;
			(*j)++;
			return (1);
		}
	}
	return (0);
}
