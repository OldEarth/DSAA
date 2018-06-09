#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

Status InitStack(SqStack *s)
{
	s->top = -1;
	return OK;
}

Status Push(SqStack *s, SElemType e)
{
	if(s->top == MAXSIZE-1)
		return ERROR;
	s->top++;
	s->data[s->top] = e;
	return OK;
}

Status StackTraverse(SqStack s)
{
	int i = 0;
	while(i<=s.top){
		printf("%d ",s.data[i++]);
	}
	printf("\n");
	return OK;
}

Status Pop(SqStack *s,SElemType *e)
{
	if(s->top<0)
		return ERROR;
	*e = s->data[s->top];
	s->top--;
	return OK;
}

Status StackEmpty(SqStack s)
{
	if(s.top==-1)
		return OK;
	return ERROR;
}

Status GetTop(SqStack s,int *e)
{
	if(s.top==-1)
		return ERROR;
	*e = s.data[s.top];
	return OK;
}

int StackLength(SqStack s)
{
	return s.top+1;
}

void ClearStack(SqStack *s)
{
	s->top = -1;
}

int main()
{
	SqStack s;
	int j,e;
	if(InitStack(&s))
		for(j=1;j<=10;j++)
			Push(&s,j);
	printf("栈中元素依次为: ");
	StackTraverse(s);
	Pop(&s,&e);
	printf("弹出的栈顶元素 e=%d\n",e);
	printf("栈空否: %d(1:空0:否)",StackEmpty(s));
	GetTop(s,&e);
	printf("栈顶元素e=%d 栈的长度为%d\n",e,StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否; %d(1:空0:否)\n", StackEmpty(s));
	return 0;
}	
