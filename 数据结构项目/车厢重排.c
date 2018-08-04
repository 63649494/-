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
#define List 20
#define Last 10
typedef int Elemtype;


void chongpai()
{
   int i,j,n,k,l,a[List],b[List];
   Elemtype hc[List][List];int front[List]={0},rear[List]={0};//数组模拟队列，头指针指向头元素，尾指针指向尾元素的下一个位置
   printf("输入火车车厢数:");
   scanf("%d",&n);
   printf("输出车厢的初始顺序(从1开始，如：3 4 5 6 7...)：\n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       b[i]=0;
   }
   for(i=0;i<List;i++)
     for(j=0;j<List;j++)
        hc[i][j]=0;
   for(i=0;i<n;i++)
     {
         for(k=0;k<n;k++)
            if((rear[k]!=front[k]&&hc[k][rear[k]-1]<a[i])||rear[k]==front[k]){hc[k][rear[k]]=a[i];rear[k]++;break;}
         for(j=1;b[j-1]!=0;j++);
         for(;j<=n;j++)
         {
             for(k=0;k<n&&hc[k][front[k]]!=j;k++);
                 if(k==n)break;
             for(k=0;k<n;k++)
              {
                if(rear[k]!=front[k]&&hc[k][front[k]]==j){b[j-1]=hc[k][front[k]];front[k]++;break;}
              }
         }


     }
    printf("输出重排后的火车车厢次序：");
    for(i=0;i<n;i++)
       printf("%d ",b[i]);
}

int main()
{
    chongpai();
    return 0;
}
