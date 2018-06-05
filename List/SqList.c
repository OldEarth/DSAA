#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

Status visit(ElemType c)
{
	printf("%d ",c);
	return OK;
}

Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e  = L.data[i-1];
	return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	int j;
	if(L->length==MAXSIZE)
		return ERROR;
	if(i<1 || i>L->length+1)
		return ERROR;
	if(i<=L->length){
		for(j=L->length-1;j>=i-1;j--)
			L->data[j+1] =  L->data[j];
	}
	L->data[i-1] = e;
	L->length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if(i<1 || i>L->length)
		return ERROR;
	if(L->length == 0)
		return ERROR;
	*e = L->data[i-1];
	if(i<L->length)
		for(k=i-1;k<L->length-1;k++)
			L->data[k] = L->data[k+1];
	L->length--;
	return OK;
}

Status InitList(SqList *L)
{
	L->length = 0;
}

Status ListTraverse(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}

Status ListEmpty(SqList L)
{
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status LocateElem(SqList L,ElemType j)
{
	int i;
	if(L.length==0)
		return 0;
	for(i=0;i<L.length;i++){
		if(L.data[i]==j)
			return i+1;
	}
	if(i>=L.length)
		return 0;
}

main()
{
	SqList L;
	ElemType e;
	Status i;
	int j,k;
	i = InitList(&L);
	printf("初始化之后:L.length=%d\n", L.length);
	for(j=1;j<=5;j++)
		i  = ListInsert(&L,1,j);
	printf("在表头依次插入1-5后: L.data =");
	ListTraverse(L);

	printf("L.length=%d\n",L.length);
	i = ListEmpty(L);
	printf("L是否为空: i=%d(1:是 0:否)\n",i);
	
	i = ClearList(&L);
	printf("清空L后: L.length=%d\n",i);

	for(j=1;j<=10;j++)
		ListInsert(&L,j,j);
	ListTraverse(L);

	ListInsert(&L,1,0);
	ListTraverse(L);

	GetElem(L,5,&e);
	printf("第5个元素的值为:%d\n",e);

	for(j=3;j<=4;j++){
		k=LocateElem(L,j);
		if(k)
			printf("第%d元素为%d\n",k,j);
		else
			printf("没有值为%d的元素\n",j);
	}

	k = L.length;
	for(j=k+1;j>=k;j--){
		i = ListDelete(&L,j,&e);
		if(i==ERROR)
			printf("删除第%d个数据失败\n",j);
		else
			printf("删除第%d个的元素值为: %d\n",j,e);
	}
	ListTraverse(L);
}
