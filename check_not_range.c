//
// Created by Fidelia Mallister on 11/7/20.
//

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
