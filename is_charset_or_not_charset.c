//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

int		is_charset_or_not_charset(t_compiled *compiled, t_len *len,
								size_t string_len, const char *string)
{
	if (compiled->arr[len->px]->type == CHARSET ||
		compiled->arr[len->px]->type == NOT_CHARSET)
	{
		if (check_bracket(compiled->arr[len->px], string[len->nx]) == 1)
		{
			if (len->nx < string_len)
			{
				len->px++;
				len->nx++;
				return (1);
			}
		}
	}
	return (0);
}
