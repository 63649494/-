#include<malloc.h>
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

void reverse(LNode *head){
	LNode *p,*q;
	p=head->next;
	head->next=NULL;
	while(p!=NULL){
	q=p;
	p=p->next;
	q->next=head->next;
	head->next=q;
	}

}


void print(LNode* head)
{
    LNode *p=head->next;
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
