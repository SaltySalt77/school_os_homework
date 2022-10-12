#include "ft_shm.h"

int	main(void)
{
	char			newline[SIZE];
	void			*shmaddr;
	t_shm_buff		*buf;
	struct timeval	std_time;

	
	shmaddr = init_add_share_memory();
	if (shmaddr == (void *)-1)
	{
		perror("init_add_share_memory ");
		return (1);
	}
	buf = (t_shm_buff	*) shmaddr;
	buf->nbr = 0;
	for (int i = 1; i <= 9; i++)
	{
		gettimeofday(&std_time, NULL);
		printf("input message : \n");
		fgets(newline, SIZE, stdin);
		buf->nbr = i;                          				// 공유 메모리에 몇 번째 입력값인지 입력
		strncpy(buf->message, newline, strlen(newline) + 1);
		printf("sending message...\n");
		wait_nbr_sec(std_time, 1); 			               // 입력값 받기 직전으로부터 1초 계산하여 기다림
	}
	if (shmdt(shmaddr) == -1);
		perror("shmdt ");
	return (0);
}