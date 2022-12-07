#include "ft_shm.h"
#include <pthread.h>
#include "ft_sem.h"

void	*add_1_to_shm(void *value) {
	t_values	*values;

	values = (t_values	*) value;
	for (int i = 0; i < 10000; i++)
	{
		s_wait(values->semid);
		pthread_mutex_lock(&(values->add));
		values->buff->nbr += 1;
		pthread_mutex_unlock(&(values->add));
		s_signal(values->semid);
	}
	return (0);
}


int  main(void)
{
	pthread_t		id[2];
	t_values	*values;

	values = malloc(sizeof(t_values));
	if (!values)
		exit(1);
	values->buff = (t_shm_buff *) init_add_share_memory();
	values->semid = create_sem();
	pthread_mutex_init(&(values->add), NULL);
	for (int i = 0; i < 2; i++)
		pthread_create(id + i, NULL, &add_1_to_shm, (void *) values);
	for (int i = 0; i < 2; i++)
		pthread_join(id[i], NULL);
	pthread_mutex_destroy(&(values->add));
	printf("Result : %d\n", values->buff->nbr);
	if (shmdt((void *) values->buff) == -1)
		perror("shmdt ");
	free(values);
	return (0);
}