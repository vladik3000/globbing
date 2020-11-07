#include "globbing.h"

static int		is_continue(t_gtoken **compiled, const char *pattern,
				size_t *k, size_t *j)
{
	if (if_star_or_question(compiled, pattern[*k], *j) == 1)
		return (1);
	else if (if_backslash(k, compiled, pattern, j) == 1)
		return (1);
	else if (if_is_valid_bracket(pattern, k, compiled, j) == 1)
		return (1);
	return (0);
}

t_compiled		*compile_pattern(const char *pattern)
{
	t_gtoken	**compiled;
	t_compiled	*result;
	size_t		k;
	size_t		j;

	init_to_zero(&k, &j);
	init_result_compiled(&result, &compiled, pattern);
	while (pattern[k])
	{
		if (pattern[k] == '*')
			compiled[j]->type = STAR;
		else if (pattern[k] == '?')
			compiled[j]->type = QUESTION;
		else if (is_continue(compiled, pattern, &k, &j) == 1)
			continue ;
		else
			compiled[j]->type = REGULAR;
		compiled[j]->c = pattern[k];
		k++;
		j++;
	}
	result->arr = compiled;
	return (result);
}
