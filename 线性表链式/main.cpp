#include "c1.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
    }LNode,*LinkList;

Status GetElem_L(LinkList L,int i,ElemType &e){
    LNode *p;//一开始用的elemtype，p=L->next是个链表类型的指针
    int j;
    p=L->next;j=1;
    while(p&&j<i){
        p=p->next;++j;
        }
    if(!p||j>i)return ERROR;
    e=p->data;
    return OK;
    }//取得元素

Status ListInsert_L(LinkList &L,)

int main()
{

    return 0;
}

