#include "c1.h"

typedef int QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode *next;//*next->QNode *next
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue  &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
		}
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	QNode *p;//int->QNode
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data=e; p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	if(Q.front=Q.rear) return ERROR;
	QNode *p;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;//Q.front的next的next
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK; 
}

int main(){
	LinkQueue Q;
	InitQueue(Q);
	DestroyQueue(Q);
	QElemType e=1;
	EnQueue(Q,e);
	QElemType f;
	DeQueue(Q,f);
	return 0;
}
