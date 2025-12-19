#include<stdio.h>
#include<math.h>
#include<limits.h>

typedef struct {
    int index;
    int s;
    int f;
} Act;

void MERGE(Act A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    Act L[n1 + 1], R[n2 + 1];
    
    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];
    L[n1].f = INT_MAX;
    R[n2].f = INT_MAX;
    
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i].f <= R[j].f) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MERGE_SORT(Act A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

void Greedy(Act A[], int n) {
    printf("Activities are selected n: ");
    
    int i = 0;
    printf("%d ", A[i].index + 1);
    for (int m = 1; m < n; m++) {
        if (A[m].s >= A[i].f) {
            printf("%d ", A[m].index + 1);
            i = m;
        }
    }
    printf("\n");
}

//1.1 Time Complexity = O(n log n)


int main() {
    int n;
    int s, f;

    printf("Input number of Activity (n) = ");
    scanf("%d", &n);
    Act act[n];

    for (int i = 0; i < n; i++) {
        printf("Input Enter S and F of Activity %d = ", i + 1);
        scanf("%d %d", &s, &f);
        act[i].s = s;
        act[i].f = f;
        act[i].index = i;
    }

    MERGE_SORT(act, 0, n - 1); 

    Greedy(act, n);

    return 0;
}
