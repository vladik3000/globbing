//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <stdlib.h>

void		init_result_compiled(t_compiled **result, t_gtoken ***compiled,
						const char *pattern)
{
	*result = malloc(sizeof(t_compiled));
	(*result)->size = get_compiled_size(pattern);
	*compiled = init_gtoken((*result)->size);
}
