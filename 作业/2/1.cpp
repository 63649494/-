#include"c1.h"
#include<stdio.h>

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

void CreateList_L(LinkList &L,int n){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
	LNode *p,*q;
	q=L;
    for(int i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        p->next=q->next;
        q->next=p;
        p=q;
        //p->next=L->next;L->next=p;
    }
}

/*void reverse(LinkList &L)
{
    LinkList p=L->next;
    L->next=NULL;
    while(p)
    {
        LinkList s=p;
        p=p->next;

        s->next=L->next;
        L->next=s;
        }
    }*/

void reverse(LinkList &head)
{
    if (head == NULL || head->next==NULL)  //空或者只有一个元素不用逆置
       return ;
    LinkList p, q, r;
    p = head;
    q = p->next;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    //以下两步，很重要
    head->next = NULL;   //这一步会使新的尾节点的链域置空
    head = p;
     //head指针指向新的一头
}

void print(LNode* head)
{
    LNode *p=head->next;//要加->next
    printf("\n输出链表数据\n");
    if(head!=NULL)
    do
    {
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=NULL);
    else
		printf("此链表为空!");

}

int main(){
    LinkList L;
    int n=3;
    CreateList_L(L,n);
    print(L);
	reverse(L);
	print(L);
	return 0;
}
