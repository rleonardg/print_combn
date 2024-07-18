/*
DESCRIPTION
	While n is greater or equal than 0 and less than 10 will
	display the combination of numbers (n) in increasing order.

EXAMPLE
	If n = 2 the output will be:
	01, 02, 03, ..., 09, 12, ..., 79, 89
	
	If n = 4 the output will be:
	0123, 0124, 0125, ..., 0129, 0134, ..., 5789, 6789
*/
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *arr_num, int n)
{
	int	i;
	int	mistake;

	i = 1;
	mistake = 1;
	while (i < n)
	{
		if (arr_num[i - 1] >= arr_num[i])
		{
			mistake = 0;
		}
		i++;
	}
	if (mistake)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(arr_num[i++] + '0');
		}
		if (arr_num[0] != 10 - n)
			ft_putchar(',');
			ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	arr_num[n];
	
	i = 0;
	while (i < n)
	{
		arr_num[i++] = 0;
	}
	while (arr_num[0] <= (10 - n) && n > 0 && n < 10)
	{
		ft_print(arr_num, n);	
		i = n - 1;
		arr_num[n - 1]++;
		while (i > 0)
		{
			if (arr_num[i] > 9)
			{
				arr_num[i - 1]++;
				arr_num[i] = 0;
			}
			i--;
		}
	}
}

int	main(void)
{
	ft_print_combn(3);
}
