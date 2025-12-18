#include<stdio.h>
#include<math.h>
#include<limits.h>

typedef struct {
    int index ;
    int s;
    int f;
}Act;

void MERGE(Act A[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    Act L[n1+1], R[n2+1];
    int i, j;
    //copy
    for(i=1; i<=n1; i++){
        L[i] = A[p+i-1];
    }
    for(j=1; j<=n2; j++){
        R[j] = A[q+j];
    }
    L[n1+1].f = INT_MAX;
    R[n2+1].f = INT_MAX;

    int k = p;
    i = 1;
    j = 1;
    while(k<=r){
        if(L[i].f <= R[j].f){
            A[k] = L[i];
            i = i+1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
        k++;
    }
}

void MERGE_SORT(Act A[],int p ,int r)
{
    if(p<r){
        int q = floor((p+r)/2);
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE(A, p, q, r);
    }
}

void Greedy(Act A[],int n){
    int j=0;
    int index[n];
    int c=1;
    index[0] = A[0].index+1;
    for(int i=0;i<n;i++){
        if(A[i].s>=A[j].f){
            j=i;
            index[c] = A[i].index+1;
            c++;
            }

    }
        printf("Activities are selected n : ");
        for(int k=0;k<c;k++){
            printf(" %d",index[k]);
    }

}
int main(){
    int n;
    int i,j;
    int s,f;
    int p = 0;

    printf("Input number of Activity (n) = ");
    scanf("%d",&n);
    Act act[n];
    for(i=0;i<n;i++){

        printf("Input Enter S and F of Activity %d = ",i+1);
        scanf("%d %d",&s,&f);
        act[i].s = s;
        act[i].f = f;
        act[i].index = i;

    }
    MERGE_SORT(act, p, n);
    for(i=0;i<n;i++){
    }

    Greedy(act,n);


}

