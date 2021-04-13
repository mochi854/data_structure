//费波纳基数列[迭代算法]
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

//递归实现
int Fib(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fib(i - 1) + Fib(i - 2);

}

//递归定义
int factorial(n)
{
	if (0 == n) return 1;
	else
		return n * factorial(n - 1);
	
}

//字符串反向输出

//折半查找算法
//汉诺塔
//1. 将X上的63个盘子借助Z移到Y上；
//2. 将Y上的63个盘子借助X移到Z上。

#include <stdio.h>
 
//将n个盘子从x借助y移动到z
void move(int n, char x, char y, char z)
{
	if (1 == n)
	{
		printf("%c==?%c\n", x, z);
	}
	else
	{
		move(n - 1, x, z, y);//将n-1个盘子从x借助z移到y上
		printf("%c==>%c\n", x, z);//将第n个盘子从x移到z上
		move(n - 1, y, x, z);//将n-1个盘子从y借助x移到z上

	}
}

int main()
{
	int m;

	printf("请输入汉诺塔的层数：");
	scanf("%d", &m);
	printf("移动的步数如下：\n");
	move(n, 'X', 'Y', 'Z');

	return 0;

}

//八皇后问题，回归/回溯
#include <stdio.h>

int count = 0;

int notDanger(int row, int j, int(*chess)[8])
{	
	int i,flag1=0,flag2=0;

	//判断列方向
	for (i = 0;i < 9;i++)
	{
		if (*(*(chess + i) + j) != 0)
		{
			flag1 = 1;
			break;
		}
	}
	//判断右上方
	for (i = row, k = j;i >= 0 && k <8;i--, k--)
	{
		if (*(*(chess + i) + k) != 0)
		{
			flag2 = 1;
			break;
		}
	}
	//判断左上方
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

//参数row:表示起始行
//参数n:表示列数
//参数(*chess)[8]:表示指向棋盘每一行的指针
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
		printf("第%d种", count + 1);
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
		//判断这个位置是否有危险
		//如果没有危险？继续往下
		for (j = 0;j < n;j++)
		{
			if (notDanger(row,j,chess))//判断是否危险
			{
				for (i = 0;i < 8;i++)
				{
					*(*(chess + row) + i） = 0;

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

