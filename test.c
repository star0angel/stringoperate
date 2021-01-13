#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

#include <stdio.h>
#include <string.h>

//判断一个字符串是否有某个字符  并替换成另一个字符输出
 
int main()
{
	char a[] = "aaasdfdgdfgdf";
	char b[] = "df";
	int lena = strlen(a);//保存母串的长度
	int lenb = strlen(b);//保存查找的子串长度
	char c[100] = { 0 };
	printf("请输入你要替换的字符串：");
	scanf("%s", c);
	int lenc= strlen(c);//保存替换的子串长度
	//char* p = strstr(a, b);
	
	char* dest = a;//指向a
	char q[100] = { 0 };
	char *pq = q;
	for (char *p= strstr(dest, b);p; p = strstr(dest, b))
	{
		int i = 0;//设置循环
		for (i = 0; i < p - dest; i++)
		{
			pq[i] = dest[i];//前面的复制过去到q
		}
		strcat(pq, c);//前面的+子串
		pq = p - dest + pq + lenc;//指针pq指向q字符串的末尾
		dest = p + lenb;//dest指向母串第一个过去的子串
	}
	strcat(q, dest);//把结尾带上 
	printf("%s", q);
	//int i = 0;
	//char q[100] = {0};
	//for (i=0;i<p-a;i++)
	//{
	//	q[i] = p[i];
	//}
	////q[i] = '\0';
	//strcat(q, c);
	//strcat(q, &a[p - a + lenb]);
	//printf("%s",q);
	return 0;
}