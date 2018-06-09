#include <stdio.h>

#define ERROR 0
#define OK 1
#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;

Status InitStack(SqDoubleStack *s)
{
	s->top1 = -1;
	s->top2 = MAXSIZE;
	return OK;
}

Status Push(SqDoubleStack *s, SElemType e, int stackNumber)
{
	if(s->top1+1==s->top2)
		return ERROR;
	if(stackNumber==1)
		s->data[++s->top1] = e;
	else if(stackNumber==2)
		s->data[--s->top2] = e;
	return OK;
}

Status StackTraverse(SqDoubleStack s)
{
	int i = 0;
	while(i<=s.top1)
		printf("%d ",s.data[i++]);
	i = s.top2;
	while(i<MAXSIZE)
		printf("%d ",s.data[i++]);
	printf("\n");
	return OK;
}

int StackLength(SqDoubleStack s)
{
	return (s.top1+1)+(MAXSIZE-s.top2);
}

Status StackEmpty(SqDoubleStack s)
{
	if(s.top1==-1&&s.top2==MAXSIZE)
		return OK;
	else
		return ERROR;
}

Status Pop(SqDoubleStack *s, int *e, int stackNumber)
{
	if(s->top1<0||s->top2>=MAXSIZE)
		return ERROR;
	if(stackNumber==1)
		*e = s->data[s->top1--];
	else if(stackNumber==2)
		*e = s->data[s->top2++];
	return OK;
}

void ClearStack(SqDoubleStack *s)
{
	s->top1 = -1;
	s->top2 = MAXSIZE;
}

int main()
{
	SqDoubleStack s;
	int j,e;
	if(InitStack(&s)){
		for(j=1;j<=5;j++)
			Push(&s,j,1);
		for(j=MAXSIZE;j>=MAXSIZE-2;j--)
			Push(&s,j,2);
	}
	
	printf("栈中元素依次为:");
	StackTraverse(s);	

	printf("当前栈中元素有: %d\n",StackLength(s));
	
	Pop(&s,&e,2);
	printf("弹出的栈顶元素 e=%d\n",e);
	printf("栈是否空：%d(1:空0:否)\n",StackEmpty(s));

	ClearStack(&s);
	printf("清空栈后，栈空否: %d(1:空0:否)\n",StackEmpty(s));
	return 0;
}
