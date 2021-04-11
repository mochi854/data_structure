void unionL(list* La, list Lb)
{
	int La_len, Lb_len, i;

	ElemType e;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);

	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e))
		{
			ListInsert(La, ++La_len, e);
		}
	}
}

//线性表的顺序存储结构
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length; //线性表当前长度
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

Status GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
	{
		return ERROR;
	}
	*e = L.data[i - 1];

	return OK;
}

// 插入
Status ListInsert(SqList* L, int i, ElemType e)
{
	int k;

	if (L->length == MAXSIZE) //顺序线性表已经满了
	{
		return ERROR;
	}
	if (i<1 || i>L->length + 1) //删除位置不正确
	{
		return ERROR;
	}
	if (i <= L->length) //若插入数据位置不在表尾
	{
		//将要插入位置后数据元素向后移动一位
		for (k = L->length - 1;k >= i - 1;k--)
		{
			L->data[k + 1] = L->data[k];
		}

		k->data[i - 1] = e;
		k->length++;

		return OK;
	}
}

//删除
Status ListDelete(SqList* L, int i, ElemType* e)
{
	int k;

	if (L->length == 0)
	{
		return ERROR;
	}
	if (i<1 || i>L->length)
	{
		return ERROR;
	}

	*e = L->data[i - 1];

	if (i < L->length)
	{
		for (k = i;k < L->length;k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	k->length--;

	return OK;
}

//单链表
typedef struct Node
{
	ElemType data; //数据域
	struct Node* next;//指针域
}Node;
typedef struct Node* LinkList;

Status GetElem(LinkList L, int i, ElemType* e)
{
	int j;
	LinkList p;

	p = L->next;
	j = 1;

	while (p && j < i)
	{
		p = p->next;
		++j;
	}

	if (!p || j > i)
	{
		return ERROR;
	}

	*e = p->data;

	return OK;
}


Status ListInsert(LinkList* L, int i, ElemType)
{
	int j;
	LinkList p, s;

	p = *L;
	j = 1;

	while (p && j < i) //用于寻找第i个结点
	{
		p = p->next;
		j++;
	}

	if (!p || j > i)
	{
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}

Status ListDelete(LinkList* L, int i, ElemType* e)
{
	int j;
	LinkList p, q;

	p = *L;
	j = 1;

	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}

	if (!(p->next) || j > i)
	{
		return ERROR;
	}

	q = p->next;
	p->next = q->next;

	*e = q->data;
	free(q);

	return OK;
}

// 头插法，顺序相反
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;

	srand(time(0)); // 初始化随机种子

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));//生成新节点
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//尾插法
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;  // r是List尾部结点

	for (i = 0;i < n;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;  // r永远是List尾部结点
	}
	r->next = NULL;
}	


//单链表整表删除
Status ClearList(LinkList* L)
{
	LinkList p, q;

	p = (*L)->next;

	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}

	(*L)->next = NULL;

	return OK;
}

//静态链表，游标，用数组表示链表
//线性表的静态链表存储结构
#define MAXIZE 1000
typedef struct
{
	ElemType data;//数据
	int cur;//游标(Cursor)

}Component, StaticLinkList[MAXSIZE];

//对静态链表进行初始化相当于初始化数组
//备用链表
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1;i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

//快速找到未知长度单链表的中间结点
//1.遍历一遍L，2.循环L/2
Status GetMidNode(LinkList L, ElemType* e)
{
	LinkList search, mid;
	mid = search = L;

	while (search->next != NULL)
	{
		search = search->next->next;
		mid = mid->next;
	}
	else
	{
	search = search->next;
	}

	*e = mid->data;

	return OK;
}

//终端结点，尾指针 rear
//约瑟夫问题： n个人围圈报数，报n出列，最后剩下的是几号？
# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node* create(int n)
{
	node* p = NULL, * head;
	head = (node*)malloc(sizeof(node));
	p = head;
	node* s;
	int i = 1;

	if (0 != n)
	{
		while (i <= n)
		{
			s = (node*)malloc(sizeof(node));
			s->data = i++; //为循环链表初始化，第一个结点为1,第二个节点为2
			p->next = s;
			p = s;
		}
		s->next = head->next;
	}
	free(head);

	return s->next;
}

