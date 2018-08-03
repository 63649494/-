#include"c1.h"
typedef int ElemType;

typedef struct LNode
{
    ElemType date;
    struct LNode *next;
}LNode,*Linklist;

LNode* create(int n)
{
    LNode*p,*q,*head;
    int i;
    p=q=(LNode*)malloc(sizeof(LNode));
    //scanf("%d",&p->date);
    for(i=1;i<=n;i++)
    {
        if(i==1)head=p;
        else q->next=p;
        q=p;
        p=(LNode*)malloc(sizeof(LNode));
        scanf("%d",&p->date);
    }
    q->next=p;//之所以写这一行，是因为在最后一次建的空间虽然输入数，但要等下一次循环才能接入链表
    q=p;
    q->next=NULL;
    return head;
}

void daoshu(LNode*head)
{

   LNode*p,*r,*q;
   p=head->next;
   head->next=NULL;
   while(p!=NULL)
   {
       q=p;
       p=p->next;
       q->next=head->next;
       head->next=q;
   }
}

void print(LNode *head)
{
    LNode*p;
    p=head->next;
    if(head!=NULL)
    while(p!=NULL)
    {
        printf("%d ",p->date);
        p=p->next;
    }
}

int main()
{
    int n;
    printf("输入数的个数n：\n");
    scanf("%d",&n);
   LNode*head;
   printf("请输入n个数\n");
   head=create(n);
   daoshu(head);
   print(head);
   return 0;
}

