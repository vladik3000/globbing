//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

int		is_question(t_compiled *compiled, t_len *len, size_t string_len)
{
	if (compiled->arr[len->px]->type == QUESTION)
	{
		if (len->nx < string_len)
		{
			len->px += 1;
			len->nx += 1;
			return (1);
		}
	}
	return (0);
}
