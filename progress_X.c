#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/sem.h>


int main()
{
    int shmid = shmget((key_t)1000, 512, IPC_CREAT | 0666);//����һ��512���ֽڴ�С����Ϊ1000�Ĺ����ڴ�ռ�
    if (shmid == -1)
        return -1;
        char* s = (char*)shmat(shmid, NULL, 0);//���ع����ڴ汻ӳ��ĵ�ַ
   
    if (s== -1)return -1;

        int a[2] = { 1,0 }��
            sem_init(a, 2)��
   
    while (1)
    {
        printf("����������\n");
        char input[512] = { 0 };
        
        sem_p(0);
        fgets(input, 512, stdin);//��ȡ��������

        strcpy(s, input);
        sem_v(1);

        if (strncmp("end", input, 3) == 0)//���ж��Ƿ����˳�ָ������������ݷ��빲���ڴ�
        {
            break;
        }
    }
    

    shmdt(s);

    exit(0);
}