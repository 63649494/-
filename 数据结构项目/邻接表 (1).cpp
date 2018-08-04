#include<stdio.h>
#include<malloc.h>
#define Status int
#define OK 0
#define ERROR -1
#define MAX_VERTEX_NUM 100       //最大顶点个数

typedef int InfoType;
typedef int VertexType;

typedef struct ArcNode{
    int adjvex; //该弧所指向的顶点的位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
    //InfoType  *info;       //该弧相关信息的指针
    }ArcNode;//表结点

typedef struct VNode{
    VertexType data;        //顶点信息
    ArcNode *firstarc;      //指向第一条依附该定点的弧的指针
    }VNode,AdjList[MAX_VERTEX_NUM];//头结点

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;  //图的当前顶点数和弧数
   // int kind;           //图的种类标志
    }ALGraph;


void Create(ALGraph* G)
{
    int i,j,k,w,v;
    ArcNode *s;
    printf("请输入顶点数和边数");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    printf("建立表头\n");
    for(i=0;i<G->vexnum;i++)
        {   printf("请输入第%d个顶点：",i+1);
            scanf("%d",&G->vertices[i].data);
            G->vertices[i].firstarc = NULL;// 将边表置为空表
           }//构造顶点向量

    printf("建立边表\n");
    for (k=0;k<G->arcnum;k++)
    {
       printf("请输入第%d条边的头结点，表结点：",k+1);
       scanf("%d,%d",&i,&j);
       s=(ArcNode*)malloc(sizeof(ArcNode));
       s->adjvex=j;
       s->nextarc=G->vertices[i].firstarc;  //插入表头
       G->vertices[i].firstarc=s;
      /* s=(ArcNode*)malloc(sizeof(ArcNode));//若为无向图去掉注释
       s->adjvex=i;
       s->nextarc=G->vertices[j].firstarc;
       G->vertices[j].firstarc=s;*/
   }
}

void Print(ALGraph* G){
    for (int i=0;i< G->vexnum;i++)
   {
       printf("%d->",i);
       while(G->vertices[i].firstarc!=NULL)
       {
            printf("%d->",G->vertices[i].firstarc->adjvex);
            G->vertices[i].firstarc=G->vertices[i].firstarc->nextarc;

       }
       printf("\n");
   }
}

//定义栈及其相关函数
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;

typedef struct{
    int *base;
    int *top;
    int stacksize;
    }SqStack;

    int InitStack(SqStack &S){
    S.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!S.base) exit(1);
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return 0;
    }

int StackEmpty(SqStack S){
    if(S.top==S.base) return 1;
    else return 0;
    }


int Push(SqStack &S,int q){
    if(S.top-S.base>=S.stacksize){
        S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));//是realloc不是malloc
        if(!S.base) exit(1);
        S.top=S.base+S.stacksize;
        S.stacksize=S.stacksize+STACKINCREMENT;
        }
        *S.top++=q;
        printf("%4d",q);
        return 0;
    }


int Pop(SqStack &S,int &e){
    if(S.top==S.base) return 1;
    e=*--S.top;
    return 0;
    }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 /*void FindInDegree(ALGraph G,int indegree[])
 { /* 求顶点的入度
   int i,j;
   ArcNode *p;
   for(i=0;i<G.vexnum;i++)
     indegree[i]=0; /* 赋初值
   for(i=0;i<G.vexnum;i++)
      for(p=G.vertices[i].firstarc;p;p=p->nextarc)
            indegree[p->adjvex]++;
    for(j=0;j<G.vexnum;j++)
    printf("%4d",indegree[j]);
 }*/

void FindInDegree(ALGraph G,int indegree[]){
    int i,j;
    for(i=0;i<G.vexnum;i++){
        printf("请输入第%d个顶点的度",i+1);
        scanf("%d",&indegree[i]);
        }
    for(j=0;j<G.vexnum;j++)
    printf("%4d",indegree[j]);
    printf("\n");
    }

Status TopologicalSort(ALGraph G){
    int indegree[MAX_VERTEX_NUM];
    FindInDegree(G,indegree);//求入度，放在indegree里
    SqStack S;
    InitStack(S);
    int i,k,count;
    ArcNode *p;
    for(i=0;i<G.vexnum;++i)
        if(!indegree[i]) Push(S,i);
    count=0;
    while(!StackEmpty(S)){
        Pop(S,i);   printf("\n输出%d号顶点为%d\n",i,G.vertices[i].data);
        ++count;
        printf("%d\n",count);
        for(p=G.vertices[1].firstarc; p ;p=p->nextarc){
            printf("text");
            k=p->adjvex;
            if(!(--indegree[k]))   Push(S,k);
            }
        }
    if(count<G.vexnum) {
        printf("该图有回路");
        return ERROR;}
    else {
        printf("该图无回路");
        return OK;}
    }

int main(){
    printf("邻接表建立一个图\n例：\n0->2\n1->0\n2->3\n3->\n");
    ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));
    Create(G);
    Print(G);
    TopologicalSort(*G);
    return 0;
    }

