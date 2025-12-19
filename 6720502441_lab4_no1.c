#include <stdio.h>

typedef struct {
    int id;
    float w;
    float v;
    float r;
} Item;

void sort(Item A[], int n) {
    Item tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j].r < A[j + 1].r) {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
    }
}

void solve(Item A[], int n, float W) {
    float sumW = 0.0;
    float totalVal = 0.0;
    float x[10] = {0};

    for (int i = 0; i < n; i++) {
        if (sumW < W) {
            if (sumW + A[i].w <= W) {
                x[A[i].id] = 1.0; 
                sumW += A[i].w;
                totalVal += A[i].v;
            } else {
                float remain = W - sumW;
                float frac = remain / A[i].w; 
                x[A[i].id] = frac;         
                sumW += (frac * A[i].w);
                totalVal += (frac * A[i].v);
                break; 
            }
        }
    }

    printf("The results of xi is:");
    for (int i = 0; i < n; i++) printf(" %.2f", x[i]);
    
    printf("\nMaximum value is: %.2f\n", totalVal);
}

/* 2.1 Time Complexity: O(n log n)*/

int main() {
    int n = 4;
    float W = 6.0;
    
    Item items[4] = {
        {0, 1.0, 5.0, 0.0}, 
        {1, 2.0, 4.0, 0.0}, 
        {2, 4.0, 8.0, 0.0}, 
        {3, 5.0, 6.0, 0.0}  
    };

    for(int i=0; i<n; i++) {
        items[i].r = items[i].v / items[i].w;
    }

    sort(items, n);
    solve(items, n, W);

    return 0;
}
