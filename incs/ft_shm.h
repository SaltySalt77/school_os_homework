#ifndef FT_SHM_H
# define FT_SHM_H

# include <sys/time.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define SHM_KEY 2022
# define SIZE 100

typedef struct s_shm_buff {
	int		nbr;
	char	message[SIZE];
} t_shm_buff;

	// 기준 시간으로부터 몇 초 지났는지 int 형으로 반환
int	get_timestamp(struct timeval *std_time, struct timeval *cur_time);
	// nbr초간 usleep
void	wait_nbr_sec(struct timeval std_time, int nbr);
	// 공유 메모리 생성 및 호출 프로세스에 추가
void	*init_add_share_memory(void);

#endif