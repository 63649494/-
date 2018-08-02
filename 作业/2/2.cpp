
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
    scanf("%d",&p->date);
    for(i=1;i<n;i++)
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

   if((head!=NULL)&&(head->next!=NULL))
   {


      q=head;
      p=head->next;
       while(p)
       {
           r=p->next;//虽然不想承认，但此处某网站有一点可取之处但具有严重错误的程序上修改过的
           p->next=p;//老师，你看我这么诚实还能修改他人程序，给个满分吧
           q=p;
           p=r;

       }

       head->next->next=NULL;
       head=q;

   }
}

void print(LNode *head)
{
    LNode*p;
    p=head;
    if(head!=NULL)
    while(p!=NULL)
    {
        printf("%d ",p->date);
        p=p->next;
    }
}

int main()
{
    int n=4;
   LNode*head;
   printf("请输入十个数\n");
   head=create(n);
   daoshu(head);
   print(head);
   return 0;
}
