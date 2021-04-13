//ջ��˳��洢�ṹ
typedef struct
{
	ElemType* base;
	ElemType* top;
	int stackSize;
}sqStack;

//����һ��ջ
#define STACK_INIT_SIZE 100
initStack(sqStack* s)
{
	s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(0);
	s->top = s->base; //�ʼ��ջ������ջ��
	s->stackSize = STACK_INIT_SIZE;
}

//��ջ������push
# define STACKINCREMENT 10

Push(sqStack* s, ElemType e)
{
	//���ջ����׷�ӿռ�
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stackSize;//����ջ��
		s->stackSize = s->stackSize + STACKINCREMENT;//����ջ���������
	}

	*(s->top) = e;
	s->top++;
}

//��ջ���� Pop
Pop(sqStack* s, ElemType* e)
{
	if (s->top == s->base) //ջ�ѿտ���Ҳ
		return;
	*e = *--(s->top);
}

//��·����
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;//���ڱ�עջ����λ��
	int stackSize;
}

//���һ��ջ
ClearStack(sqStack* s)
{
	s->top = s->base;
}

//����һ��ջ������ղ�һ����
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

//������ַ���=Ԫ�ظ���
int StackLen(sqStack s)
{
	return (s.top - s.base);
}


//������-��ʮ����
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

	printf("�������������������#���ű�ʾ������\n");
	scanf("%c", );
	while (c != '#')
	{
		Push("%c", &c);
	}

	getchar(0);//��'\n'�ӻ�����ȥ��

	len = StackLen(s);
	printf("ջ�ĵ�ǰ�����ǣ�%d\n", len);

	for (i = 0;i < len;i++)
	{
		Pop(&s, &c);
		sum = sum + (c - 48) * pow(2, i);

	}
	return 0;
}

//ջ����ʽ�洢�ṹ
typedef struct StackNode
{
	ElemType data;//���ջ������
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top; //topָ��
	int count; //ջԪ�ؼ�����
}

//��ջ����
Status Push(LinkStack* s, ElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
} 

// ��ջ����
Status Pop(LinkStack* s, ElemType* e)
{
	LinkStackPtr p;
	if (StackEmpty(*s)) //�ж��Ƿ�Ϊ��ջ
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

//�沨�����ʽ
int main()
{
	sqStack s;
	char c;
	double d, e;
	char str[MAXBUFFER];
	int i = 0;

	InitStack(&s);

	printf("�밴�沨�����ʽ������������ݣ������������֮���ÿո��������#��Ϊ������־��");
	scanf("%c", &c);

	while (c != '#')
	{	
		while (isdigit(c) || c == '.')//���ڹ�������
		{
			str[i++] = c;
			str[i] = '\0';
			if (i >= 10) {
				printf("�������뵥�����ݹ���");
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
					printf("����Ϊ0");
					return -1;
				}
				break;
				

		}
		scanf("%c", &c);
	}
	Pop(&s, &d);
	printf("\n���յļ�����Ϊ:%f\n", d);

	return 0;
}

//��׺���ʽת��Ϊ��׺���ʽ
/*�ܽ���򣺴����ұ�����׺���ʽ��ÿ�����ֺͷ��ţ�����������ֱ����������Ƿ��ţ����ж�����ջ�����ŵ����ȼ���
�������Ż������ȼ�����ջ�����ţ���ջ��Ԫ��һ�γ�ջ�������ֱ�����������Ż�ջ�ղŽ���ʺ���ĸ�������ջ��
*/

int main()
{
	sqStack s;
	char c, e;

	InitStack(&s);

	printf("��������׺���ʽ����#��Ϊ������־");
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
			printf("���������ʽ����");
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

//���е���ʽ�洢�ṹ
typedef struct QNode
{
	ElemType data;
	struct QNode* next;
}QNode, * QueuePrt;

typedef struct {
	QueuePrt front, rear;//���С�βָ��
}LinkeQueue;

//����һ������
initQueue(LinkQueue* q)
{
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}

//����в���
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

//�����в���
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


//����һ������
DestroyQueue(LinkQueue* q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

//ѭ������ (rear+1)%QueueSize; (front+1)%QueueSize;
initQueue(cycleQueue* q)
{
	q->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	if (!q->base)
		exit(0);
	q->front = q->rear = 0;

}


//����в���
InsertQueue(cycleQueue* q, ElemType e)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return;//��������
	q->base[q->rear] = e;
	q - rear = (q->rear + 1) % MAXSIZE;
}


//�����в���
DeleteQueue(cycQueue* q, ElemType)
{
	if (q->front == q->rear)
		return;//����Ϊ��
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}



