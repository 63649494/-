#include<string.h>
#include<malloc.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h> /* floor(),ceil(),abs() */

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define max_n 20
#define MAXQSIZE 20

typedef int Status;
typedef int Elemtype;

typedef struct{
    int *base;      //初始化的动态分配存储空间
    int front;      //头指针，若队列不空，指向队列头元素
    int rear;       //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

int InitQueue(SqQueue &Q){   //构造一个空队列Q
    Q.base=(int *)malloc(MAXQSIZE*sizeof(int));
    if(!Q.base){        //存储分配失败
        exit(OVERFLOW);
    }
    Q.front=Q.rear=0;
    return OK;
}

int EnQueue(SqQueue &Q,int e){  //插入元素e为Q的新的队尾元素
    if((Q.rear+1)%MAXQSIZE==Q.front){   //队列满
        return ERROR;
    }
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}


int DeQueue(SqQueue &Q,int &e){//删除Q的队头元素，并用e返回其值
    if(Q.front==Q.rear){
        return ERROR;
    }
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

int DefQueue(SqQueue &Q,int &e){//删除Q的队头元素，并用e返回其值
    if(Q.front==Q.rear){
        return ERROR;
    }
    e=Q.base[Q.rear];
    Q.rear=(Q.rear-1)%MAXQSIZE;
    return OK;
}

int DerQueue(SqQueue &Q,int &e){//删除Q的队尾元素，并用e返回其值
    if(Q.front==Q.rear){
        return ERROR;
    }
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

int QueueLength(SqQueue Q){  //返回队列的长度
    return(Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int isEmpty(SqQueue &Q)
{
    if(Q.front==Q.rear)
    {
        printf("对列为空\n");
        return 0;
    }
    else
    {
    printf("对列不为空\n");
    return 1;
    }
}



/*******队列操作*********/

int Support(SqQueue &S,int e){
        int r,t;
        t=isEmpty(S);
        if(t==1)//辅助轨不为空
                {
                DeQueue(S,r);//读取队头
                if(e>r)
                {
                EnQueue(S,e);return 0;
                }
                else//e<r
                return 1;}
        else
        {   printf("辅助轨为空\n");
            EnQueue(S,e);
        return 0;}//辅助轨为空直接进入
}
int Outtrack(SqQueue &S,SqQueue &P,int i){
     int a;
     DeQueue(S,a);
     if(a==i){
     EnQueue(P,a);//出轨
     return 0;}
     else
     return 1;
          }//出轨

int Track(int *a,int n,SqQueue &Q,SqQueue &P,SqQueue &S1,SqQueue &S2,SqQueue &S3){
    int i,j,k,z;
    for(i=0;i<n;i++)
        EnQueue(Q,a[i]);//创建入轨队列
    printf("此时入轨队列长度%d\n",QueueLength(Q));
    int e;
    for(i=0;i<n;i++){
        z=isEmpty(Q);
        printf("z为%d,1不为空，0为空\n",z);
        if(z==1){//入队队列不为空；
            for(j=0;j<n;j++){
            DeQueue(Q,e);//读取队头
            printf("此时队列长度%d\n",QueueLength(Q));
            if(e==1)
                EnQueue(P,e);//出轨
            else{//e！=1
                /********问题*********/
                if(Support(S1,e))//e<r下一辅助轨
                    if(Support(S2,e))
                        if(Support(S3,e))
                            printf("没有足够辅助轨\n");
                    }
                }
            }
        else//入队队列为空
        {
            printf("此时出轨队列长度%d\n",QueueLength(P));
            printf("进行出轨\n");
            for(k=2;k<=n;k++){
                if(Outtrack(S1,P,k))
                printf("%d号车厢出列\n",k);
                else//a!=i
                {if(Outtrack(S2,P,k))
                    printf("%d号车厢出列\n",k);
                    else//a!=i
                    {if(Outtrack(S3,P,k))
                        printf("%d号车厢出列\n",k);
                        else
                        printf("%d号车厢出列过程出错\n",k);
                        }
                    }
            }
        break;
        }
        }

}


int main(){
    int i,n;
    SqQueue Q,P,S1,S2,S3;
    InitQueue(Q);
    InitQueue(P);
    InitQueue(S1);
    InitQueue(S2);
    InitQueue(S3);
    printf("请输入火车车厢数：");
    scanf("%d",&n);
    int a[n];
    printf("请输入火车入轨次序：");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    Track(a,n,Q,P,S1,S2,S3);//数组a的引用出过问题
    }
