#include "../inc/push_swap.h"

void ra(t_stack array)
{
	array.arr_a[(array.a_st + array.a_sz) % array.size] = array.arr_a[array.a_st];
	array.a_st = (array.a_st + 1) % array.size;
	write(1, "ra\n", 3);
}

void rb(t_stack array)
{
	array.arr_b[(array.b_st + array.b_sz) % array.size] = array.arr_b[array.b_st];
	array.b_st = (array.b_st + 1) % array.size;
	write(1, "rb\n", 3);
}

void pa(t_stack array)
{
	array.a_st = (array.a_st - 1 + array.size) % array.size;
	array.arr_a[array.a_st] = array.arr_b[array.b_st];
	array.b_st = (array.b_st + 1) % array.size;
	array.b_sz--;
	array.a_sz++;
	write(1, "pa\n", 3);
}

void pb(t_stack array)
{
	array.b_st = (array.b_st - 1 + array.size) % array.size;
	array.arr_b[array.b_st] = array.arr_a[array.a_st];
	array.a_st = (array.a_st + 1) % array.size;
	array.a_sz--;
	array.b_sz++;
	write(1, "pb\n", 3);
}
