//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

int			if_is_valid_bracket(const char *pattern, size_t *k,
								t_gtoken **compiled, size_t *j)
{
	size_t len;

	len = 0;
	if (pattern[*k] == '[')
	{
		if ((len = is_valid_bracket(pattern, *k + 1)) != 0)
		{
			if (pattern[*k + 1] == '!')
			{
				compiled[*j]->type = NOT_CHARSET;
				compiled[*j]->charset = ft_strsub(pattern, *k + 2, len - 2);
			}
			else
			{
				compiled[*j]->type = CHARSET;
				compiled[*j]->charset = ft_strsub(pattern, *k + 1, len - 1);
			}
			*k += len + 1;
			(*j)++;
			return (1);
		}
		compiled[*j]->type = REGULAR;
	}
	return (0);
}
