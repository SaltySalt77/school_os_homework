#include "ft_shm.h"
#include "ft_msgq.h"

void	*upload_msg_to_que(void	*value)
{
	struct timeval	std_time;
	t_msgq_buff		msgq_buff;
	t_lst			*curr;
	int				msgqid;
	int				i;

	i = 1;
	curr = (t_lst *) value;
	msgqid = msgget(MSGQ_KEY, IPC_CREAT | 0666);
	if (msgqid == -1)
	{
		perror("msgget");
		exit(1);
	}
	while (i <= 9)
	{
		if (curr->sent == false)
		{
			curr->sent = true;
			gettimeofday(&std_time, NULL);
			if (i % 2)
				msgq_buff.data_nbr = 1;
			else
				msgq_buff.data_nbr = 2;
			strncpy(msgq_buff.message, curr->msg, strlen(curr->msg) + 1);
			if ((msgsnd(msgqid, &msgq_buff, sizeof(t_msgq_buff) - sizeof(long), 0)) == -1)
			{
				perror("msgsnd");
				exit(1);
			}
			if (curr->next != NULL)
				curr = curr->next;
			wait_nbr_sec(std_time, 2);
			i++;
		}
		else if (curr->sent == true && curr->next != NULL)
			curr = curr->next;
		usleep(100);
	}
	return (0);
}

t_lst	*add_buffer(char	*msg)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		exit(1);
	strncpy(new->msg, msg, strlen(msg) + 1);
	new->sent = false;
	new->next = NULL;
}

int	main(void)
{
	void			*shmaddr;
	t_shm_buff		*shm_buff;
	t_lst			*head;
	t_lst			*buffer;	// 메세지큐에 넣기 전에 메세지가 도착할 경우 보관함
	int				i;
	pthread_t		uploader;

	i = 0;
	shmaddr = init_add_share_memory();
	if (shmaddr < (void *)0)
	{
		perror("init_add_share_memory ");
		exit(1);
	}
	shm_buff = (t_shm_buff *) shmaddr;
	head = NULL;
	while (i < 9)
	{
		if (shm_buff->nbr == i)
		{
			usleep(100);
			continue ;
		}
		else if (shm_buff->nbr - i == 1)
		{
			if (i == 0)
			{
				head = add_buffer(shm_buff->message);
				pthread_create(&uploader, NULL, &upload_msg_to_que, (void *) head);
				buffer = head;
				printf("received message from shared memory %d\n", i);
			}
			else
			{
				buffer->next = add_buffer(shm_buff->message);
				buffer = buffer->next;
				printf("received message from shared memory %d\n", i);
			}
		}
		i++;
	}
	pthread_join(uploader, NULL);
	return (0);
}