#include <string.h>
#include <stdio.h>


int		process_open_bracket(char *pattern, char c)
{
	int neg;

	neg = 0;
	if (strchr(pattern, ']') == NULL)
		return (-1);
	if (pattern[1] == '!')
		neg = 1;
}




int		match(char *pattern, char *string)
{
	int px;
	int nx;
	int nextpx;
	int nextnx;
	char	c;

	px = 0;
	nx = 0;
	nextpx = 0;
	nextnx = 0;
	c = 0;
	while (px < strlen(pattern) || nx < strlen(string))
	{
		if (px < strlen(pattern))
		{
			c = pattern[px];
			if (c == '?')
			{
				if (nx < strlen(string))
				{
					px++;
					nx++;
					continue ;
				}
			}
			else if (c == '*')
			{
				nextpx = px;
				nextnx = nx + 1;
				px++;
				continue ;
			}
			else if (c == '[')
			{
				process_open_bracket(
			else
			{
				if (nx < strlen(string) && string[nx] == c)
				{
					px++;
					nx++;
					continue ;
				}
			}
		}
		if (0 < nextnx && nextnx <= strlen(string))
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

