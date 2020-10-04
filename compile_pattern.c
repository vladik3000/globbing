#include "globbing.h"

size_t		get_compiled_size(const char *pattern)
{
	size_t i;
	size_t size;
	size_t len;

	i = 0;
	size = 0;
	len = 0;
	while (pattern[i])
	{
		if (pattern[i] == '\\')
		{
			if (pattern[i + 1])
				i += 2;
			size += 1;
			continue ;
		}
		if (pattern[i] == '[')
		{
			i++;
			size++;
			if ((len = is_valid_bracket(pattern, i)) != 1)
			{
				i += len;
				continue ;
			}
		}
		size++;
		i++;
	}
	return (size);
}

t_gtoken **init_gtoken(size_t compiled_size)
{
	t_gtoken **compiled;
	size_t k;

	k = 0;
	compiled = NULL;
	if (!(compiled = malloc(sizeof(t_gtoken *) * (compiled_size + 1)))) // rewrite to xmalloc!
		exit(12);
	while (k < compiled_size)
	{
		if (!(compiled[k] = malloc(sizeof(t_gtoken))))
			exit(12);
		bzero(compiled[k], sizeof(t_gtoken));
		k++;
	}
	compiled[k] = NULL;
	return (compiled);
}


t_compiled *compile_pattern(const char *pattern)
{
	t_gtoken **compiled;
	t_compiled *result;
	size_t k;
	size_t j;
	size_t len;

	k = 0;
	j = 0;
	len = 0;
	result = malloc(sizeof(t_compiled));
	result->size = get_compiled_size(pattern);
	compiled = init_gtoken(result->size);
	while (pattern[k])
	{
		if (pattern[k] == '*')
			compiled[j]->type = STAR;
		else if (pattern[k] == '?')
			compiled[j]->type = QUESTION;
		else if (pattern[k] == '\\') // \[!a-z]
		{
			if (pattern[k + 1])
			{
				k++;
				compiled[j]->type = REGULAR;
				compiled[j]->c = pattern[k];
				if (pattern[k + 1])
					k++;
				j++;
				continue ;
			}
		}
		else if (pattern[k] == '[')
		{
			if ((len = is_valid_bracket(pattern, k + 1)) != 0)
			{
				if (pattern[k + 1] == '!')
				{
					compiled[j]->type = NOT_CHARSET;
					if (!(compiled[j]->charset = ft_strsub(pattern, k + 2, len - 2)))
						exit(12);
				}
				else
				{
					compiled[j]->type = CHARSET;
					if (!(compiled[j]->charset = ft_strsub(pattern, k + 1, len - 1)))
						exit(12);
				}
				k += len + 1;
				j++;
				continue ;
			}
			compiled[j]->type = REGULAR;
		}
		else
			compiled[j]->type = REGULAR;
		compiled[j]->c = pattern[k];
		k++;
		j++;
	}
	result->arr = compiled;
	return (result);
}


//int main(int ac, char **av)
//{
//	t_gtoken **c;
//	size_t len;
//	size_t i = 0;
//
//	len = 0;
//	c = compile_pattern(av[1]);
//	len = get_compiled_size(av[1]);
//	while (i < len)
//	{
//		printf("token[%zu]:[%d]\n", len, c[i]->type);
//		if (c[i]->type == CHARSET || c[i]->type == NOT_CHARSET)
//			printf("charset:%s\n", c[i]->charset);
//		i++;
//	}
//	printf("string:[%s]\nsize:[%zu]\n", av[1], get_compiled_size(av[1]));
//	return (0);
//}
