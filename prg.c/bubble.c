#include<stdio.h>
void main()
{
int n,i,j,array[50],temp;
printf("Enter the limit:");
scanf("%d",&n);
printf("\n enter the element\n");
for(i=0;i<n;i++)
{
scanf("%d",&array[i]);
}
for (i=0;i<n-1;i++)
{
for (j=0;j<(n-i-1);j++)
{
if(array [j]>array[j+1])
{
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
}
}
}
printf("\n Sorted Array =");
for(i=0;i<n;i++)
{
printf("%d | ",array[i]);
}
printf("\n");
}

