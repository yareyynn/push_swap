#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack array;

	array = stack_init(argc, argv);
	radix_sort(array);
}
