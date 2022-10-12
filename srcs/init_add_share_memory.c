#include "ft_shm.h"

void	*init_add_share_memory(void)
{
	int 	shmid;
	void	*shmaddr;

    if ((shmid = shmget(SHM_KEY, sizeof(t_shm_buff), IPC_CREAT | 0666)) == -1) 
        return ((void *) -1);
	shmaddr = shmat(shmid, (void *) 0, 0);
	if (shmaddr < (void *)0)
		return ((void *) -1);
	return (shmaddr);
}
