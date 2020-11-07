//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"

int		is_star(t_compiled *compiled, t_len *len, const char *string)
{
	if (compiled->arr[len->px]->type == STAR)
	{
		if (string[len->nx] == '/')
		{
			len->px++;
			len->nextnx = 0;
			return (1);
		}
		len->nextpx = len->px;
		len->nextnx = len->nx + 1;
		len->px++;
		return (1);
	}
	return (0);
}
