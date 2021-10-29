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
			printf("时间到了\n");
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
			printf("时间到了\n");
			break;
		}
	}

}
int main()
{
	int m, s;
	again:
	printf("请输入要计时的时间(分钟与秒)：");
	scanf("%d %d",&m,&s);
	if (m >= 0 && s >= 0 && s <= 60)
	{
		printf("计时开始：\n");
		 process(m, s);
	}
	else
	{
		printf("输入错误，请重新选择\n");
		goto again;
	}
	//while (1)
	//{
	//	if (m ==0 && s == 0)
	//	{
	//		printf("时间到了\n");
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
	//		printf("时间到了\n");
	//		break;
	//	}
	//}
	return 0;
}