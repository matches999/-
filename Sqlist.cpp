#include<stdio.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int status;		// Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int elemtype;	//定义线性表元素的数据类型，便于后期修改操作

typedef struct
{
	elemtype data[MAXSIZE];		//开辟一段空间（占座）
	int length;					//当前线性表的长度，在初始化函数中确定大小
}Sqlist;

//初始化线性表,建立一个空的线性表
status InitList(Sqlist *L) 
{
	L->length = 0;
	return OK;
}

status ListEmpty(Sqlist L)
{
	if (L.length == 0)
		return true;
	else
		return false;
}

status ClearList(Sqlist *L)
{
	L->length = 0;
	return OK;
}

/*得到线性表中第i个元素并通过e返回，这里是传入一个地址进去接收得到的值。
注意事项：
1.若线性表为空，返回error
2.若i不在当前线性表长度范围内，返回error
3.在范围内时，注意线性表的元素位置，与数组位置的差值*/
status GetElem(Sqlist L, int i, int *e)
{
	if (L.length == 0||i<1||i>L.length)
	{
		return ERROR;
	}
	//这一步可以省略下面的if语句，因为if语句顺序执行到这里，只有(<=)这种情况未考虑
	//if (i <= L.length)
	//{
		*e = L.data[i - 1];
	//}
	return OK;
}

//查找线性表内是否存在对应元素
status LocateElem(Sqlist L,int e)
{
	if (L.length == 0)
		return ERROR;
	//注意这里的循环条件
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i;
	}
	return ERROR;
}
/*插入元素条件：
1.已达到最大容量的线性表不可插入
2.插入的位置不合理也不可插入
注意：
数组与线性表之间下标的关系
插入元素后，线性表长度发生变化，记得+1*/
status ListInsert(Sqlist *L, int i,int e)
{
	int k;
	if (L->length == MAXSIZE || i<1 || i>MAXSIZE)
		return ERROR;
	if (i >= 1 && i <= L->length)
	{
		for (k = L->length; k >= i; k--)
		{
			L->data[k] = L->data[k - 1];
		}
		
	}
	//如果线性表没有满，且插入元素位置在当前长度与最大容量之间，可直接插入
	L->data[i-1] = e;
	L->length++;
	return OK;

}

/*删除元素并通过地址返回被删除元素的值
条件：1、表是否为空，是否在线性表中
删除元素后，长度-1*/
status ListDelete(Sqlist *L, int i, int *e)
{
	if (L->length == 0||i<1||i>L->length)
		return ERROR;
	//注意这里的循环次数
	for (int k = i-1; k < L->length-1; k++)
	{
		L->data[k] = L->data[k + 1];
	}
	L->length--;
	return OK;
}

status ListLength(Sqlist L)
{
	return L.length;
}

/*求并集：将所有在线性表Lb中但不在La中的元素插入到La中*/
void UnionList(Sqlist *La,Sqlist Lb)
{
	int La_len, Lb_len;
	La_len = ListLength(*La);
	Lb_len = ListLength(Lb);
	for (int i = 1; i <= Lb_len; i++)
	{
		int e;
		GetElem(Lb, i, &e);
		if (!LocateElem(*La, e)) 
		{
			ListInsert(La,++La_len,e);
		}
	}

}
int main()
{


	getchar();
	return 0;
}
