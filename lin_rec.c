#include <stdio.h>
#include<time.h>
void delay()
{
    int k;
for(k=0;k<5000000;k++)
{}
}
int RecursiveLS(int arr[], int value, int index, int n)
{   delay();
    int pos = 0;

    if(index >= n)
    {
        return 0;
    }

    else if (arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }

    else
    {
        return RecursiveLS(arr, value, index+1, n);
    }
    return pos;
}

int main()
{
    int n, key, pos, m = 0, arr[10000],i;
    clock_t start,end;
    printf("Enter the total elements in the array  ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    arr[i]=i;
    key=arr[n-1];
    i=0;
    start=clock();
    pos =  RecursiveLS(arr, key, 0, n);
    end=clock();
    if (pos != 0)
    {
        printf("Element found at pos %d ", pos);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}
