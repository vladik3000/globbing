//
// Created by Fidelia Mallister on 11/7/20.
//

#include "globbing.h"

int		if_star_or_question(t_gtoken **compiled, char pattern_char, size_t j)
{
	if (pattern_char == '*')
		compiled[j]->type = STAR;
	else if (pattern_char == '?')
		compiled[j]->type = QUESTION;
	return (0);
}
