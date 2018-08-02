#include<stdio.h>
#include<malloc.h>
#include<math.h>


typedef int TElemType;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
    }BiTNode,*BiTree;


int CreateBiTree(BiTree &T){
    char data;
    scanf("%c",&data);
    if(data==' ') T=NULL;
    else{
        if(!(T=(BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
        T->data=data;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
        }
        return 0;
    }

int Visit(TElemType e){
    printf("%c",e);
    return 0;
    }

int InOrderTraverse(BiTree T,int (*Visit)(TElemType e)){
    if(T){
        InOrderTraverse(T->lchild,Visit);
            Visit(T->data);
                InOrderTraverse(T->rchild,Visit);
          }
    }

int main(){
    BiTree T;
    printf("创建一个二叉树：");
    CreateBiTree(T);
    printf("\n中序遍历：");
    InOrderTraverse(T,Visit);
    return 0;
    }

