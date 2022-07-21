     #include<stdio.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
       j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
int main(){
    int n,i,arr[1000],num;
printf("enter the number of integers");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    num = (rand() % n) + 1;
    arr[i-1] = num;
}
    for(i=0;i<n;i++)
   printf(" %d",arr[i]);
   quicksort(arr,0,n-1);
   printf("Order of Sorted elements: ");
   for(i=0;i<n;i++)
   printf(" %d",arr[i]);
   return 0;
}
