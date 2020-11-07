//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"

int		check_not(t_gtoken *token, char c)
{
	size_t i;

	i = 0;
	while (token->charset[i])
	{
		if (token->charset[i + 1] && token->charset[i + 1] == '-')
		{
			if (check_not_range(token->charset[i],
					token->charset[i + 2], c) == 0)
				return (0);
			i += 3;
			continue ;
		}
		else if (token->charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}
