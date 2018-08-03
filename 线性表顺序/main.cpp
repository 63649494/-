#include "c1.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct SqList{
    ElemType *elem; //首地址
    int length;
    int listsize;
    }SqList; //定义线性表

Status InitList_Sq(SqList *L){//*L写出了L
    (*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));//第一个ElemType没加 *
    if(!(*L).elem) exit(OVERFLOW);
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    return OK;
    }//构造空表

Status ListInsert_Sq(SqList *L,int i,ElemType e){
    ElemType *newbase,*q,*p;//一开始没定义
    if(i<1||i>(*L).length+1) return ERROR;
    if((*L).length>=(*L).listsize){
        newbase = (ElemType *)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);
        (*L).elem=newbase;
        (*L).listsize+=LISTINCREMENT;
        }
    q=&((*L).elem[i-1]);
    for(p=&((*L).elem[i-1]);p>=q;--p) *(p+1)=*p;//元素右移
    *q=e;
    ++(*L).length;
    return  OK;
    }//在第i个位置之前插入元素e

Status ListDelete_Sq(SqList *L,int i,ElemType e){//一开始是*e出错，换成e就好了
    ElemType *q,*p;//不需要定义e
    if(i<1||i>(*L).length+1) return ERROR;
    p=&((*L).elem[i-1]);
    e=*p;//e一开始没加*
    q=(*L).elem+(*L).length-1;
    for(++p;p<=q;++p) *(p-1)=*p;//左移动
    --(*L).length;
    printf("%d",e);
    return OK;
    }//删除在第i个位置的元素用e返回

int compare(ElemType e1, ElemType e2)//得单独编
{
  if (e1 == e2) return 0;
  else return 1;
}


Status LocateElem_Sq(SqList *L,ElemType e,int (*compare)(ElemType,ElemType)){
    ElemType i,*q,*p;
    i=1;
    p=(*L).elem;
    while(i<=(*L).length&&!(*compare)(*p++,e)) ++i;
    if(i<=(*L).length) return i;
    else return 0;
    }//比较

void MergeList_Sq(SqList *La,SqList *Lb,SqList *Lc){
    ElemType *pa,*pb,*pa_last,*pb_last,*pc;
    pa = (*La).elem; pb = (*Lb).elem;
    (*Lc).listsize = (*Lc).listsize + (*Lc).listsize;
    pc=(*Lc).elem=(ElemType *)malloc((*Lc).listsize*sizeof(ElemType));//pc要在之前定义成*pc，注意*
    if(!(*Lc).elem) exit(OVERFLOW);
    pa_last = (*La).elem+(*La).listsize-1;
    pb_last = (*Lb).elem+(*Lb).listsize-1;
    while(pa<=pa_last&&pb<=pb_last){
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
        }
    while(pa<=pa_last) *pc++=*pa++;
    while(pb<=pb_last) *pc++=*pb++;
    }//合并排列两个线性表

int main()
{
    SqList L;
    InitList_Sq(&L);//一开始写的* 改为了&
    ListInsert_Sq(&L,1,1);
    ListInsert_Sq(&L,2,2);
    int e,i;
    scanf("%d",&i);
    ListDelete_Sq(&L,i,e);
    LocateElem_Sq(&L,1,(*compare));//compare后面不用加东西
    SqList La,Lb,Lc;
    InitList_Sq(&La);//一开始写的* 改为了&
    InitList_Sq(&Lb);
    InitList_Sq(&Lc);
    ListInsert_Sq(&La,1,3);
    ListInsert_Sq(&Lb,1,2);
    MergeList_Sq(&La,&Lb,&Lc);
    return 0;
}

