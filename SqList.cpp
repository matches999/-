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
int SqListEmpty(SqList L)//�ж��Ƿ����Ա�Ϊ��
{
	if (L.length == 0)
	{
		return true;
	}
	else
		return false;
}
void ClearSqList(SqList L)//���˳���
{
	L.length = 0;
}
void DeleteSqList(SqList &L ,int i)//ɾ��˳����е�һ��Ԫ��
{
	if (i >= L.length)
		cout << "please refresh this Sqlist's position." << endl;
	else if (i >= 0 && i < L.length)
	{
		for (i; i < L.length; i++)//Ĭ��λ�ô�0��ʼ,ɾ���ڼ���Ԫ�أ���Ҫ���ǵ�-1
		{
			L.elem[i-1] = L.elem[i];
		}
		L.length--;
	}
}
//key point����ɾ��λ�ÿ�ʼ���������һ��Ԫ�أ��ֱ�����ǰ��һλ��
//����-1��
//���ɾ���������һ��Ԫ�أ���ôĿǰ����������ɾ�� ��ֻ��ͨ�������ı䣬��ʱ��������
void InsertSqList(SqList &L, int i, int elem)
{
	for (int k=L.length;i<k;k--)
	{
		L.elem[k] = L.elem[k - 1];
	}
	L.elem[i] = elem;
	L.length++;
}
void UnionSqList(SqList &La, SqList &Lb, SqList &Lc)//����˳���ϲ���һ��˳���
{
	//��һ�����������˳����δ�ﵽĩβ
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

	//�ڶ������������˳�������һ���Ѿ��ﵽĩβ
}

int main()
{
	//SqList L;
	//InitSqList(L);//��ʼ�����Ա����Ҫ
	//CreatSqList(L);
	//PrintSqList(L);
	//DeleteSqList(L, 3);
	//InsertSqList(L, 3, 1314);
	//PrintSqList(L);

	//ʵ�ֺϲ�����
	SqList La, Lb, Lc;
	InitSqList(La); InitSqList(Lb); InitSqList(Lc);
	CreatSqList(La); CreatSqList(Lb);
	UnionSqList(La,Lb,Lc);

	PrintSqList(Lc);





	system("pause");
	return 0;

}