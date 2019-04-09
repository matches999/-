#include<iostream>

using namespace std;
typedef struct SqList
{
	int maxSize;
	int length;
	int *elem;
};
void InitSqList(SqList &L)
{
	L.elem = (int *)malloc(20 * sizeof(int));
	L.maxSize = 20;
	L.length = 0;
}
void CreatSqList(SqList &L)
{
	int n;
	do
	{
		cin >> n;
		if (n != -10000) {
			L.elem[L.length] = n;
			L.length++;
		}
	} while (n != -10000);
}
void PrintSqList(SqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << ' ';
	}
	cout << endl;
}
int SqListEmpty(SqList L)//判断是否线性表为空
{
	if (L.length == 0)
	{
		return true;
	}
	else
		return false;
}
void ClearSqList(SqList L)//清空顺序表
{
	L.length = 0;
}
void DeleteSqList(SqList &L ,int i)//删除顺序表中的一个元素
{
	if (i >= L.length)
		cout << "please refresh this Sqlist's position." << endl;
	else if (i >= 0 && i < L.length)
	{
		for (i; i < L.length; i++)//默认位置从0开始,删除第几个元素，需要考虑到-1
		{
			L.elem[i-1] = L.elem[i];
		}
		L.length--;
	}
}
//key point：从删除位置开始遍历到最后一个元素，分别将他们前移一位；
//最后表长-1；
//如果删除的是最后一个元素，那么目前不是真正的删除 ，只是通过将表长改变，暂时看不见？
void InsertSqList(SqList &L, int i, int elem)
{
	for (int k=L.length;i<k;k--)
	{
		L.elem[k] = L.elem[k - 1];
	}
	L.elem[i] = elem;
	L.length++;
}
void UnionSqList(SqList &La, SqList &Lb, SqList &Lc)//两个顺序表合并成一个顺序表
{
	//第一种情况，两个顺序表均未达到末尾
	int i = 0;int j = 0;
	while (i<La.length&&j<Lb.length)
	{
		if (La.elem[i] < Lb.elem[j])
		{
			Lc.elem[Lc.length++] = Lb.elem[j];
			j++;
		}
		else
		{
			Lc.elem[Lc.length++] = La.elem[i];
			i++;
		}
	}
	while(j<Lb.length)
	{	
			Lc.elem[Lc.length++] = Lb.elem[j];
			j++;
	}
	while(i<La.length)
	{
			Lc.elem[Lc.length++] =La.elem[i];
			i++;
	}

	//第二种情况，两个顺序表中有一个已经达到末尾
}

int main()
{
	//SqList L;
	//InitSqList(L);//初始化线性表很重要
	//CreatSqList(L);
	//PrintSqList(L);
	//DeleteSqList(L, 3);
	//InsertSqList(L, 3, 1314);
	//PrintSqList(L);

	//实现合并操作
	SqList La, Lb, Lc;
	InitSqList(La); InitSqList(Lb); InitSqList(Lc);
	CreatSqList(La); CreatSqList(Lb);
	UnionSqList(La,Lb,Lc);

	PrintSqList(Lc);





	system("pause");
	return 0;

}