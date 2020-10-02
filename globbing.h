
#ifndef GLOBBING_H
# define GLOBBING_H

#include "libft/libft.h"
#include <string.h> // remove this ??
#include <ctype.h> // remove this!!
#include <stdio.h> // remove this
# define REGULAR 1
# define STAR	 2
# define QUESTION 3
# define CHARSET 4
# define NOT_CHARSET 5

typedef struct	s_gtoken
{
	char charset[62];
	int type;
}				t_gtoken;

int		is_forbidden(char c);
int		is_valid_bracket(const char *pattern, size_t *px);
#endif
// a\*b[A-Z] a ... * ... b ... ABCDE...Z
// abcd[z-a] a b c d [ z - a ]
