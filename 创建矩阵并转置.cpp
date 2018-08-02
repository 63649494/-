#include<stdio.h>
#define MAXSIZE 12500

typedef int ElemType;

typedef struct{
    int i,j;        //i行j列
    ElemType e;     //e元素
    }Triple;

typedef struct{
    Triple data[MAXSIZE+1];
    int mu,nu,tu;//行数列数非零元个数
    }TSMatrix;

int CreateTSMatrix(TSMatrix *M)
//创建稀疏矩阵
{
    int i,m,n;
    ElemType e;
    printf("请输入矩阵的行、列、非零元个数(以,相隔)：");
    scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
    for(i=1;i<=(*M).tu;i++)
    {
        printf("请按行序顺序输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值(以,相隔)：",i,(*M).mu,(*M).nu);
        scanf("%d,%d,%d",&m,&n,&e);
        (*M).data[i].i=m;
        (*M).data[i].j=n;
        (*M).data[i].e=e;
    }
    return 0;
}//创建操作借鉴于http://blog.csdn.net/cytchan/article/details/50688002

void PrintTSMatrix(TSMatrix M)
//打印稀疏矩阵
{
    int i;
    printf("%d行%d列%d个非零元素。\n",M.mu,M.nu,M.tu);
    printf("行  列  元素值\n");
    for(i=1;i<=M.tu;i++)
        printf("%2d%4d%5d\n",M.data[i].i,M.data[i].j,M.data[i].e);
 }

int TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu=M.nu;  T.nu=M.mu;  T.tu=M.tu;
    if(T.tu){
        int q=1;
        for(int col=1;col<=M.nu;++col)
            for(int p=1;p<=M.tu;++p)
                if(M.data[p].j==col){
                    T.data[q].i=M.data[p].j; T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;    ++q;
                    }
        }
        return 0;
    }

/*Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    if(T.tu){
        for(int col=1;col<=M.nu;++col)
            for(int row=1;row<=M.mu;++row)
                T[col][row]=M[row][col];
        }
        return OK;
}*/

int main()
{
    //Triple
    //TSMatrix *M;//M->*M
    TSMatrix M;
    //CreateTSMatrix(M);
    CreateTSMatrix(&M);
    PrintTSMatrix(M);
    TSMatrix T;
    TransposeSMatrix(M,T);
    PrintTSMatrix(T);
    return 0;
}

