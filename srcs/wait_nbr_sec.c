#include "ft_shm.h"

void	wait_nbr_sec(struct timeval std_time, int nbr)
{
	struct timeval	cur_time;

	while (1)
	{
		gettimeofday(&cur_time, NULL);
		if (get_timestamp(&std_time, &cur_time) >= nbr)
			break ;
		usleep(1000);
	}
}
