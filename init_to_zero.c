//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>

void		init_to_zero(size_t *a, size_t *b)
{
	if (a && *a)
		*a = 0;
	if (b && *b)
		b = 0;
}
