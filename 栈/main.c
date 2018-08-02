#include "c1.h"
/* c3-1.h 栈的顺序存储表示 */
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
  typedef int SElemType;
 typedef struct SqStack
 {
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */

 Status InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!(*S).base)
     exit(OVERFLOW); /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return OK;
 }
 Status StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }
 Status Push(SqStack *S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!(*S).base)
       exit(OVERFLOW); /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return OK;
 }

 Status Pop(SqStack *S,SElemType *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if((*S).top==(*S).base)
     return ERROR;
   *e=*--(*S).top;
   return OK;
 }
void conversion()
 {
    SqStack s;
    SElemType n,e;
    if(InitStack(&s)==ERROR)
    {
        printf("初始化失败");
        exit(OVERFLOW);
     }
     printf("请输入要转换的数：");
    scanf("%d",&n);
    while (n!=0)
    {
        Push(&s,n%8);
        n=n/8;

    }
    while(!StackEmpty(s)) {
       Pop(&s,&e);
       printf("%d",e);
    }

 }

int main()
{
    conversion();
    return 0;
}
