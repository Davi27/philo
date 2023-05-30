#include "philo.h"

int	memory(t_table *table)
{
	table->seats = malloc(sizeof(t_seat) * table->total);
	if (!table->seats)
		error_message("Error! Problem allocating seats");
	table->forks = malloc(sizeof(pthread_mutex_t) * table->total);
	if (!table->forks)
		error_message("Error! Problem allocating forks");
	return (1);
}

int	init_table(t_table *table, int argc, char **argv)
{
	table->start = current_time();
	table->total = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	if (table->total == 1)
		return (single_thread(table));
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	table->rounds = -1;
	if (argc == 6)
		table->rounds = ft_atoi(argv[5]);
	if (!memory(table) || table->total == 0 
		|| table->time_to_die == 0 || table->eat_time == 0
		|| table->sleep_time == 0 || table->rounds == 0)
		return (1);
	pthread_mutex_init(&table->print, NULL);
	return (0);
}

int	init_seats(t_table *table)
{
	int	i;

	i = 0;
	while (i++ < table->total)
		pthread_mutex_init(&table->forks[i], NULL);
	i = 0;
	while (i < table->total)
	{
		table->seats[i].table = table;
		table->seats[i].id = i + 1;
		table->seats[i].total_rounds = 0;
		table->seats[i].time_to_live = table->start + current_time();
		table->seats[i].l_f = &table->forks[i];
		if (i + 1 == table->total)
			table->seats[i].r_f = &table->forks[0];
		else
			table->seats[i].r_f = &table->forks[i + 1];
		i++;
	}
	return (0);
}
