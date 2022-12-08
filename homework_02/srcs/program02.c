#include "ft_shm.h"
#include "ft_sem.h"

int  main(void)
{
	void		*shmaddr;
	t_shm_buff	*buff;
	int			semid;

	shmaddr = init_add_share_memory();
	buff = (t_shm_buff *) shmaddr;
	semid = create_sem();
    for (int i=0; i < 10000; i++) {
        s_wait(semid);
		buff->nbr += 1;
        s_signal(semid);
    }
	s_wait(semid);
	printf("Result : %d\n", buff->nbr);
	s_signal(semid);
	if (shmdt(shmaddr) == -1)
		perror("shmdt ");
	return (0);
}