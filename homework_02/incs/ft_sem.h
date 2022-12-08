#ifndef FT_SEM_H
# define FT_SEM_H

# include <sys/sem.h>

#define SEM_KEY 5678

/* Mac OS의 sys/sem 헤더파일에는 정의되어있으므로 주석으로 해두었습니다.
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