int main()
{
	int n = 41;
	int m = 3;
	int i;
	node* p = create(n);
	node* temp;

	m %= n;
	
	while (p != p->next)
	{
		for (i = 1;i < m - 1;i++)
		{
			p = p->next;
		}

		printf("%d->", p->next->data);
		temp = p->next;
		p->next = temp->next;

		free(temp);

		p = p->next;

	}

	printf("%d\n", p->data);

	return 0;
}

//链表合并：假设A, B 为非空循环链表的尾指针
LinkList Connect(LinkList A, LinkList B)
{
	LinkList p = A->next; //保存A表的头结点位置

	A->next = B->next->next; //B表的开始结点链接到A表尾

	free(B->next); //释放B表的头结点，初学者容易忘记

	B->next = p;

	return B; //返回新循环链表的尾指针
}

//单链表是否有环
//1.比较步数的方法
int HasLoop1(LinkList L)
{
	LinkList cur1 = L; //定义结点cur1
	int pos1 = 0; //cur1的步数

	while (cur1)
	{
		while (cur2)
		{
			LinkList cur2 = L;//定义结点cur2
			int pos2 = 0;//cur2的步数
			if (cur2 == cur1)
			{
				if (pos1 == pos2)
					break;
				else
				{
					printf("环的位置在第%d个结点处,\n\n", pos2);
					return 1;//有环并返回1
				}
			}
			cur2 = cur2->next;//如果没发现环，继续下一个结点
			pos1++;//cur2步数自增
		}
		cur1 = cur1->next;//cur1继续向后一个结点
		pos1++;
	}
	return 0;
}
//2.快慢指针方式
int HasLoop2(LinkList L)
{
	int step1 = 1;
	int step2 = 2;
	LinkList p = L;//慢
	LinkList q = L;//快

	while (p != NULL && q != NULL && q->next != NULL)
	{
		p = p->next;
		if (q->next != NULL)
			q = q->next->next;
		
		printf("p:%d,q:%d\n", p->data, q->data);

		if (p == q)
			return 1;
	}
	return 0;
}

//魔术师发牌问题
void Magician(LinkList head)
{
	linklist p;
	int j;
	int Countnumber = 2;

	p = head;
	p->data = 1; //第一张牌放1

	while (1)
	{
		for (j = 0;j < Countnumber;j++)
		{
			p = p->next;
			if (p->data != 0) //该位置有牌的话，则下一个位置
			{
				p->next;
				j--;
			}
		}
		if (p->data == 0)
		{
			p->data = Countnumber;
			Countnumber++;

			if (Countnumber == 14)
				break;

		}
	}
}


//双向链表结点结构
typedef struct DualNode
{
	ElemType data;
	struct DualNode* prior;//前驱节点
	struct DualNode* next;//后继节点
}DualNode, * DuLinkList;

//双向链表插入操作
s->next = p;
s->prior = p->prior;
p->prior->next = s;
p->prior = s;

//双向链表的删除操作
p->prior = p->next;
p->next->prior = p->prior;
free(p);

//双向链表实践
#include<studio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode;
{
	ElemType data;
	struct DualNode* prior;
	struct DualNode* next;
}DualNode, * DuLinkList;

//step1: 初始化
Status InitLisk(DuLinkList* L)
{
	DualNode* p, * q;
	int i;

	*L = (DuLinkList)malloc(sizeof(DualNode));
	if (!(*L))
	{
		return ERROR;
	}

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for (i = 0;i < 26;i++)
	{
		q = (DualNode*)malloc(sizeof(DualNode));
		if (!q)
		{
			return ERROR;
		}

		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next; //p->next = NULL
		p->next = q;

		p = q;
	}
	p->next = (*L)->next;
	(*L)->next->prior = p;

	return OK;
}
//step2: 排序
void Caesar(DuLinkList* L, int i)
{
	if (i > 0)
	{
		do
		{
			(*L) = (*L)->next;

		} while (--i);
	}
	if (i < 0)
	{
		do
		{
			(*L) = (*L)->next;
		} while (++i);
	}
}

int main()
{
	DuLinkList L;
	int i, n;

	InitList(&L);
	
	Caesar(&L, n);

	for (i = 0;i < 25;i++)
	{
		L = L->next;
		printf(L->data);
	}

	return 0;

}