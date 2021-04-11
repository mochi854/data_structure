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

//���Ա��˳��洢�ṹ
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int length; //���Ա�ǰ����
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

// ����
Status ListInsert(SqList* L, int i, ElemType e)
{
	int k;

	if (L->length == MAXSIZE) //˳�����Ա��Ѿ�����
	{
		return ERROR;
	}
	if (i<1 || i>L->length + 1) //ɾ��λ�ò���ȷ
	{
		return ERROR;
	}
	if (i <= L->length) //����������λ�ò��ڱ�β
	{
		//��Ҫ����λ�ú�����Ԫ������ƶ�һλ
		for (k = L->length - 1;k >= i - 1;k--)
		{
			L->data[k + 1] = L->data[k];
		}

		k->data[i - 1] = e;
		k->length++;

		return OK;
	}
}

//ɾ��
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

//������
typedef struct Node
{
	ElemType data; //������
	struct Node* next;//ָ����
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

	while (p && j < i) //����Ѱ�ҵ�i�����
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

// ͷ�巨��˳���෴
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;

	srand(time(0)); // ��ʼ���������

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));//�����½ڵ�
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

//β�巨
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;

	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;  // r��Listβ�����

	for (i = 0;i < n;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;  // r��Զ��Listβ�����
	}
	r->next = NULL;
}	


//����������ɾ��
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

//��̬�����α꣬�������ʾ����
//���Ա�ľ�̬����洢�ṹ
#define MAXIZE 1000
typedef struct
{
	ElemType data;//����
	int cur;//�α�(Cursor)

}Component, StaticLinkList[MAXSIZE];

//�Ծ�̬������г�ʼ���൱�ڳ�ʼ������
//��������
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1;i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

//�����ҵ�δ֪���ȵ�������м���
//1.����һ��L��2.ѭ��L/2
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

//�ն˽�㣬βָ�� rear
//Լɪ�����⣺ n����ΧȦ��������n���У����ʣ�µ��Ǽ��ţ�
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
			s->data = i++; //Ϊѭ�������ʼ������һ�����Ϊ1,�ڶ����ڵ�Ϊ2
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

//����ϲ�������A, B Ϊ�ǿ�ѭ�������βָ��
LinkList Connect(LinkList A, LinkList B)
{
	LinkList p = A->next; //����A���ͷ���λ��

	A->next = B->next->next; //B��Ŀ�ʼ������ӵ�A��β

	free(B->next); //�ͷ�B���ͷ��㣬��ѧ����������

	B->next = p;

	return B; //������ѭ�������βָ��
}

//�������Ƿ��л�
//1.�Ƚϲ����ķ���
int HasLoop1(LinkList L)
{
	LinkList cur1 = L; //������cur1
	int pos1 = 0; //cur1�Ĳ���

	while (cur1)
	{
		while (cur2)
		{
			LinkList cur2 = L;//������cur2
			int pos2 = 0;//cur2�Ĳ���
			if (cur2 == cur1)
			{
				if (pos1 == pos2)
					break;
				else
				{
					printf("����λ���ڵ�%d����㴦,\n\n", pos2);
					return 1;//�л�������1
				}
			}
			cur2 = cur2->next;//���û���ֻ���������һ�����
			pos1++;//cur2��������
		}
		cur1 = cur1->next;//cur1�������һ�����
		pos1++;
	}
	return 0;
}
//2.����ָ�뷽ʽ
int HasLoop2(LinkList L)
{
	int step1 = 1;
	int step2 = 2;
	LinkList p = L;//��
	LinkList q = L;//��

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

//ħ��ʦ��������
void Magician(LinkList head)
{
	linklist p;
	int j;
	int Countnumber = 2;

	p = head;
	p->data = 1; //��һ���Ʒ�1

	while (1)
	{
		for (j = 0;j < Countnumber;j++)
		{
			p = p->next;
			if (p->data != 0) //��λ�����ƵĻ�������һ��λ��
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


//˫��������ṹ
typedef struct DualNode
{
	ElemType data;
	struct DualNode* prior;//ǰ���ڵ�
	struct DualNode* next;//��̽ڵ�
}DualNode, * DuLinkList;

//˫������������
s->next = p;
s->prior = p->prior;
p->prior->next = s;
p->prior = s;

//˫�������ɾ������
p->prior = p->next;
p->next->prior = p->prior;
free(p);

//˫������ʵ��
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

//step1: ��ʼ��
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
//step2: ����
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