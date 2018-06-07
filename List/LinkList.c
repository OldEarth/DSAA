#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	if(!(*L))
		return ERROR;
	(*L)->next = NULL;
	
	return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while(p && j<i){
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p;
	LinkList s;
	int j=1;
	p = *L;
	while(p->next&&j<i){
		p = p->next;
		j++;	
	}
	if(!(p->next) || j>i)
		return ERROR;
	s = p->next;
	p->next = s->next;
	*e = s->data;
	free(s);
	return OK;
}

Status ListTraverse(LinkList L)
{
	LinkList p = L;
	p = p->next;
	if(!p)
		return ERROR;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int ListLength(LinkList L)
{
	LinkList p = L->next;
	int j = 0;
	while(p){
		j++;
		p = p->next;
	}
	return j;
}

Status ClearList(LinkList *L)
{
	LinkList p = (*L)->next;
	LinkList q;
	while(p){
		q = p->next;
		free(p);
		p = q; 
	}
	(*L)->next = NULL;
	return OK;
}

Status GetElem(LinkList L, int i,ElemType *e)
{
	LinkList p = L->next;
	LinkList q;
	int j = 0;
	while(p&&j<i){
		j++;
		q = p;
		p = p->next;
	}
	if(!p||j>i)
		return ERROR;
	*e = q->data;
	return OK;
}

int LocateElem(LinkList L, int j)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while(p){
		i++;
		if(p->data==j)
			return i;
		p = p->next;
	}
	if(!p)
		return ERROR;
}

void CreateListHead(LinkList *L,int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i=0;i<n;i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1; //随机生成100以内的数字
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

void CreateListTail(LinkList *L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0;i<n;i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;	
	}
	r->next = NULL;
}

int main()
{
	LinkList L;
	Status i;
	int j,k;
	ElemType e;
	i = InitList(&L);
	printf("初始化之后，ListLength(L)=%d\n",ListLength(L));

	for(j=1;j<=5;j++)
		i=ListInsert(&L,1,j);
	printf("在L表头依次插入1-5后: L.data=");
	ListTraverse(L);
	
	printf("ListLength(L)=%d \n",ListLength(L));

	i = ClearList(&L);
	printf("清空L后: ListLength=%d\n",ListLength(L));

	for(j=1;j<=10;j++)
		ListInsert(&L,j,j);
	printf("在L的表尾依次插入1-10后: L.data=");
	ListTraverse(L);
	printf("ListLength(L)=%d\n",ListLength(L));

	ListInsert(&L,1,0);
	printf("在L的表头插入0后: L.data=");
	ListTraverse(L);

	GetElem(L,5,&e);
	printf("第五个元素为:%d\n",e);
	for(j=3;j<=4;j++){
		k = LocateElem(L,j);
		if(k)
			printf("第%d个元素的值为%d\n",k,j);
		else
			printf("没有值为%d的元素\n",j);
	}

	k = ListLength(L);
	for(j=k+1;j>=k;j--){
		i = ListDelete(&L,j,&e);
		if(i == ERROR)
			printf("删除第%d个数据失败\n",j);
		else
			printf("删除第%d个元素值为%d\n",j,e);
	}
	printf("依次输出L的元素:");
	ListTraverse(L);
	
	i = ClearList(&L);
	printf("\n清空L后: ListLength(L)=%d\n",ListLength(L));	
	CreateListHead(&L,20);
	printf("整体创建L的元素（头插法）：");
	ListTraverse(L);
	
	i = ClearList(&L);
	printf("\n清空L后: ListLength(L)=%d\n",ListLength(L));	
	CreateListTail(&L,20);
	printf("整体创建L的元素（尾插法）：");
	ListTraverse(L);
}
