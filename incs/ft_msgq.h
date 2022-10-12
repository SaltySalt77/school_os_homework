#ifndef FT_MSGQ_H
# define FT_MSGQ_H

# include <sys/msg.h>
# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define MSGQ_KEY 1010
# define SIZE 100

typedef struct s_msgq_buff {
	long 	data_nbr;
	char	message[SIZE];
} t_msgq_buff;

typedef struct s_lst
{
	char			msg[SIZE];
	bool			sent;
	struct s_lst	*next;
	
} t_lst;


#endif