#include "ft_msgq.h"

int	main(void)
{
	int		 	retval;
	int			msgqid;
	t_msgq_buff	buff;
	int			i;

	i = 0;
	msgqid = msgget(MSGQ_KEY, IPC_CREAT | 0666);
	if (msgqid == -1)
	{
		perror("msgget");
		exit(1);
	}
	while (true)
	{
		retval = msgrcv(msgqid, &buff, sizeof(t_msgq_buff) - sizeof(long), 2, IPC_NOWAIT); 
		if (retval < 0)
			break ;
		printf("%s", buff.message);
		i++;
	}
	while (i == 0)
	{
		retval = msgrcv(msgqid, &buff, sizeof(t_msgq_buff) - sizeof(long), 0, IPC_NOWAIT); 
		if (retval < 0)
			break ;
		printf("%s", buff.message);
	}
	exit(0);
}