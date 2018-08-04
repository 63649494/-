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
#define List 100
#define Last 10
typedef int Elemtype;
typedef struct
{
    Elemtype *elem;
    int length;
    int listsize;
}Sqlist;

Sqlist jia(Sqlist a,Sqlist b,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {

        if((a.elem[i]+b.elem[i])/10>0)b.elem[i+1]+=(a.elem[i]+b.elem[i])/10;
        b.elem[i]=(a.elem[i]+b.elem[i])%10;
    }
    if(b.elem[n-1]!=0)
    b.length=n;
    return b;
}

Sqlist jian(Sqlist a,Sqlist b,int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {

          if(i<b.length)
          {
             if(a.elem[i]<b.elem[i])
             {
                b.elem[i]=a.elem[i]+10-b.elem[i];
                if(a.elem[i+1]==0)a.elem[i+1]=10;
                a.elem[i+1]=a.elem[i+1]-1;
             }
             else b.elem[i]=a.elem[i]-b.elem[i];
          }
         else if(i<a.length)b.elem[i]=a.elem[i];
    }
    for(i=n-2;i>=0&&b.elem[i]==0;i--);
    b.length=i+1;
    return b;
}

void cheng()
{
    /*int i,j,k;Sqlist c[n];
    for(i=0;i<n;i++)
    {
        c[i].elem=(Elemtype*)malloc(n*sizeof(Elemtype));
        c[i].length=n;
        for(j=0;j<n;j++)c[i].elem[j]=0;
    }

    for(i=0;i<a.length;i++)
    {
        for(j=0;j<b.length;j++)
        {
            if(c[i].elem[j]/10>0)c[i].elem[j+1]+=c[i].elem[j]/10;
           if((a.elem[i]*b.elem[j])/10>0)
           c[i].elem[j+1]+=(a.elem[i]*b.elem[j])/10;
           c[i].elem[j]+=(a.elem[i]*b.elem[j])%10;
        }
    }
    if(c[i-1].elem[j]!=0)b.length++;
     k=b.length+i-1;
    for(j=n;j>=0&&c[i].elem[j]==0;j--);
    c[i].length=j+1;
     b.elem=(Elemtype*)realloc(b.elem,k*sizeof(Elemtype));
     for(i=0;i<k;i++)b.elem[i]=0;
     for(i=0;i<a.length;i+2)
     {
         for(j=0;j<k;j++)
            if(j-i>=0&&j<=c[i].length)
            {
               if((c[i].elem[j-i]+c[i+1].elem[j-i-1])/10>0)b.elem[j+1]+=(c[i].elem[j-i]+c[i+1].elem[j-i-1])/10;
                      b.elem[j]+=(c[i].elem[j-i]+c[i+1].elem[j-i-i])%10;
            }
                 else if(j>c[i].length)b.elem[j]=c[i+1].elem[j-i-1];
                 else if(j-i<0) b.elem[j]=c[i].elem[j-i];

     }
     if(b.elem[k]!=0)k++;
     b.length=k;
     return b;*/

  int i,j,t,n,temp;
  char mult1[List];
  char mult2[List];
  printf("输入两个数:\n");
  scanf("%s %s",mult1,mult2);
  int len1 = strlen(mult1);
  int len2 = strlen(mult2);
  int *c1 = (int *)malloc(sizeof(int)*len1);
  int *c2 = (int *)malloc(sizeof(int)*len2);
  for(i=0; i<len1; i++)
      c1[i]=(int)mult1[i]-48;
  for(i=0; i<len2; i++)
      c2[i]=(int)mult2[i]-48;
  int *result = (int *)malloc(sizeof(int)*(len1+len2));
  n=len1+len2-1;
  for(i=0; i<=n; i++)
      result[i]=0;
  temp=0;
  for(i=len2-1; i>-1; i--)
     {
      t=c2[i];
      for(j=len1-1; j>-1 ;j--)
          {
            if((temp=result[n]+t*c1[j])>=10)
               {
                 result[n]=(temp%10);
                 result[n-1]+=temp/10;
               }
            else
            result[n]=temp;
            n--;
          }
            n=n+len1-1;
    }
  if(result[0]!=0)
  printf("%d",result[0]);
  for(i=1;i<=len1+len2-1;i++)
  printf("%d",result[i]);
  printf("\n");//太惭愧了http://blog.sina.com.cn/hexw100
}

