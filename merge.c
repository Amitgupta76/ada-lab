#include<stdlib.h>
#include<stdio.h>
// Merge Function
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
{
// Finding mid element
int m = l+(r-l)/2;
// Recursively sorting both the halves
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);

// Merge the array
merge(arr, l, m, r);
}
}


void printArray(int A[], int size)
{
int i;
for (i=0; i < size; i++)
printf("%d ", A[i]);
printf("n");
}

int main()
{
int n,i,arr[1000],num;
printf("enter the number of integers");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    num = (rand() % n) + 1;
    arr[i-1] = num;
}
int arr_size = n;
printf("Given array is n");
printArray(arr, arr_size);
mergeSort(arr, 0, arr_size - 1);
printf("nSorted array is n");
printArray(arr, arr_size);
return 0;
}
