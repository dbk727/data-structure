#include<stdio.h>
void main()
{
int arr [100],i,n;
printf("Enter the size of array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Even numbers in array are:");
for (i=0;i<n;i++)
{
if (arr [i]%2==0)
{
printf("%d\n",arr[i]);
}
}
}
