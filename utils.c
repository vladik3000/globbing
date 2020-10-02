#include "globbing.h"

int		is_forbidden(char c)
{
	return (!ft_isalpha(c) && !ft_isdigit(c) && c != '-' && c != ']');
}

int		is_valid_bracket(const char *pattern, size_t *px)
{
	size_t i;

	if (ft_strchr(pattern, ']') == NULL || !pattern)
		return (0);
	i = pattern[*px] == '!' ? *px + 1 : *px;
	while (pattern[i] && pattern[i] != ']')
	{
		if (is_forbidden(pattern[i]))
		{
			return (0);
		}
		if (ft_isalpha(pattern[i]) && pattern[i + 1] && pattern[i + 1] == '-')
		{
			if (!pattern[i + 2])
				return (0);
			if (!ft_isalpha(pattern[i + 2]))
				return (0);
			if ((isupper(pattern[i]) && !isupper(pattern[i + 2])) || (islower(pattern[i]) && !islower(pattern[i + 2])))
				return (0);
			if (pattern[i] >= pattern[i + 2])
				return (0);
		}
		if (ft_isdigit(pattern[i]) && pattern[i + 1] && pattern[i + 1] == '-')
		{
			if (!pattern[i + 2])
				return (0);
			if (!ft_isdigit(pattern[i + 2]))
				return (0);
			if (pattern[i] >= pattern[i + 2])
				return (0);
		}
		i++;
	}
	*px += i - *px + 1;
	return (1);
}
