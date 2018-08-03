#include<stdio.h>
#include<string.h>
#include<limits.h>
#define INFINITY INT_MAX
#define VRType int
#define InfoType int
#define VertexType int
#define Status int
#define max_n 20
#define OK 0
typedef enum{DG, DN, AG, AN} GraphKind;//{有向图，有向网，无向图，无向网}

//  弧结点与矩阵的类型
typedef struct {
    VRType    adj;          //VRType为弧的类型。图--0,1;网--权值
    InfoType  *Info;        //与弧相关的信息的指针
}ArcCell, AdjMatrix[max_n][max_n];

//  图的类型
typedef struct{
    VertexType vexs[max_n];     // 顶点向量
    AdjMatrix  arcs;            // 邻接矩阵
    int vexnum;
    int arcnum;  // 图的顶点数，弧数
    GraphKind  kind;            // 图类型
}MGraph;

 int LocateVex(MGraph G,VertexType u)                            //返回顶点u在图G中的位置
  {   int i;
      for(i=0;i<G.vexnum;++i)
           if(u=G.vexs[i])
              return   i;
      return   0;
 }

 Status CreateUDG(MGraph &G){
     int v1;
     int v2;
     printf("请输入无向图的顶点数，弧数：");
     scanf("%d,%d",&G.vexnum,&G.arcnum);//IncInfo为0则各弧不含其它信息
     for(int i=0;i<G.vexnum;++i)
        {   printf("请输入第%d个顶点：",i+1);
            scanf("%d",&G.vexs[i]);}//构造顶点向量
    /* for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;++j)
            G.arcs[i][j]={INFINITY,NULL};//[adj,info]*/
     for(int k=0;k<G.arcnum;++k){
         printf("请输入第%d条边依附的两个顶点：",k+1);
         scanf("%d,%d",&v1,&v2);
         int i=LocateVex(G,v1);
         int j=LocateVex(G,v2);
         G.arcs[i][j].adj=1;
         //if(IncInfo) Input(*G.arcs[i][j].info);
         G.arcs[j][i]=G.arcs[i][j];//置v1,v2的对称弧
         }
        return OK;
     }

/*void Print(MGraph &G){
    for(int i=0;i<G.vexnum;i++){
        for(int j;j<G.vexnum;j++)
            printf("%4d\n",G.arcs[i][j]);
        printf("\n");
            }

    }*/

 int main(){
     printf("邻接矩阵建立一个图\n例：\n0->3->2->1\n1->3->2->0\n2->1->0\n3->1->0\n");
     MGraph G;
     CreateUDG(G);
     //Print(G);
     return 0;
     }
