//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"
#include <unistd.h>
#include <stdlib.h>
#include <strings.h> // remove

t_gtoken	**init_gtoken(size_t compiled_size)
{
	t_gtoken	**compiled;
	size_t		k;

	k = 0;
	compiled = malloc(sizeof(t_gtoken *) * (compiled_size + 1));
	while (k < compiled_size)
	{
		compiled[k] = malloc(sizeof(t_gtoken));
		bzero(compiled[k], sizeof(t_gtoken));
		k++;
	}
	compiled[k] = NULL;
	return (compiled);
}
