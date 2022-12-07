#ifndef FT_SEM_H
# define FT_SEM_H

# include <sys/sem.h>

#define SEM_KEY 5678
/*
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
*/

int create_sem(void);
void s_signal(int semid);
void s_wait(int semid);
#endif