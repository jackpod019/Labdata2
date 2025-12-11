#include<stdio.h>
#include<math.h>
#include<limits.h>
void MERGE(int A[],int p,int q,int r,int c)
{
int n1 =q-p+1;
int n2=r-q;
int L[n1+1],R[n2+1];
int i,j;
for(i=1;i<=n1;i++){
    L[i]=A[p+i-1];
}
for(j   =1;j<=n2;j++){
    R[j]=A[q+j];
}
L[n1+1]=INT_MAX;
R[n2+1]=INT_MAX;
int k=p;
i=1;
j=1;
while(k<=r){
    if(L[i]<=R[j]){
        A[k]=L[i];
        i=i+1;
    }else{
        A[k]=R[j];
        j=j+1;
    }
    k++;
}


for(i=0;i<8;i++){
    printf("%d ",A[i]);
}
printf("\n");
printf("Rec : %d = ",c);
c--;
}
void MERGE_SORT(int A[],int p ,int r,int c)
{
    if(p<r){
        c++;
        int q=floor((p+r)/2);
        MERGE_SORT(A,p,q,c);
        MERGE_SORT(A,q+1,r,c);
        MERGE(A,p,q,r,c);

    }
}
int main()
{
    int A[] = {27,5,2,7,9,3,2,10};
    int p=0;
    int q;
    int r = (sizeof(A)/sizeof(A[0])) - 1;
    int c=0;
    printf("Given array is: ");
    for(int i=0;i<r;i++){
        printf("%d ",A[i]);
    }
    MERGE_SORT(A,p,r,c);
    for(int i=0;i<=r;i++){
        printf("%d ",A[i]);
    }
}
