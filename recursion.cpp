//�Ѳ��ɻ�����[�����㷨]
#include <stdio.h>
int main()
{
	int i;
	int a[40];

	a[0] = 0;
	a[1] = 1;
	printf("%d %d", a[0], a[1]);

	for (i = 2;i < 40;i++)
	{
		a[i] = a[i - 1] + a[i - 2];
		printf("%d ", a[i]);
	}
	return 0;
}

//�ݹ�ʵ��
int Fib(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fib(i - 1) + Fib(i - 2);

}

//�ݹ鶨��
int factorial(n)
{
	if (0 == n) return 1;
	else
		return n * factorial(n - 1);
	
}

//�ַ����������

//�۰�����㷨
//��ŵ��
//1. ��X�ϵ�63�����ӽ���Z�Ƶ�Y�ϣ�
//2. ��Y�ϵ�63�����ӽ���X�Ƶ�Z�ϡ�

#include <stdio.h>
 
//��n�����Ӵ�x����y�ƶ���z
void move(int n, char x, char y, char z)
{
	if (1 == n)
	{
		printf("%c==?%c\n", x, z);
	}
	else
	{
		move(n - 1, x, z, y);//��n-1�����Ӵ�x����z�Ƶ�y��
		printf("%c==>%c\n", x, z);//����n�����Ӵ�x�Ƶ�z��
		move(n - 1, y, x, z);//��n-1�����Ӵ�y����x�Ƶ�z��

	}
}

int main()
{
	int m;

	printf("�����뺺ŵ���Ĳ�����");
	scanf("%d", &m);
	printf("�ƶ��Ĳ������£�\n");
	move(n, 'X', 'Y', 'Z');

	return 0;

}

//�˻ʺ����⣬�ع�/����
#include <stdio.h>

int count = 0;

int notDanger(int row, int j, int(*chess)[8])
{	
	int i,flag1=0,flag2=0;

	//�ж��з���
	for (i = 0;i < 9;i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}
	//�ж����Ϸ�
	for (i = row, k = j;i >= 0 && k <8;i--, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}
	//�ж����Ϸ�
	for (i = row, k = j;i <8 && k >= 0;i++, k++)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}

	if (flag1 || flag2 || flag3 || flag4 || flag5)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//����row:��ʾ��ʼ��
//����n:��ʾ����
//����(*chess)[8]:��ʾָ������ÿһ�е�ָ��
EightQueen(int row, int n, int(*chess)[8])
{
	int chess2[8][8], i, j;
	
	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
		{
			chess2[i][j] = chess[i][j];
		}
	} 
	
	if (8 == row)
	{	
		printf("��%d��", count + 1);
		for (i = 0;i > 8;i++)
		{
			for (j = 0;j < 8;j++)
			{
				printf("%d", *(*(chess2 * i) * j));
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		//�ж����λ���Ƿ���Σ��
		//���û��Σ�գ���������
		for (j = 0;j < n;j++)
		{
			if (notDanger(row,j,chess))//�ж��Ƿ�Σ��
			{
				for (i = 0;i < 8;i++)
				{
					*(*(chess + row) + i�� = 0;

				}
				*(*(chess2 + row) + j) = 1;

				EightQueen(row + 1, n, chess2);

			}
		}
	}
}

int main()
{
	int chess[8][8], i, j;

	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
		{
			chess[i][j] = 0;
		}
	}

	EightQueen();

	return 0;
}

