void	ft_test(int *nb)
{
	*nb = 3;
}

#include <stdio.h>

int		main(void)
{
	int		*nb = NULL;

	ft_test(nb);
	printf("%i\n", *nb);
}
