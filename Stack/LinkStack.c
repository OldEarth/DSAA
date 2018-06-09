#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int SElemType;

typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

Status InitStack(LinkStack *s)
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!s->top)
		return ERROR;
	s->top = NULL;
	s->count = 0;
	return OK;
}

Status Push(LinkStack *s, SElemType e)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = e;
	p->next = s->top;
	s->top = p;
	s->count++;
	return OK;
}

void StackTraverse(LinkStack s)
{
	LinkStackPtr p;
	p = s.top;
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

Status StackEmpty(LinkStack *s)
{
	if(s->count==0)
		return OK;
	else
		return ERROR;
}

Status Pop(LinkStack *s, SElemType *e)
{
	LinkStackPtr p;
	if(StackEmpty(s))
		return ERROR;
	p = s->top;
	*e = p->data;
	s->top = p->next;
	free(p);
	s->count--;
	return OK;
}

int main()
{
	LinkStack s;
	int j,e;
	if(InitStack(&s))
		for(j=1;j<=10;j++)
			Push(&s,j);
	printf("栈中的元素依次为: ");
	StackTraverse(s);
	Pop(&s,&e);
	printf("弹出的栈顶元素:e=%d\n",e);
	
}
