 //字符串的存储结构：顺序存储结构
//BF算法，串的模式匹配，暴力破解

//KMP算法
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
	//因为前缀是固定的，后缀是相对的
}

//返回子串T在主串s第pos个字复之后的位置
//若不存在，则返回0
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