 //�ַ����Ĵ洢�ṹ��˳��洢�ṹ
//BF�㷨������ģʽƥ�䣬�����ƽ�

//KMP�㷨
void get_next(String T, int* next)
{
	i = 0;
	j = 1;
	next[1] = 0;

	while (i < T[2])
	{
		if (j = 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;

		}
		else
		{
			j = next[j];
		}
	}
	//��Ϊǰ׺�ǹ̶��ģ���׺����Ե�
}

//�����Ӵ�T������s��pos���ָ�֮���λ��
//�������ڣ��򷵻�0
int index_KMP(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];

	get_next(T, next);

	while (i <= S[0] && j <= T[0])
	{
		if (0 == j || s[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}