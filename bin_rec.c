#include <stdio.h>
#include<time.h>
void delay()
{
    int k;
for(k=0;k<5000000;k++)
{}
}
void binary_search(int [], int, int, int);
void bubble_sort(int [], int);

int main()
{
    int key, n, i;
    int arr[10000];
    clock_t start,end;
    printf("Enter size of a list: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    arr[i]=i;
    key=arr[n-1];
    i=0;
    bubble_sort(arr, n);
    start=clock();
    binary_search(arr, 0, n, key);
    end=clock();
}

void bubble_sort(int list[], int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++)
        {
            if (list[i] > list[j])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void binary_search(int list[], int lo, int hi, int key)
{   delay();
    int mid;

    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found\n");
    }
    else if (list[mid] > key)
    {
        binary_search(list, lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search(list, mid + 1, hi, key);
    }
}
