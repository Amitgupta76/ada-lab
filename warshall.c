#include<stdio.h>
#include<math.h>
int max(int,int);
void warshall(int A[10][10],int n) {
    int i,j,k;
	for ( k=0;k<n;k++)
	  for ( i=0;i<n;i++)
	   for ( j=0;j<n;j++)
	    A[i][j]=max(A[i][j],A[i][k]&&A[k][j]);
}
int max(int a,int b) {
	return a>b?a:b;
}
void main() {
	int p[10][10];
	int n;
	int i,j;

    printf("\n Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("\n Enter the adjacency matrix:\n");
	for( i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
            scanf("%d",&p[i][j]);
	}

	printf("\n Matrix of input data: \n");
	for ( i=0;i<n;i++) {
		for ( j=0;j<n;j++)
		   printf(" %d\t",p[i][j]);
		printf("\n");
	}
	warshall(p,n);
	printf("\n Transitive closure: \n");
	for ( i=0;i<n;i++) {
		for ( j=0;j<n;j++)
		   printf(" %d\t",p[i][j]);
		printf("\n");
	}

}
