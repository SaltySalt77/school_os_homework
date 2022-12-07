#include "ft_shm.h"

void	*init_add_share_memory(void)
{
	int 	shmid;
	void	*shmaddr;

    if ((shmid = shmget(SHM_KEY, sizeof(t_shm_buff), 0666)) == -1)
	{
		if ((shmid = shmget(SHM_KEY, sizeof(t_shm_buff), IPC_CREAT | 0666)) == -1)
			exit(1);
		shmaddr = shmat(shmid, (void *) 0, 0);
		if (shmaddr < (void *)0)
			exit(1);
		t_shm_buff *tmp = (t_shm_buff *)shmaddr;
		tmp->nbr = 0;
		return (shmaddr);

	}
	shmaddr = shmat(shmid, (void *) 0, 0);
	if (shmaddr < (void *)0)
		exit(1);
	return (shmaddr);
}
