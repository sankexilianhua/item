#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void process(int m, int  n)
{
	while (1)
	{
		if (m == 0 && n == 0)
		{
			printf("ʱ�䵽��\n");
			break;
		}
		if (n == 0)
		{
			if (m>0)
			 m -= 1;
			 n = 60;
		}
		printf("%02d:%02d",m,n);
		Sleep(1000);
		system("cls");
		n--;
		if (m == 0 && n == 0)
		{
			printf("ʱ�䵽��\n");
			break;
		}
	}

}
int main()
{
	int m, s;
	again:
	printf("������Ҫ��ʱ��ʱ��(��������)��");
	scanf("%d %d",&m,&s);
	if (m >= 0 && s >= 0 && s <= 60)
	{
		printf("��ʱ��ʼ��\n");
		 process(m, s);
	}
	else
	{
		printf("�������������ѡ��\n");
		goto again;
	}
	//while (1)
	//{
	//	if (m ==0 && s == 0)
	//	{
	//		printf("ʱ�䵽��\n");
	//		break;
	//	}
	//	if (s == 0)
	//	{
	//		if (m>0)
	//			m -= 1;
	//		s = 60;
	//	}
	//	printf("%02d:%02d", m, s);
	//	Sleep(1000);
	//	system("cls");
	//	s--;
	//	if (m == 0 && s == 0)
	//	{
	//		printf("ʱ�䵽��\n");
	//		break;
	//	}
	//}
	return 0;
}