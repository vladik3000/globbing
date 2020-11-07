
#ifndef GLOBBING_H
# define GLOBBING_H

# define REGULAR		1
# define STAR			2
# define QUESTION		3
# define CHARSET		4
# define NOT_CHARSET	5

# include <unistd.h>

typedef struct	s_gtoken
{
	char	c;
	char	*charset;
	int		type;
}				t_gtoken;

typedef struct	s_compiled
{
	t_gtoken	**arr;
	size_t		size;
}				t_compiled;

typedef struct	s_len
{
	size_t nx;
	size_t px;
	size_t nextnx;
	size_t nextpx;
}				t_len;

int				is_px_less_size(t_compiled *compiled, t_len *len,
					const char *string, size_t string_len);
void			init_len(t_len *len);
int				is_regular(t_compiled *compiled, t_len *len,
				const char *string, size_t string_len);
int				is_charset_or_not_charset(t_compiled *compiled, t_len *len,
								size_t string_len, const char *string);
int				is_star(t_compiled *compiled, t_len *len, const char *string);
int				is_question(t_compiled *compiled, t_len *len,
				size_t string_len);
int				check_bracket(t_gtoken *token, char c);
int				check_not(t_gtoken *token, char c);
int				check_range(char a, char b, char c);
int				check_not_range(char a, char b, char c);
void			init_result_compiled(t_compiled **result, t_gtoken ***compiled,
							const char *pattern);
void			init_to_zero(size_t *a, size_t *b);
int				if_is_valid_bracket(const char *pattern, size_t *k,
								t_gtoken **compiled, size_t *j);
int				if_backslash(size_t *k, t_gtoken **compiled,
							const char *pattern, size_t *j);
int				if_star_or_question(t_gtoken **compiled,
						char pattern_char, size_t j);
t_gtoken		**init_gtoken(size_t compiled_size);
size_t			get_compiled_size(const char *pattern);
int				is_forbidden(char c);
int				is_valid_bracket(const char *pattern, size_t px);
t_compiled		*compile_pattern(const char *pattern);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);

#endif
