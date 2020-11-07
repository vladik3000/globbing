//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

int		is_regular(t_compiled *compiled, t_len *len, const char *string,
				size_t string_len)
{
	if (len->nx < string_len && compiled->arr[len->px]->type == REGULAR
	&& string[len->nx] == compiled->arr[len->px]->c)
	{
		len->px++;
		len->nx++;
		return (1);
	}
	return (0);
}
