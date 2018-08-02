#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<string.h>

#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef char SqBiTree[MAX_TREE_SIZE];


typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
    }BiTNode,*BiTree;


BiTNode *CreateBiTree(SqBiTree M, int i, int Strsize){
    char ch;
    BiTNode *t;
    ch=M[i-1];
    if(ch=='#'||ch=='\n'||i>=Strsize)
    return NULL;
    else{
        t=(BiTNode*)malloc(sizeof(BiTNode));
        t->data=ch;
        t->lchild=CreateBiTree(M,2*i,Strsize);//由二叉树性质5得，左孩子的节点编号为根节点根的两倍
        t->rchild=CreateBiTree(M,2*i+1,Strsize);//由二叉树性质5得，右孩子的节点编号为根节点根的两倍加1
 }
 return t;
}

BiTNode* CreateNode(char* data){
    BiTNode* temp=(BiTNode*)malloc(sizeof(BiTNode));
    temp->data=*data;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
    }//创建节点

typedef struct{
    BiTNode *base;
    BiTNode *top;
    int stacksize;
    }Stack;//节点栈

BiTNode *CreateBiTreeWithoutRecur(SqBiTree str){
    BiTNode* Stack[MAX_TREE_SIZE];
    int top=0;
    BiTNode* root=NULL;
    BiTNode* temproot=NULL;
    BiTNode* temp=NULL;
    root=CreateNode(str);//创建第一个节点
    temproot=root;
    while(*str!='\0'){
        str++;//下一个字符
        if(*(str-1)!='#'){//判断当前字符不为空
            Stack[top++]=temproot;//当前节点进栈
            if(*str!='#'){//判断下一个字符是否为空
                temp=CreateNode(str);//创建下一个节点
                temproot->lchild=temp;//下一个节点作为当前节点的左孩子
                temproot=temp;//左孩子成为当前节点
                }
            else temproot->lchild=NULL;
            }
        if(*(str-1)=='#'&&top>0){//当前节点为空（要判断栈是否为空！）
            temproot=Stack[--top];//当前节点退栈，回到上一个节点
            if(*str!='#'){//判断下一个字符是否为空
                temp=CreateNode(str);
                temproot->rchild=temp;//下一个节点作为当前节点的右孩子
                temproot=temp;
                }
            else temproot->rchild=NULL;
            }
        }
    return root;
}//非递归创建二叉树

int Visit(TElemType e){
    printf("%c",e);
    return 0;
    }

int PreOrderTraverse(BiTree T,int (*Visit)(TElemType e)){
    if(T){
        Visit(T->data);
            PreOrderTraverse(T->lchild,Visit);
                PreOrderTraverse(T->rchild,Visit);
          }
    }

int main(){
    SqBiTree M;
    BiTree T;
    printf("前序创建一个二叉树（例：ABC##DE#G##F###）：");
    scanf("%s",M);
    printf("非递归创建：");
    T=CreateBiTreeWithoutRecur(M);
    //T=CreateBiTree(M, 1,strlen(M));
    printf("前序遍历：");
    PreOrderTraverse(T,Visit);
    printf("\n");
    printf("递归创建：");
    T=CreateBiTree(M,1,strlen(M));
    printf("前序遍历：");
    PreOrderTraverse(T,Visit);
    printf("\n");

    return 0;
    }

//ABC##DE#G##F###
