#include<stdio.h>
int main()
{
    int n,h,k,i=0;
    char items[100][50];
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(i=0;i<n;i++)
    {
        scanf("%s",items[i]);
    }
    printf("Enter no.of hours: ");
    scanf("%d",&h);
    k=h%n;
    for(i=k;i<n;i++)
    {
        printf("%s\t",items[i]);
    }
    for(i=0;i<k;i++)
    {
        printf("%s\t",items[i]);
    }
    return 0;
}