int SubStract( int *p1, int *p2, int len1, int len2 )
{
    int i;
    if( len1 < len2 )
        return -1;
    if( len1 == len2 )
    {                        //判断p1 > p2
        for( i=len1-1; i>=0; i-- )
        {
            if( p1[i] > p2[i] )   //若大，则满足条件，可做减法
                break;
            else if( p1[i] < p2[i] ) //否则返回-1
                return -1;
        }
    }
    for( i=0; i<=len1-1; i++ )  //从低位开始做减法
    {
        p1[i] -= p2[i];
        if( p1[i] < 0 )          //若p1<0，则需要借位
        {
            p1[i] += 10;         //借1当10
            p1[i+1]--;           //高位减1
        }
    }
    for( i=len1-1; i>=0; i-- )       //查找结果的最高位
        if( p1[i] )                  //最高位第一个不为0
            return (i+1);       //得到位数并返回
    return 0;                   //两数相等的时候返回0
}
void chu()
{
    int k, i, j;
    int len1, len2;             //大数位数
    int nTimes;                 //两大数相差位数
    int nTemp;                  //Subtract函数返回值
    int num_a[List];          //被除数
    int num_b[List];          //除数
    int num_c[List];          //商
    char str1[List + 1];      //读入的第一个大数
    char str2[List + 1];      //读入的第二个大数
    printf("输入相除的两个数：\n");
        scanf("%s", str1);        //以字符串形式读入大数
        scanf("%s", str2);

        for ( i=0; i<List; i++ )   //初始化清零操作
        {
            num_a[i] = 0;
            num_b[i] = 0;
            num_c[i] = 0;
        }

        len1 = strlen(str1);  //获得大数的位数
        len2 = strlen(str2);

        for( j=0, i=len1-1; i>=0; j++, i-- )
            num_a[j] = str1[i] - '0';  //将字符串转换成对应的整数,颠倒存储
        for( j=0, i=len2-1; i>=0; j++, i-- )
            num_b[j] = str2[i] - '0';
        nTimes = len1 - len2;    //相差位数
        for ( i=len1-1; i>=0; i-- )    //将除数扩大，使得除数和被除数位数相等
        {
            if ( i>=nTimes )
                num_b[i] = num_b[i-nTimes];
            else                     //低位置0
                num_b[i] = 0;
        }
        len2 = len1;
        for( j=0; j<=nTimes; j++ )      //重复调用，同时记录减成功的次数，即为商
        {
            while((nTemp = SubStract(num_a,num_b + j,len1,len2 - j)) >= 0)
            {
                len1 = nTemp;      //结果长度
                num_c[nTimes-j]++;//每成功减一次，将商的相应位加1
            }
        }

        printf("商为：");
        for( i=List-1; num_c[i]==0 && i>=0; i-- );//跳过高位0
        if( i>=0 )
            for( ; i>=0; i-- )
                printf("%d", num_c[i]);
        else
            printf("0");
        printf("\n");

}//感觉我太废了，这么个程序除了加法减法是自己的思想，乘法除法却要抄网上的大数,高精度计算---大数除法 - javawebsoa - 博客园
void print(Sqlist b)
{
    int i;
    for(i=b.length;i>=0;i--)
     printf("%d",b.elem[i]);
}



Sqlist suan()
{
   int i,n,m;
   Sqlist a,b;
   printf("请输入将要计算的两数(减法时第一个数要大于等于第二个数)的长度：");
   scanf("%d %d",&a.length,&b.length);
   n=a.length>b.length? a.length:b.length;
   n=n+1;
   a.elem=(Elemtype*)malloc(n*sizeof(Elemtype));
   b.elem=(Elemtype*)malloc(n*sizeof(Elemtype));
   for(i=0;i<n;i++)
   {
       b.elem[i]=a.elem[i]=0;
   }
   printf("从低位到高位输入第一个数，位与位之间用空格：");
   for(i=0;i<a.length;i++)
   {
       scanf("%d",&a.elem[i]);
   }
   printf("从低位到高位输入第二个数，位与位之间用空格：");
   for(i=0;i<b.length;i++)
   {
       scanf("%d",&b.elem[i]);
   }
   printf("输入1,2代表加，减：");
   scanf("%d",&m);
   switch(m)
   {
       case 1:{b=jia(a,b,n);print(b);}break;
       case 2:{b=jian(a,b,n);print(b);}break;
       default:break;
   }
   return b;
}



int main()
{
   Sqlist b;
   int a;
   printf("输入1，2,3代表算加减或算乘或算除:");
   scanf("%d",&a);
   switch(a)
   {
     case 1:b=suan();break;
     case 2:cheng();break;
     case 3:chu();break;
   }
   printf("\n");
   return 0;
}
