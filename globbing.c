#include <string.h>
#include <stdio.h>
#include <ctype.h>

int		is_forbidden(char c)
{
	return (!isalpha(c) && !isdigit(c) && c != '-' && c != ']');
}

int		alpha(const char *pattern, size_t *px, const char c)
{
	char start;
	int	range;
	int		i;

	i = 0;
	range = 0;
	start = pattern[*px];
	if (isalpha(pattern[*px]) && pattern[*px + 1] && pattern[*px + 1] == '-')
	{
		if (!pattern[*px + 2] || !isalpha(pattern[*px + 2]) || pattern[*px] >= pattern[*px + 2])
			return (-1);
		range = pattern[*px + 2] - pattern[*px];
		while (i <= range)
		{
			if (start + i == c)
			{
				*px += 3;
				return (1);
			}
			i++;
		}
		*px += 3;
		return (0);
	}
	if (start == c)
	{
		*px += 1;
		return (1);
	}
	return (0);
}


int		digit(const char *pattern, size_t *px, const char c)
{
	char start;
	int	range;
	int		i;

	i = 0;
	range = 0;
	start = pattern[*px];
	if (isdigit(pattern[*px]) && pattern[*px + 1] && pattern[*px + 1] == '-')
	{
		if (!pattern[*px + 2] || !isdigit(pattern[*px + 2]) || pattern[*px] >= pattern[*px + 2])
			return (-1);
		range = pattern[*px + 2] - pattern[*px];
		while (i <= range)
		{
			if (start + i == c)
			{
				*px += 3;
				return (1);
			}
			i++;
		}
		*px += 3;
		return (0);
	}
	if (start == c)
	{
		*px += 1;
		return (1);
	}
	return (0);
}

int		brackets(const char *pattern, size_t *px, const char c)
{
	int neg;
	size_t i;
	int		res;

	res = 0;
	if (!pattern || (strchr(pattern, ']') == NULL))
		return (-1);
	neg = 0;
	i = 0;
	if (pattern[0] == '!')
	{
		neg = 1;
		i = 1;
	}
	while (pattern[*px] && pattern[*px] != ']')
	{
		if (is_forbidden(pattern[*px]))
			return (-1);
		if (isalpha(pattern[*px]))
		{
			if ((res = alpha(pattern, px, c)) == -1)
				return (-1);
			else
				res = 1;
		}
		else if (isdigit(pattern[*px]))
		{
			if ((res = digit(pattern, px, c)) == -1)
				return (-1);
			else if (res == 1)
				res = 1;
		}
		*px += 1;
	}


}
// a-z a
// a => 12
// z => 34
//
//
//

int		match(const char *pattern, const char *string)
{
	size_t		px;
	size_t		nx;
	size_t		nextpx;
	size_t		nextnx;
	size_t		pattern_len;
	size_t		string_len;
	size_t		list_len;

	pattern_len = strlen(pattern);
	string_len = strlen(string);
	px = 0;
	nx = 0;
	nextpx = 0;
	nextnx = 0;
	list_len = 0;
	while (px < pattern_len || nx < string_len)
	{
		if (px < pattern_len)
		{
			if (pattern[px] == '?')
			{
				if (nx < string_len)
				{
					px++;
					nx++;
					continue ;
				}
			}
			else if (pattern[px] == '*')
			{
				nextpx = px;
				nextnx = nx + 1;
				px++;
				continue ;
			}
			else if (pattern[px] == '[')
			{
				if (brackets(pattern, &px, string[nx]) == 1)
					nx++;
				continue ;
			}
			else
			{
				if (nx < string_len && string[nx] == pattern[px])
				{
					px++;
					nx++;
					continue ;
				}
			}
		}
		if (0 < nextnx && nextnx <= string_len)
		{
			px = nextpx;
			nx = nextnx;
			continue ;
		}
		return (0);
	}
	return (1);
}


int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("usage: ./match [pattern] [string]\n");
		return (-1);
	}

	match(av[1], av[2]) ? printf("it's a match!\n") : printf("not match\n");
	return (0);
}

