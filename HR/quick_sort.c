#include <stdio.h>
#define MAX_N 10000

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort(int A[], int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = A[end];
    int l = start, r = end;
    while (l < r) {
        if (A[l] <= pivot) l++;
        else if (A[r] > pivot) r--;
        else {
            swap(A + l, A + r);
        }
    }
    quickSort(A, start, l - 1);
    quickSort(A, l, end);
}

int main() {
	int T, N, A[MAX_N], i;
	scanf("%d", &T);
	while (T--) {
	    scanf("%d", &N);
	    for (i = 0; i < N; i++) {
	        scanf("%d", A + i);
	    }
	    quickSort(A, 0, N - 1);
        printf("%d", A[0]);
        for (i = 1; i < N; i++) {
            printf(" %d", A[i]);
        }
        printf("\n");
	}
	return 0;
}
