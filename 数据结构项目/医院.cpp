#include<stdio.h>
#include<string.h>
#include<limits.h>
#define INFINITY 99
#define VRType int
#define InfoType int
#define VertexType int
#define Status int
#define max_n 20
#define OK 0
#define TRUE 1
#define FALSE 0

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

 int LocateVex(MGraph G,VertexType u)       //返回顶点u在图G中的位置
  {   int i;
      for(i=0;i<G.vexnum;++i)
           if(u==G.vexs[i])
              return   i;
      return   0;
 }

 Status CreateUDN(MGraph &G){
     int v1;
     int v2;
     int w;
     printf("请输入有向网的顶点数，弧数：");
     scanf("%d,%d",&G.vexnum,&G.arcnum);//IncInfo为0则各弧不含其它信息
     for(int i=0;i<G.vexnum;++i)
        {   printf("请输入第%d个顶点：",i+1);
            scanf("%d",&G.vexs[i]);}//构造顶点向量
     for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;++j)
            G.arcs[i][j].adj=INFINITY;//[adj,info]*/
     for(int k=0;k<G.arcnum;++k){
         printf("请输入第%d条边依附的两个顶点和权值：",k+1);
         scanf("%d,%d,%d",&v1,&v2,&w);
         int i=LocateVex(G,v1);
         int j=LocateVex(G,v2);
         G.arcs[i][j].adj=w;
         //if(IncInfo) Input(*G.arcs[i][j].info);
         //G.arcs[j][i]=G.arcs[i][j];//置v1,v2的对称弧
         }
        return OK;
     }


    void PrintGraph(MGraph &G)
{
    int i, j;
    int VertexNum = G.vexnum;
  /*  printf("图的顶点为:\n");
    for( i=0; i<VertexNum; i++ )
        printf("%d ", G.vexs[i]);
    printf("\n");*/

    printf("图的邻接矩阵为:\n");
    for( i=0; i<VertexNum; i++ ) {
        for( j=0; j<VertexNum; j++ )
            printf("%d ", G.arcs[i][j]);
        printf("\n");
    }
}

/***************************************************/
typedef int PathMatrix[max_n][max_n];//
typedef int ShortPathTable[max_n];

int ShortestPath_DIJ(MGraph G,int v0,PathMatrix *P,ShortPathTable *D)
{ int v,w,i,j,min;
  Status final[max_n];
  for(v=0;v<G.vexnum;++v){
    final[v]=FALSE;
    (*D)[v]=G.arcs[v0][v].adj;
    for(w=0;w<G.vexnum;++w)
      (*P)[v][w]=FALSE; //设空路径
    if((*D)[v]<INFINITY)
    {
      (*P)[v][v0]=TRUE;
      (*P)[v][v]=TRUE;
    }
  }
  (*D)[v0]=0;
  final[v0]=TRUE; //初始化,v0顶点属于S集
  //开始主循环，每次求得V0到某个顶点的最短路径，并加v到s集
  for(i=1;i<G.vexnum;++i) //其余G.vexnum-1个顶点
  {
    min=INFINITY;//当前所知离v0顶点的最近距离
    for(w=0;w<G.vexnum;++w)
      if(!final[w])//w顶点在V-S中
        if((*D)[w]<min)
        {
        v=w;
        min=(*D)[w];
        }//w顶点离v0顶点更近
    final[v]=TRUE; //离v0顶点最近的v加入S集
    for(w=0;w<G.vexnum;++w) //更新当前最短路径及距离
    {
      if(!final[w]&&min<INFINITY&&G.arcs[v][w].adj<INFINITY&&(min+G.arcs[v][w].adj<(*D)[w]))
      {//修改D[w]和P[w],w∈V-S
        (*D)[w]=min+G.arcs[v][w].adj;
        for(j=0;j<G.vexnum;++j) (*P)[w][j]=(*P)[v][j];
        (*P)[w][w]=TRUE;
      }
    }
  }
  int d=0;

   /* printf("最短路径数组p[i][j]如下:\n");
        for(int i=0;i<G.vexnum;++i)
        {
        for(int j=0;j<G.vexnum;++j)
        printf("%2d",p[i][j]);
        printf("\n");
        }*/

  /*printf("%d到各顶点的最短路径长度为：\n",G.vexs[0]);
        for(int i=1;i<G.vexnum;++i)
    printf("%d-%d:%d\n",G.vexs[0],G.vexs[i],(*D)[i]);
*/
  for(int i=1;i<G.vexnum;++i){//计算距离之和
    if((*D)[i]==INFINITY)//排除无效距离
        (*D)[i]=0;
    d=d+(*D)[i];}
    printf("此点到各点距离之和为:%d\n",d);
    return d;
}

void Hospital(MGraph &G){
    PathMatrix p;
    ShortPathTable D;
    int g[G.vexnum][G.vexnum];//邻接矩阵备份
    for(int i=0;i<G.vexnum;++i)
        for(int j=0;j<G.vexnum;++j)
            g[i][j]=G.arcs[i][j].adj;
    int V[G.vexnum];
    for(int j=0;j<G.vexnum;++j){
        for(int i=0;i<G.vexnum;++i)//邻接矩阵还原
            for(int j=0;j<G.vexnum;++j)
                G.arcs[i][j].adj=g[i][j];
        for(int i=0;i<G.vexnum;++i)//判断j列有无值
            {if(G.arcs[i][j].adj!=INFINITY)//有值则行列互换
                {int t;
                t=G.arcs[i][j].adj;
                G.arcs[i][j].adj=G.arcs[j][i].adj;
                G.arcs[j][i].adj=t;}
                }
    for(int i=0;i<G.vexnum;++i)//第j行与第0行互换
    {int t;
    t=G.arcs[0][i].adj;
    G.arcs[0][i].adj=G.arcs[j][i].adj;
    G.arcs[j][i].adj=t;}
    for(int i=0;i<G.vexnum;++i)//第j列与第0列互换
    {int t;
    t=G.arcs[i][0].adj;
    G.arcs[i][0].adj=G.arcs[i][j].adj;
    G.arcs[i][j].adj=t;}
    PrintGraph(G);
    V[j]=ShortestPath_DIJ(G,G.vexs[0],&p,&D);
    }
    int min=V[0];
    for(int i=0;i<G.vexnum;i++){//求最小路径
    if(V[i]<min)
    min=V[i];
    }
    for(int i=0;i<G.vexnum;i++){//求最小路径的下标
    if(V[i]==min)
    printf("医院建在编号为%d的城即为最优解",i+1);
    }
}


 int main(){
     printf("邻接矩阵建立一个图\n例：6,9;1,2,6;1,3,3;2,3,4;2,4,5;3,4,3;4,5,2;3,5,4;4,6,3;5,6,5 \n");
     MGraph G;
     CreateUDN(G);
     //PrintGraph(G);
     Hospital(G);
     return 0;
     }


