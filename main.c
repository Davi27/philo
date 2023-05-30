#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
	{
		error_message("Error! Wrong number of parameters");
		return (1);
	}
	if (init_table(&table, argc, argv) || init_seats(&table))
		return (1);
	if (run_threads(&table))
		return (1);
	return (0);
}