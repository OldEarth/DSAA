#include <stdio.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int Status;
typedef int QElemType;

typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *q)
{
	q->front = 0;
	q->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue q)
{
	if(q.front == q.rear)
		return OK;
	else
		return ERROR;
}

int QueueLength(SqQueue q)
{
	return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue *q, QElemType i)
{
	if((q->rear+1)%MAXSIZE == q->front)
		return ERROR;
	q->data[q->rear] = i;
	q->rear = (q->rear+1)%MAXSIZE;
	return OK;
}

Status QueueTraverse(SqQueue q)
{
	int i;
	i = q.front;
	while(i!=q.rear){
		printf("%d ",q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	printf("\n");
	return OK;
}

Status DeQueue(SqQueue *q, QElemType *e)
{
	if(q->front == q->rear)
		return ERROR;
	*e = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	return OK;
}

int main()
{
	SqQueue Q;
	int i,d;
	InitQueue(&Q);
	printf("初始化队列后，队列是否为空？%d(1:空0:否)\n",QueueEmpty(Q));
	for(i=0;i<MAXSIZE-1;i++)
		EnQueue(&Q,i+100);
	printf("队列长度为：%d\n",QueueLength(Q));
	printf("现在队列中的元素为:\n");
	QueueTraverse(Q);
	while(QueueLength(Q)>2){
		DeQueue(&Q,&d);
		printf("删除的元素值为%d\n", d);
	}
	QueueTraverse(Q);
}
