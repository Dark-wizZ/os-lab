#include <stdio.h>
#include <conio.h>

#define MAX_PROCESS 15
#define MAX_RESOURCES 15

void main()
{
    int allocated[MAX_PROCESS][MAX_RESOURCES], max[MAX_PROCESS][MAX_RESOURCES], need[MAX_PROCESS][MAX_RESOURCES], avail[MAX_RESOURCES], work[MAX_RESOURCES], flag[MAX_PROCESS];
    int pno, rno, i, j, prc, count, t, total;
    
    clrscr();
    
    printf("\nEnter number of processes: ");
    scanf("%d", &pno);
    
    printf("\nEnter number of resources: ");
    scanf("%d", &rno);
    
    for (i = 0; i < pno; i++)
        flag[i] = 0;
    
    printf("\nEnter total number of each resource:\n");
    for (i = 0; i < rno; i++)
        scanf("%d", &avail[i]);
    
    printf("\nEnter maximum resources for each process:\n");
    for (i = 0; i < pno; i++)
    {
        printf("\nFor process %d:\n", i+1);
        for (j = 0; j < rno; j++)
            scanf("%d", &max[i][j]);
    }
    
    printf("\nEnter allocated resources for each process:\n");
    for (i = 0; i < pno; i++)
    {
        printf("\nFor process %d:\n", i+1);
        for (j = 0; j < rno; j++)
            scanf("%d", &allocated[i][j]);
    }
    
    printf("\nAvailable resources: ");
    for (j = 0; j < rno; j++)
    {
        total = 0;
        for (i = 0; i < pno; i++)
        {
            total += allocated[i][j];
        }
        avail[j] -= total;
        work[j] = avail[j];
        printf("%d ", work[j]);
    }
    
    count = 0;
    do
    {
        prc = -1;
        for (i = 0; i < pno; i++)
        {
            if (flag[i] == 0)
            {
                for (j = 0; j < rno; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }
                if (j == rno)
                {
                    prc = i;
                    break;
                }
            }
        }
        
        if (prc != -1)
        {
            flag[prc] = 1;
            printf("\nProcess %d completed\n", prc+1);
            for (j = 0; j < rno; j++)
            {
                work[j] += allocated[prc][j];
            }
            count++;
        }
    } while (count < pno && prc != -1);
    
    if (count == pno)
        printf("\nThe system is in a Safe State!!");
    else
        printf("\nThe system is in an Unsafe State!!");
    
    getch();
}
