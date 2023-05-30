#include "philo.h"

void	print_message(char *str, t_seat *seat)
{
	long int	time;

	time = current_time() - seat->table->start;
	printf("%ld %d %s\n", time, seat->id, str);
}