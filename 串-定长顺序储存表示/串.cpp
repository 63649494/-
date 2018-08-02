#include"c1.h"
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];

Status Concat(SString &T,SString S1,SString S2){
    int uncut;
    int i;
    if(S1[0]+S2[0]==MAXSTRLEN){  //未截断
        for(i=1;i<=S1[0];i++)
        T[i]=S1[i];
        //T[1..S1[0]]=S1[1..S1[0]]
        for(i=1;i<=S2[0];i++)
        T[S1[0]+i]=S1[i];
        T[0]=S1[0]+S2[0];
        uncut=TRUE;
        }
    else if(S1[0]<MAXSTRLEN){   //截断
        for(i=1;i<=S1[0];i++)
        T[i]=S1[i];
        //T[1..S1[0]]=S1[1..S1[0]]
        for(i=S1[0]+1;i<=MAXSTRLEN;i++)
        T[i]=S2[i-S1[0]];
        //T[S1[0]+1..MAXSTRLEN]=S1[1..MAXSTRLEN-S1[0]]
        uncut=FALSE;
        }
    else{
        for(i=0;i<=MAXSTRLEN;i++)
        T[i]=S1[i];
        //T[0..MAXSTRLEN]=S1[0..MAXSTRLEN]
        uncut=FALSE;
        }
    return uncut;
    }


int main()
    {
    return 0;
    }
