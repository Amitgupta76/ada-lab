#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[],int n)
{
    int a,b,key;
    for (a = 1; a < n; a++) 
    {
        key = arr[a];
        b = a - 1;
        while (b >= 0 && arr[b] > key) 
        {
            arr[b + 1] = arr[b];
            b = b - 1;
        }
        arr[b + 1] = key;
    }
}

int main()
{
    time_t start,end;
    int arr[10000];
    int i,size;
    printf("Program to implement insertion sort on array of numbers\n");
    printf("Enter the size of the array: \n");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        arr[size-i] = i;
    }
    start = clock();
    insertion_sort(arr,size);
    end = clock();
    printf("Time taken to sort the elements is: %f ",difftime(end,start));
    return 0;
}


Values
1000 : 1382
2000 : 5309
3000 : 11857
4000 : 20860
5000 : 32481
