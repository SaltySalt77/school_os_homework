#include "ft_sem.h"
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdio.h>

void s_wait(int semid)
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1) {
        perror("semop : ");
        return ;
    }
}

void s_signal(int semid)
{
    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1) {
        perror("semop : ");
        return ;
    }
}

int create_sem(void)
{
    int semid;
    union semun sem_union;

    // semaphore
    if ((semid = semget(SEM_KEY, 1, IPC_CREAT|IPC_EXCL|0666)) == -1) {
        // try as a client
        if ((semid = semget(SEM_KEY, 0, 0)) == -1) return -1;
    } else {
        sem_union.val = 1;
        semctl(semid, 0, SETVAL, sem_union);
    }

    return semid;
}
