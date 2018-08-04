#include <stdio.h>
#include<stdlib.h>
#include<string>
#include <iostream>

#define MAXBIT  30
#define MAXdata    1000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1 //结点是叶子数的2倍减一

typedef struct
{
    int bit[MAXBIT];//编码数组
    int s;//霍夫曼的层数
} HCodeType;//编码结构

typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
    int data;
} HNodeType;//结点结构

//创建霍夫曼树
void HuffmanTree (HNodeType HuffNode[MAXNODE],int n)
{
    int i,j,d1,d2,x1,x2;

    for (i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent =-1;//用于判断是否有双亲
        HuffNode[i].lchild =-1;//用于判断是否有左孩子
        HuffNode[i].rchild =-1;//用于判断是否有右孩子
        HuffNode[i].data=' ';
    }//初始化结点

    for (i=0; i<n; i++)
    {
        printf ("请输入字母的编号(如A=1,B=2....Z=26),以及它的权值: ");
        scanf ("%d,%d",&HuffNode[i].data,&HuffNode[i].weight);
        getchar();
        int A=HuffNode[i].data;
        printf ("字母的编号为%d的权值为%d\n",A,HuffNode[i].weight);
    }

    //编码开始
    for (i=0; i<n-1; i++)//第一次处理两个，之后两两处理，i<n-1；
    {
        d1=d2=MAXdata;
        x1=x2=0;//初始化编码

        //找出最小两个的权值以及其对应的字母编号
        for (j=0; j<n+i; j++)//每次循环多一个结点，j<n+i
        {
            if (HuffNode[j].weight<d1&&HuffNode[j].parent==-1)
            {
                d2=d1;
                x2=x1;
                d1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight<d2&&HuffNode[j].parent==-1)
            {
                d2=HuffNode[j].weight;
                x2=j;
            }
        }
        //设置找到的两个最小子结点x1，x2的双亲结点信息
        HuffNode[x1].parent=n+i;
        HuffNode[x2].parent=n+i;
        HuffNode[n+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;//双亲权值为孩子权值之和
        HuffNode[n+i].lchild=x1;
        HuffNode[n+i].rchild=x2;

        printf ("第%d个双亲结点的权值为%d,其左孩子和右孩子的结点的权值为%d: %d, %d\n",i+1,HuffNode[n+i].weight,HuffNode[x1].weight,HuffNode[x2].weight);
    }
}

//编码
void Codeing(HNodeType HuffNode[],int n){
    HCodeType HuffCode[MAXLEAF],cd;       //cd用来临时存放编码
    int i,j,c,p;
    HuffmanTree(HuffNode,n);
    for (i=0;i<n;i++)
    {
        cd.s=n-1;
        c=i;
        p=HuffNode[c].parent;
        while(p!=-1)//判断双亲结点是否存在
        {
            if(HuffNode[p].lchild==c)//c是否为p的左孩子，是为0，否为1
            cd.bit[cd.s]=0;
            else
                cd.bit[cd.s]=1;
            cd.s--; //层数上升
            c=p;
            p=HuffNode[c].parent;//c的双亲
        }

        //保存求出的每个叶结点的哈夫曼编码和编码的起始位
        for (j=cd.s+1; j<n; j++)
        {HuffCode[i].bit[j] = cd.bit[j];}
        HuffCode[i].s = cd.s;
    }

    //输出哈夫曼编码
    for (i=0; i<n; i++)
    {
        printf ("编号为%d的赫夫曼编码为:\n", i+1);
        for (j=HuffCode[i].s+1;j<n;j++)
        {
            printf("%d\n",HuffCode[i].bit[j]);
        }
        printf("在霍夫曼树中的层数为:%d\n",n-1-HuffCode[i].s);
    }
    }


//解码
void Decodeing(HNodeType Dec[],int Num)
{   char bit[1000];
    int i,t=0;
    int m=2*Num-1;//节点数
    char *num1;
    char num[1000];

    printf("请输入编码进行解码:\n");
    scanf("%s",&bit);

    for(i=0;i<strlen(bit);i++)
    {
        if(bit[i]=='0')
            num[i]=0;
        else
            num[i]=1;
    }
    i=0;
    num1=&num[0];
    while(num1<(&num[strlen(bit)]))//nump小于编码长度
    {t=m-1;//字母的编号，每次循环重回树顶
    while((Dec[t].lchild!=-1)&&(Dec[t].rchild!=-1))//直到没有左右孩子停止
    {
        if(*num1==0)
        {
            t=Dec[t].lchild ;
        }
        else t=Dec[t].rchild;
        num1++;//
    }
    printf("%d ",Dec[t].data);
    }
}


int main(void)
{
    int n;
    printf("请输入文档包含的字母种类个数:\n");
    scanf("%d",&n);
    HNodeType HuffNode[MAXNODE];
    Codeing(HuffNode,n);
    Decodeing(HuffNode,n);
    getchar();
    return 0;
}
