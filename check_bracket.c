//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"

int		check_bracket(t_gtoken *token, char c)
{
	size_t i;

	if (token->type == NOT_CHARSET)
		return (check_not(token, c));
	i = 0;
	while (token->charset[i])
	{
		if (token->charset[i + 1])
		{
			if (token->charset[i + 1] == '-')
			{
				if (check_range(token->charset[i],
					token->charset[i + 2], c) == 1)
					return (1);
				i += 3;
				continue ;
			}
		}
		if (token->charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}
