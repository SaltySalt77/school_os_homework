#ifndef FT_SHM_H
# define FT_SHM_H

# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define SHM_KEY 3333
# define SIZE 100

typedef struct s_shm_buff {
	int		nbr;
} t_shm_buff;

typedef struct s_values
{
	int				semid;
	t_shm_buff		*buff;
	pthread_mutex_t	add;
} t_values;


	// 공유 메모리 생성 및 호출 프로세스에 추가
void	*init_add_share_memory(void);

#endif