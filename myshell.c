#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<string.h>

int main()
{
	int pid = 0;
	int status = 0;
	int len = 0;
	char buf[100] = { 0 };
	int i = 0;

	while (1) {
		printf("LGT@myshell:~$ ");
		scanf("%[^\n]%*c", buf);
		pid = fork();//�����ӽ���  
		if (pid < 0)
		{
			printf("��������ʧ��\n");
			return 1;
		}

		if (pid == 0)
		{
			execlp(buf, buf, NULL); // �ӽ��̵���execlp�����н���ָ����滻  

			printf("ָ�����\n"); // ��������ǲ����ڵ���������ڲ�����ʱ����������  
			return 1;
		}

		if (waitpid(pid, &status, 0) < 0) // �����̵ȴ��ӽ���ִ�н���  
		{
			printf("�ȴ��ӽ���\n");
			return 1;
		}

	}
		    return 0;
	
}
