# include "../inc/push_swap.h"

void index_elements(t_stack array)
{
	int i;
	int j;
	int index;

	i = 0;
	while(array.arr_b[i])
	{
		j = 0;
		index = 0;
		while (array.arr_b[j])
		{
			if (array.arr_b[i] > array.arr_b[j])
				index++;
			j++;
		}
		array.arr_a[i] = index;
		i++;
	}
	i--;
	j = 0;
	while((i >> j) != 0)
		j++;
	array.bit = j;
}

void radix_sort(t_stack array)
{
	int i;
	int j;

	i = 0;
	while (i < array.bit)
	{
		j = 0;
		while (j < array.a_sz)
		{
			if ((array.arr_a[array.a_st] >> i) & 1)
				ra(array);
			else
				pb(array);
			j++;
		}
		while (array.b_sz > 0)
		{
			if ((array.arr_b[array.b_st] >> (i + 1)) & 1 || i == array.bit - 1)
				pa(array);
			else
				rb(array);
		}
		i++;
	}
}
