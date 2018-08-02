#include "c1.h"
#define MAXQSIZE 100//不用加;
typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
	Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q.base)exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}//创建队列

int QueueLength(SqQueue Q){
	return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;//if rear+1<M rear=rear+1;if rear+1=M rear=0;
}//队列长度

Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear+1)%MAXQSIZE==Q.front)return ERROR;
	Q.base[Q.rear+1]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE;
	return OK;
}//插入队尾元素

Status DeQueue(SqQueue &Q,QElemType e){
	if(Q.front==Q.rear) return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	printf("%d",e);
}//删除队头元素

int main(){
	SqQueue sq;
	InitQueue(sq);
	QueueLength(sq);
	QElemType e;
	EnQueue(sq,e);
	QElemType f;
	DeQueue(sq,f);
	return 0;
}
