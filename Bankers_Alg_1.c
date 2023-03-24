// BANKERS ALGORITHM

/*
I) Add the following functionalities in program
a) Accept Available
b) Display Allocation, Max
c) Display the contents of need matrix
d) Display Available

Process  Allocation  MAX
        A B C        A B C
P0      0 1 0        7 5 3
P1      2 0 0        3 2 2
P2      3 0 2        9 0 2
P3      2 1 1        2 2 2
P4      0 0 2        4 3 3
*/

#include <stdio.h>
#include <stdlib.h>

int n, m, i, j, k, y, alloc[10][10], max[10][10], avail[20], ind = 0; // n- process m-resources

void Accept()
{
    printf("Enter Number of Processes : ");
    scanf("%d", &n);

    printf("Enter no of resources : ");
    scanf("%d", &m);

    printf("Enter the allocation matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the max matrix: " );
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter the available matrix : ");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }
   
}
   
//Bankers Algorithm logic...
void Bankers()
{
     int ifinish[n],isafesequence[n],iwork[m],ineed[n][m];

    //calculating need matrix  need_matrix = max_matrix - allocation_matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            ineed[i][j]=max[i][j]-alloc[i][j];
        }
    }
    //print need matrix
    printf("Need Matrix Is : ");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0; j<m; j++)
        {
            printf("%d\t",ineed[i][j]);
        }
    }
    
    for(i=0; i<m; i++)
    {
        iwork[i]=avail[i];
    }
      for(i=0; i<n; i++)
    {
        ifinish[i]=0;
    }
    
    
    for(k=0; k<n; k++)
    {
        for(i=0;i<n;i++)
        {
            if(ifinish[i] == 0)
            {
                int flag=0;
                for(j=0; j<m; j++)
                {
                    if(ineed[i][j] > iwork[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    isafesequence[ind++]=i;
                    for(y=0; y<m; y++)
                    {
                      iwork[y] += alloc[i][y];
                    ifinish[i]=1;
                    }
                }
            }
        }
   }
    printf("\nFollowing is the SAFE Sequence\n");
    for(i = 0; i <= n - 1; i++)
    {
      printf(" P%d ", isafesequence[i]);
    }
    printf("\n");

}

int main()
{
    Accept();
    Bankers();
}
