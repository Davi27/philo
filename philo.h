#ifndef PHILO_H
# define PHILO_H


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_seat t_seat;

typedef struct s_table
{
	int				total;
	int				time_to_die;
	int				eat_time;
	int				sleep_time;
	int				rounds;
	long int		start;
	t_seat			*seats;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_table;

typedef struct s_seat
{
	int				id;
	int				total_rounds;
	long int		time_to_live;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	*l_f;
	t_table			*table;
	pthread_t		philo;
}	t_seat;


int			error_message(char *str);
int			ft_atoi(char *str);
long int	current_time(void);
void		ft_usleep(long int time);

int			memory(t_table *table);
int			init_table(t_table *table, int argc, char **argv);
int			init_seats(t_table *table);

int			single_thread(t_table *table);
int			run_threads(t_table *table);

void		print_message(char *str, t_seat *seat);

#endif