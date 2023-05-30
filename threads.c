#include "philo.h"

int	single_thread(t_table *table)
{
	print_message("has taken a fork", table->seats);
	ft_usleep(table->time_to_die);
	print_message("died", table->seats);
	return (1);
}

void	*dinner(void* arg)
{
	printf("Inside dinner\n");
	return NULL;
}

int	run_threads(t_table *table)
{
	int	i;

	i = 0;
	if (table->total == 1)
		single_thread(table);
	while (i < table->total)
	{
		pthread_create(&table->seats[i].philo, NULL, &dinner, NULL);
		i++;
	}
	return (0);
}