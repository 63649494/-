 /* c1.h (程序名) */
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> /* malloc()等 */
 #include<limits.h> /* INT_MAX等 */
 #include<stdio.h> /* EOF(=^Z或F6),NULL */
 #include<stdlib.h> /* atoi() */
 #include<io.h> /* eof() */
 #include<math.h> /* floor(),ceil(),abs() */
 #include<process.h> /* exit() */
 /* 函数结果状态代码 */
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 /* #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 */
 typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
 typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
#define In 0
#define max 20
typedef int Elemtype;
typedef struct arcell
{
    Elemtype adj;
    char *info;
}arcell,adjm[20][20];
typedef struct
{
    Elemtype vex[max];
    adjm arcs;
    int dc,hc;//顶点数，弧数
}Graph;

Graph Createdn(Graph G)
{
    int i,j,k;printf("请输入顶点数，边（弧）数：");
    scanf("%d %d",&G.dc,&G.hc);
    for(i=0;i<G.dc;++i)G.vex[i]=i;
    for(i=0;i<G.dc;++i)
       for(j=0;j<G.dc;++j)
         {G.arcs[i][j].adj=INFINITY;G.arcs[i][j].info=NULL;}
    printf("请依次输入每条弧依附的两个顶点的下标及其权值（下标从0开始）：\n");
    for(k=0;k<G.hc;++k)
    {
        int v1,v2,w;//一条边依附的两个顶点及其权值
        scanf("%d %d %d",&v1,&v2,&w);
        G.arcs[v1][v2].adj=w;
        //Input(*G.arcs[i][j].info);
    }
    for(i=0;i<G.dc;i++)
     G.arcs[i][i].adj=0;
    return G;
}

void xuanzhi(Graph G)
{
    int d[max][max],u,v,w,i,min;
    for(v=0;v<G.dc;++v)
       for(w=0;w<G.dc;++w)
           d[v][w]=G.arcs[v][w].adj;
    for(u=0;u<G.dc;++u)
       for(v=0;v<G.dc;++v)
          for(w=0;w<G.dc;++w)
             if(d[v][u]+d[u][w]<d[v][w])
             {
                d[v][w]=d[v][u]+d[u][w];
             }
    for(v=0;v<G.dc;v++)
       for(w=1;w<G.dc;w++)
       {
           d[v][0]+=d[v][w];
       }
    min=d[0][0];
    for(v=1;v<G.dc;v++)
    {
       if(min>d[v][0])
       {
           min=d[v][0];
       }
    }
    printf("距离各村庄最近的村庄和需要的距离为：");
    for(v=0;min!=d[v][0]&&v<G.dc;v++);
    printf("%d %d\n",v,d[v][0]);
}

int main()
{
    int i,j;
    Graph G;
    G=Createdn(G);
    for(i=0;i<G.dc;i++)
    {
      printf("\n");
      for(j=0;j<G.dc;j++)
        printf("%-10d ",G.arcs[i][j].adj);
    }
    printf("\n");
    xuanzhi(G);
    return 0;

}
