#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "globbing.h"

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
int		check_not_range(char a, char b, char c)
{
	int	range;
	int	i;

	i = 0;
	range = b - a;
	while (i <= range)
	{
		if (a + i == c)
			return (0);
		i++;
	}
	return (1);
}
int		check_range(char a, char b, char c)
{
	int	range;
	int	i;

	i = 0;
	range = b - a;
	while (i <= range)
	{
		if (a + i == c)
			return (1);
		i++;
	}
	return (0);//fix
}

int		check_not(t_gtoken *token, char c)
{
	size_t i;

	i = 0;
	while (token->charset[i])
	{
		if (token->charset[i + 1] && token->charset[i + 1] == '-')
		{
			if (check_not_range(token->charset[i], token->charset[i + 2], c) == 0)
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
				if (check_range(token->charset[i], token->charset[i + 2], c) == 1)
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

int		match(const char *pattern, const char *string)
{
	size_t		px;
	size_t		nx;
	size_t		nextpx;
	size_t		nextnx;
	size_t		pattern_len;
	size_t		string_len;
	size_t		list_len;
	t_compiled *compiled;

	compiled = compile_pattern(pattern);
	pattern_len = strlen(pattern);
	string_len = strlen(string);
	px = 0;
	nx = 0;
	nextpx = 0;
	nextnx = 0;
	list_len = 0;
	while (px < /*pattern_len*/compiled->size || nx < string_len)
	{
		if (px < /*pattern_len*/compiled->size)
		{
			if (/*pattern[px]*/compiled->arr[px]->type == QUESTION/*?*/)
			{
				if (nx < string_len)
				{
					px++;
					nx++;
					continue ;
				}
			}
			else if (/*pattern[px]*/compiled->arr[px]->type == STAR/* * */)
			{
				if (string[nx] == '/')
				{
					px++;
					nextnx = 0;
					continue ;
				}
				nextpx = px;
				nextnx = nx + 1;
				px++;
				continue ;
			}
			else if (/*pattern[px]*/compiled->arr[px]->type == CHARSET ||
					compiled->arr[px]->type == NOT_CHARSET)
			{
				if (check_bracket(compiled->arr[px], string[nx]) == 1)
				{ 
					if (nx < string_len)
					{
						px++;
						nx++;
						continue ;
					}
				}
			}
			else
			{
				if (nx < string_len && compiled->arr[px]->type == REGULAR && string[nx] == /*pattern[px]*/compiled->arr[px]->c)
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

