#include "../inc/push_swap.h"

int main(int argc, void *argv[])
{
	t_stack	*array;

	if (argc_ctl(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	array = stack_init(argc, argv);
	check_sorted(array);
}
