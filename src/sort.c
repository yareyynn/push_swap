#include "../inc/push_swap.h"

int	count_digits(int num)
{
	int	count = 1;

	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	**itoa_index_array(long *arr, int size)
{
	char	**res;
	int		max_digits = 0;
	int		temp, i, j;
	int		digits;

	// Maksimum basamak sayısını bul
	for (i = 0; i < size; i++)
	{
		digits = count_digits(arr[i]);
		if (digits > max_digits)
			max_digits = digits;
	}

	// String array için yer ayır
	res = malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);

	i = 0;
	while (i < size)
	{
		res[i] = malloc(sizeof(char) * (max_digits + 1));
		if (!res[i])
			return (NULL); // bu kısımda leak kontrolü yapılabilir

		temp = arr[i];
		res[i][max_digits] = '\0';
		j = max_digits - 1;
		while (j >= 0)
		{
			res[i][j] = (temp % 10) + '0';
			temp /= 10;
			j--;
		}
		i++;
	}
	return (res);
}

void	radix_decimal_sort(t_stack *s)
{
	int		digit;
	int		max_digits;
	int		j;
	char	target;
	int		k;
	int		b_len;

	max_digits = ft_strlen(s->index_str[0]);
	digit = max_digits - 1;

	while (digit >= 0)
	{
		j = 0;
		while (j <= 9)
		{
			k = 0;
			while (k < s->a_sz)
			{
				target = s->index_str[s->arr[s->a_st]][digit];
				if (target - '0' == j)
					pb(s);
				else
					ra(s);
				k++;
			}
			b_len = s->b_sz;
			while (b_len--)
			{
				target = s->index_str[s->arr[s->b_st]][digit];
				if (target - '0' == j)
					pa(s);
				else
					rb(s);
			}
			j++;
		}
		digit--;
	}
}
