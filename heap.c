#include<stdio.h>
#include<time.h>
void delay()
{
    int k;
for(k=0;k<5000000;k++)
{}
}

void swap(int* a, int* b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {

        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    delay();
    int i;
    for (i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);
    for (i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int n,i,arr[1000],num;
    clock_t start,end;
printf("enter the number of integers");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    num = (rand() % n) + 1;
    arr[i-1] = num;
}
    for(i=0;i<n;i++)
   printf(" %d",arr[i]);
    start=clock();
    heapSort(arr, n);
    end=clock();
    printf("Sorted array is\n");
    printArray(arr, n);
    printf("time taken for %d values is %f",n,((double)(end-start)/CLOCKS_PER_SEC));
}
