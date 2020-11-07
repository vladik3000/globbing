//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

int		is_px_less_size(t_compiled *compiled, t_len *len, const char *string,
					size_t string_len)
{
	if (len->px < compiled->size)
	{
		if (is_question(compiled, len, string_len) == 1)
			return (1);
		else if (is_star(compiled, len, string) == 1)
			return (1);
		else if (is_charset_or_not_charset(compiled, len,
										string_len, string) == 1)
			return (1);
		else if (is_regular(compiled, len, string, string_len) == 1)
			return (1);
	}
	return (0);
}
