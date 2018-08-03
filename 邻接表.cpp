#include<stdio.h>
#include<malloc.h>
#define Status int
#define OK 0
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


Status CreateGraph(ALGraph *G){

    printf("输入顶点数和弧数");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    for(int i=0;i<G->vexnum;++i)
        {   printf("请输入第%d个顶点的值：",i+1);
            scanf("%d",&G->vertices[i].data);
            G->vertices[i].firstarc=NULL;// 将边表置为空表
           //构造顶点向量           {
            int m;
            printf("请输入与该顶点相连的结点个数：");
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
            int a;
            printf("请输入与该顶点相连的第%d个结点：",j+1);
            scanf("%d",&a);
            ArcNode *s;
            s=(ArcNode*)malloc(sizeof(ArcNode));
            s->adjvex=a;
            s->nextarc=G->vertices[i].firstarc;  //插入前一个
            G->vertices[i].firstarc=s;
            }
            }
        return OK;
        }


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
       s=(ArcNode*)malloc(sizeof(ArcNode));
       s->adjvex=i;
       s->nextarc=G->vertices[j].firstarc;
       G->vertices[j].firstarc=s;
   }
}//此方法借鉴http://blog.csdn.net/linxinyuluo/article/details/6847851

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

int main(){
    printf("邻接表建立一个图\n例：\n0->3->2->1\n1->3->2->0\n2->1->0\n3->1->0\n");
    ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));
    CreateGraph(G);
    Print(G);
    Create(G);
    Print(G);
    return 0;
    }

