#define  _CRT_SECURE_NO_WARNINGS
#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
//˵����
//*������ߵ�����
//#�ǵ����ߵ�����
void menu()
{
	printf("******************\n");
	printf("**��ӭ����������**\n");
	printf("**1,play 0,exit***\n");
	printf("******************\n");
	printf("��ѡ��");
}
void menu2()
{
	printf("*****************\n");
	printf("**��ѡ���ս��ʽ*\n");
	printf("**1,�˻� 0,����**\n");
	printf("*****************\n");
	printf("��ѡ��");
}
void game()
{
	char win = 'c';
	char board[ROW][COL] = { 0 };//��������
	Initialboard(board, ROW, COL);//��ʼ������
	Displayboard(board, ROW, COL);//��ӡ�����̵���Ϣ
	while (1)
	{
		//�����
		printf("�����\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
		//������
		printf("������\n");
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
	}
	if (win == 'e')
		printf("ƽ��\n");
	else if (win == '*')
		printf("���Ӯ\n");
	else if (win == '#')
		printf("����Ӯ\n");
}
void game2()
{
	char win = 'c';
	char board[ROW][COL] = { 0 };//��������
	Initialboard(board, ROW, COL);//��ʼ������
	Displayboard(board, ROW, COL);//��ӡ�����̵���Ϣ
	while (1)
	{
		//���1��
		printf("���1��\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
		//���2��
		printf("���2��\n");
		player2move(board, ROW, COL);
		Displayboard(board, ROW, COL);
		win = Isfull(board, ROW, COL);
		win = Iswin(board, ROW, COL);
		if (win != 'c')
			break;
	}
	if (win == 'e')
		printf("ƽ��\n");
	else if (win == '*')
		printf("���1Ӯ\n");
	else if (win == '#')
		printf("���2Ӯ\n");
}

void password(char* s) {

	bool flg = false;
	char ch;
	int i = 0;

	while (true)
	{
		while (ch = _getch())
		{
			if (ch == '\r')
			{
				flg = true;
				break;
			}

			if (ch != 8)//�س���\b,ASCII����8
			{//���ǻس���¼�� 
				s[i] = ch;
				putchar('*');//����Ǻ� 
				i++;
			}
			else
			{
				putchar('\b');//�س�һ���ַ�
				putchar(' ');//��ʾ�ո��ڸ�
				putchar('\b');//�ٻس�һ��ȴ�¼�� 
				i--;
			}
		}

		if (flg)
			break;

	}
}
int main()
{

	int input = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	char arr1[20] = { 0 };
	char arr2[20] = { 0 };
	char arr3[20] = { 0 };
	char arr4[20] = { 0 };
	do
	{
			//�˵������û�ѡ��
			menu();
			scanf("%d", &input);
			if (input != 0)
			{
				//��¼ϵͳ
				if (count == 0)
				{
					printf("����������˺ţ�");
					scanf("%s", &arr1);
					printf("������������룺");
					password(arr2);
					printf("\n");
					//scanf("%s", &arr2);
				}
					printf("����������˺ţ�");
					scanf("%s", &arr3);
					printf("������������룺");
					password(arr4);
					printf("\n");
					//scanf("%s", &arr4);
				if (strcmp(arr1, arr3) == 0 && strcmp(arr2, arr4) == 0)
				{
					printf("��¼�ɹ�\n");
					int i = 0;
		again:
					menu2();
					scanf("%d",&i);
					switch (i)
				{
					case 1:
						{
							printf("��Ϸ��ʼ\n");
							game();//��Ϸ����
							break;
						}
					case 0:
					{
							  printf("��Ϸ��ʼ\n");
							  game2();//��Ϸ����
							  break;
					}
					default:
					{
					   printf("ѡ�����������ѡ��\n");
						goto again;
					}
				}	
				count++;	
				}
				else
				{
					printf("\n�˺Ż��������\n");
					//printf("***************\n");
					//printf("**1.���µ�¼***\n");
					//printf("���������˳���Ϸ\n");
					//printf("***************\n");
					//printf("���������ѡ��");
					//int flag;
					//scanf("%d",&flag);
					//if (flag==1)  goto go;
					//else  printf("�˳���Ϸ\n");
				}

			}

			else
			{
				printf("�˳���Ϸ\n");
				break;
			}
		} while (input);
	    
	return 0;
}