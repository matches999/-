#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;
}*LinkList;

void CreatLinkList(LinkList &L) {
	LinkList p;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;

	p = (LNode*)malloc(sizeof(LNode));
	cin >> p->data;
	while (p->data != -10000)
	{
		p->next = L->next;
		L->next = p;
		p = (LNode*)malloc(sizeof(LNode));
		cin >> p->data;

	}

}


void PrintLinkList(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p) {
		cout << p->data << ' ';
		p = p->next;
	}

}
void MergeLinkList(LinkList La, LinkList Lb, LinkList &Lc)
{
	LinkList pa, pb, pc;
	Lc = La; pc = La;
	pa = La->next; pb = Lb->next;//指针分别指向ab的第一个节点
	//判断两个是否为空
	while (pa && pb)
	{
		if (pa->data < pb->data)
		{
			pc->next = pa; pc = pa; pa = pa->next;
		}
		else
		{
			pc->next = pb; pc = pb; pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;

}
int main()
{
	LinkList La,Lb,Lc;
	CreatLinkList(La); CreatLinkList(Lb);
	MergeLinkList(La,Lb,Lc);
	PrintLinkList(Lc);
	getchar();
	getchar();
	return 0;

}

