#include "ft_shm.h"

int	get_timestamp(struct timeval *std_time, struct timeval *cur_time)
{
	double	timestamp;

	timestamp = (cur_time->tv_sec) + (cur_time->tv_usec) / 1000000;
	timestamp -= (std_time->tv_sec) + (std_time->tv_usec) / 1000000;
	return ((int) timestamp);
}
