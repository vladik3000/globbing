
#ifndef GLOBBING_H
# define GLOBBING_H

//#include "libft/libft.h"
#include <string.h> // remove this ??
#include <ctype.h> // remove this!!
#include <stdio.h> // remove this
#include <stdlib.h> // remove tHISSSSS!!
# define REGULAR 1
# define STAR	 2
# define QUESTION 3
# define CHARSET 4
# define NOT_CHARSET 5

typedef struct	s_gtoken
{
	char c;
	char *charset;
	int type;
}				t_gtoken;

typedef struct	s_compiled
{
	t_gtoken **arr;
	size_t size;
}				t_compiled;


int		is_forbidden(char c);
int		is_valid_bracket(const char *pattern, size_t px);
t_compiled *compile_pattern(const char *pattern);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
#endif
// a\*b[A-Z] a ... * ... b ... ABCDE...Z
// abcd[z-a] a b c d [ z - a ]
