#include<stdio.h>
int main()
{
    int s1,s2,s3,i;
    printf("Enter the size of first array :\n");
    scanf("%d",&s1);
    int ar[s1];
    printf("\nEnter the elements of first array :\n");
    for(i=0;i<s1;i++)
        {
            scanf("%d",&ar[i]);
        }
        printf("\nThe elements of first array after sorting :\n");
        for(i=0;i<s1;i++)
        {
            int temp,j;
            for(j=i+1;j<s1;j++)
            {
                if(ar[i]>ar[j])
                {
                    temp=ar[i];
                    ar[i]=ar[j];
                    ar[j]=temp;
                }
            }
        }
    for(i=0;i<s1;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\nEnter the size of second array :\n");
    scanf("%d",&s2);
    int br[s2];
    printf("\nEnter the elements of second array :\n");
    for(i=0;i<s2;i++)
    {
    scanf("%d",&br[i]);
    }
    printf("\nThe elements of second array after sorting :\n");
    for(i=0;i<s2;i++)
    {
        int temp,j;
        for(j=i+1;j<s2;j++)
        {
            if(br[i]>br[j])
            {
                temp=br[i];
                br[i]=br[j];
                br[j]=temp;
            }
        }
    }
    for(i=0;i<s2;i++)
    {
        printf("%d ",br[i]);
    }
    s3=s1+s2;
    int cr[s3];
    for(i=0;i<s1;i++)
    {
        cr[i]=ar[i];
    }
    for(i=0;i<s2;i++)
    {
        cr[i+s1]=br[i];
    }
    printf("\nThe merged array before sorting :\n");
    for(i=0;i<s3;i++)
    {
        printf("%d ",cr[i]);
    }
    printf("\nThe merged array after sorting :\n");
    for(i=0;i<s3;i++)
    {
        int temp,j;
        for(j=i+1;j<s3;j++)
        {
            if(cr[i]>cr[j])
            {
                temp=cr[i];
                cr[i]=cr[j];
                cr[j]=temp;
            }
        }
    }
    for(i=0;i<s3;i++)
    {
        printf("%d ",cr[i]);
    }
    return 0;
}
