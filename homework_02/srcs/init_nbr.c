#include "ft_shm.h"

int  main(void)
{
	void	*shmaddr;
	t_shm_buff	*buff;

	shmaddr = init_add_share_memory();
	buff = (t_shm_buff	*) shmaddr;
	buff->nbr = 0;
	if (shmdt(shmaddr) == -1)
		perror("shmdt ");
	return (0);
}