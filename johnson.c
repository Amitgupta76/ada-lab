#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

int searchArr(int a[], int n, int mobile)
{   int i;
    for (i = 0; i < n; i++)
        if (a[i] == mobile)
           return i + 1;
}

int getMobile(int a[], bool dir[], int n)
{
    int mobile_prev = 0, mobile = 0,i;
    for (i = 0; i < n; i++)
    {
        if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (a[i] > a[i-1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
        if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
        {
            if (a[i] > a[i+1] && a[i] > mobile_prev)
            {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}

int printOnePerm(int a[], bool dir[], int n)
{    int i;
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    if (dir[a[pos - 1] - 1] ==  RIGHT_TO_LEFT)
       {
           int temp=a[pos-1];
           a[pos-1]=a[pos-2];
           a[pos-2]=temp;
       }

    else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
       {
           int temp=a[pos];
           a[pos]=a[pos-1];
           a[pos-1]=temp;
       }


    for (i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            if (dir[a[i] - 1] == LEFT_TO_RIGHT)
                dir[a[i] - 1] = RIGHT_TO_LEFT;
            else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
                dir[a[i] - 1] = LEFT_TO_RIGHT;
        }
    }

    for (i = 0; i < n; i++)
        printf("%d",a[i]);
    printf("\n");
}


int fact(int n)
{
    int res = 1,i;
    for (i = 1; i <= n; i++)
        res = res * i;
    return res;
}


void printPermutation(int n)
{

    int a[n],i;


    bool dir[n];


    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d",a[i]);
    }
    printf("\n");


    for (i = 0; i < n; i++)
        dir[i] =  RIGHT_TO_LEFT;

    for (i = 1; i < fact(n); i++)
        printOnePerm(a, dir, n);
}


int main()
{
    int n;
    printf("\nEnter number of digits: ");
    scanf("%d",&n);
    printPermutation(n);
    return 0;
}

