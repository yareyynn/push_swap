#include "../inc/push_swap.h"

void pa(t_stack *array)
{
	if (array->b_sz > 0)
	{
		array->a_sz++;
		array->b_sz--;
		array->a_st--;
		array->arr[array->a_st] = array->arr[array->b_st];
		array->b_st++;
	}
}

void pb(t_stack *array)
{
	if (array->a_sz > 0)
	{
		array->b_sz++;
		array->a_sz--;
		array->b_st--;
		array->arr[array->b_st] = array->arr[array->a_st];
		array->a_st++;
	}
}

void ra(t_stack *array)
{
	if (array->a_sz > 1)
	{
		int tmp = array->arr[array->a_st];
		for (int i = array->a_st; i < array->a_st + array->a_sz - 1; i++)
			array->arr[i] = array->arr[i + 1];
		array->arr[array->a_st + array->a_sz - 1] = tmp;
	}
}

void rb(t_stack *array)
{
	if (array->b_sz > 1)
	{
		int tmp = array->arr[array->b_st];
		for (int i = array->b_st; i < array->b_st + array->b_sz - 1; i++)
			array->arr[i] = array->arr[i + 1];
		array->arr[array->b_st + array->b_sz - 1] = tmp;
	}
}
