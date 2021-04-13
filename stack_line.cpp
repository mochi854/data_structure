//栈的顺序存储结构
typedef struct
{
	ElemType* base;
	ElemType* top;
	int stackSize;
}sqStack;

//创建一个栈
#define STACK_INIT_SIZE 100
initStack(sqStack* s)
{
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(0);
	s->top = s->base; //最开始，栈顶就是栈底
	s->stackSize = STACK_INIT_SIZE;
}

//入栈操作，push
# define STACKINCREMENT 10

Push(sqStack* s, ElemType e)
{
	//如果栈满，追加空间
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stackSize;//设置栈顶
		s->stackSize = s->stackSize + STACKINCREMENT;//设置栈的最大容量
	}

	*(s->top) = e;
	s->top++;
}

//出栈操作 Pop
Pop(sqStack* s, ElemType* e)
{
	if (s->top == s->base) //栈已空空是也
		return;
	*e = *--(s->top);
}

//套路出牌
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;//用于标注栈顶的位置
	int stackSize;
}

//清空一个栈
ClearStack(sqStack* s)
{
	s->top = s->base;
}

//销毁一个栈【和清空不一样】
DestroyStack(sqStack* s)
{
	int i, len;
	len = s->stackSize;
	for (i = 0;i < len;i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
}

//两个地址相减=元素个数
int StackLen(sqStack s)
{
	return (s.top - s.base);
}


//二进制-》十进制
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct
{
	ElemType* base;
	ElemType* top;
	int stackSize;
}sqStack;

void InitStack(sqStack* s)
{
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s = base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack* s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base.(s->stackSize + STACKINCREMENT) * sizef(ElemType));
		if (!s->base)
		{
			exit();
		}
		*(s->top) = e;
		s->top++;
	}
}

void Pop(sqStack* s, ElemType* e)
{
	if (s->top == s->base)
	{
		return;
	}
	*e = *--(s->top);
}

int StackLen(sqStack s)
{
	return (s.top - s.base);
}

int main()
{
	ElemType c;
	sqStack s;
	int len, i, sum = 0;

	printf("请输入二进制数，输入#符号表示结束！\n");
	scanf("%c", );
	while (c != '#')
	{
		Push("%c", &c);
	}

	getchar(0);//把'\n'从缓冲区去掉

	len = StackLen(s);
	printf("栈的当前容量是：%d\n", len);

	for (i = 0;i < len;i++)
	{
		Pop(&s, &c);
		sum = sum + (c - 48) * pow(2, i);

	}
	return 0;
}

//栈的链式存储结构
typedef struct StackNode
{
	ElemType data;//存放栈的数据
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; //top指针
	int count; //栈元素计数器
}

//进栈操作
Status Push(LinkStack* s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
} 

// 进栈操作
Status Pop(LinkStack* s, ElemType* e)
{
	LinkStackPtr p;
	if (StackEmpty(*s)) //判断是否为空栈
	{
		return ERROR;
	}
	*e = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return OK;
}

//逆波兰表达式
int main()
{
	sqStack s;
	char c;
	double d, e;
	char str[MAXBUFFER];
	int i = 0;

	InitStack(&s);

	printf("请按逆波兰表达式输入待计算数据，数据与运算符之间用空格隔开，以#作为结束标志：");
	scanf("%c", &c);

	while (c != '#')
	{	
		while (isdigit(c) || c == '.')//用于过滤数字
		{
			str[i++] = c;
			str[i] = '\0';
			if (i >= 10) {
				printf("出错，输入单个数据过大");
				return -1;
			}
			scanf("%c", &c);
			if (c == ' ')
			{
				d = atof(str);
				Push(&s, d);
				i = 0;
				break;
			}
		}

		switch (c)
		{
			case '+':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d + e);
				break;
			case '-':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d - e);
			case '*':
				Pop(&s, &e);
				Pop(&s, &d);
				Push(&s, d * e);
			case '/':
				Pop(&s, &e);
				Pop(&s, &d);
				if (e != 0)
				{
					Push(&s, d / e);
				}
				else
				{
					printf("除数为0");
					return -1;
				}
				break;
				

		}
		scanf("%c", &c);
	}
	Pop(&s, &d);
	printf("\n最终的计算结果为:%f\n", d);

	return 0;
}

//中缀表达式转换为后缀表达式
/*总结规则：从左到右遍历中缀表达式的每个数字和符号，若是数字则直接输出，若是符号，则判断其与栈顶符号的优先级，
是右括号或者优先级低于栈顶符号，则栈顶元素一次出栈并输出，直到遇到左括号或栈空才将吃屎的哪个符号入栈。
*/

int main()
{
	sqStack s;
	char c, e;

	InitStack(&s);

	printf("请输入中缀表达式，以#作为结束标志");
	scanf("%c", &c);

	while (c != '#')
	{
		while(c>='0'&&c<='9')
		{
			printf("%c", c);
		}

		if (')' == c)
		{
			Pop(&s, e);
			while ('(' != e)
			{
				printf("%c", e);
				scanf("%c", &c);
				if (c < '0' || c>'9')
				{
					printf(" ");
				}
				//Pop(&s, &e);
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (!= StackLen(s))
			{
				Push(&s, c); 
			}
			else {
				do
				{
					Pop(&s, &e);
					if ('(' == e)
					{
						Push(&s, e);
					}
					else
					{
						printf("%c", e);
					}while (StackLen(s) && '(' != e);
					push(&s, c);

				}
			}
		else if ('*' == c || '/' == c || '(' == c)
		{
			Push(&s, c);
		}
		else if ('#' == c)
		{
			break;
		}
		else
		{
			printf("出错，输入格式错误");
			return -1;
		}
		scanf("%c", &c);
		}
		while (StackLen(s))
		{
			Pop(&s, &e);
			printf("%c", e);
		}
		return 0;
	}
}

//队列的链式存储结构
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePrt;

typedef struct {
	QueuePrt front, rear;//队列、尾指针
}LinkeQueue;

//创建一个队列
initQueue(LinkQueue* q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}

//入队列操作
InsertQueue(LinkeQueue* q, ElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (p == NULL)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

//出队列操作
DeleteQueue(LinkQueue* q, ElemType* e)
{
	QueuePtr p;
	if (q->front == q->rear) 
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
		q->rear = q->front;
	free(p);
}


//销毁一个队列
DestroyQueue(LinkQueue* q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

//循环队列 (rear+1)%QueueSize; (front+1)%QueueSize;
initQueue(cycleQueue* q)
{
	q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base)
		exit(0);
	q->front = q->rear = 0;

}


//入队列操作
InsertQueue(cycleQueue* q, ElemType e)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return;//队列已满
	q->base[q->rear] = e;
	q - rear = (q->rear + 1) % MAXSIZE;
}


//出队列操作
DeleteQueue(cycQueue* q, ElemType)
{
	if (q->front == q->rear)
		return;//队列为空
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}



