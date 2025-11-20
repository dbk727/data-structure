#include<stdio.h>
void main()
{
int arr[20],i,n,p,k;
printf("Enter the size ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the position to delete");
scanf("%d",&p);
n=n-1;
k=arr[p-1];
printf("the  element to delete:%d",k);
for(i=p-1;1<n;i++)
{
arr[i]=arr[i+1];
}
printf("Enter new array\n");
for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}
}
