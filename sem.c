#include"sem.h"

//�ź���
static int semid = -1;

void sem_init(int a[], int n)
{
    semid = semget((key_t)1000, n, IPC_CREAT | IPC_EXCL | 0666);

    if (semid == -1)//�ж��ǲ��ǵ�һ������һ��Ҫ����������ʼֵ
    {
        semid = semget((key_t)1000, n, 0666);
        if (semid == -1)//�ڶ���ֻ��ȡ
        {
            perror("semget error\n");
        }
        else
        {
            union semun b;
            int i = 0;
            for (; i < n; i++)
            {
                b.val = a[i];
                if (semctl(semid, i, SETVAL, b) == -1)
                {
                    perror("semctl error\n");
                }
            }
        }
    }
}
void sem_p(int index)
{
    struct sembuf buf;
    buf.sem_num = index;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1)
    {
        perror("semop error\n");
    }
}
void sem_v(int index)
{
    struct sembuf buf;
    buf.sem_num = index;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;

    if (semop(semid, &buf, 1) == -1)
    {
        perror("semop error\n");
    }
}
void sem_del()
{
    if (semctl(semid, 0, IPC_RMID) == -1)
    {
        perror("semctl error\n");
    }
}
