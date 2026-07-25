#include<stdio.h>
int main()
{
    int n,i,j,count=0;
    printf("Enter the number of books: ");
    scanf("%d",&n);
    int IDs[n];
    printf("Enter the IDs of the books: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&IDs[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(IDs[i]==IDs[j])
            {
                count++;
            }
            
        }
        if(count>0)
            {
                printf("%d ",IDs[i]);
                count=0;
            }
    }
    return 0;
}