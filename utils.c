#include "philo.h"

int	error_message(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	ft_atoi(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (str[i] == '-')
		return (error_message("Error! Negative input is not allowed"));
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (error_message("Error! Input must be just numbers"));
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (ret <= 0)
		return (error_message("Error! Input must be bigger than 0"));
	return (ret);
}

long int	current_time(void)
{
	struct timeval	time;
	long int		ret;

	ret = 0;
	gettimeofday(&time, NULL);
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(long int time)
{
	long int	start;

	start = current_time();
	while ((current_time() - start) < time)
		usleep(time / 10);
}