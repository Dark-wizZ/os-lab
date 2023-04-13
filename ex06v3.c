#include <stdio.h>
#include <conio.h>

void main()
{
  int allocated[15][15], max[15][15], need[15][15], avail[15], tres[15], work[15], flag[15];
  int pno, rno, i, j, prc, count, total;
  count = 0;
  clrscr();
  printf("\nEnter number of process: ");
  scanf("%d", &pno);
  printf("\nEnter number of resources: ");
  scanf("%d", &rno);
  for (i = 1; i <= pno; i++)
    flag[i] = 0;
  printf("\nEnter total numbers of each resource: ");
  for (i = 1; i <= rno; i++)
    scanf("%d", &tres[i]);
  printf("\nEnter Max resources for each process:\n");
  for (i = 1; i <= pno; i++)
  {
    printf("For process %d: ", i);
    for (j = 1; j <= rno; j++)
      scanf("%d", &max[i][j]);
  }
  printf("\nEnter allocated resources for each process:\n");
  for (i = 1; i <= pno; i++)
  {
    printf("For process %d: ", i);
    for (j = 1; j <= rno; j++)
      scanf("%d", &allocated[i][j]);
  }
  printf("\nAvailable resources:\n");
  for (j = 1; j <= rno; j++)
  {
    avail[j] = 0;
    total = 0;
    for (i = 1; i <= pno; i++)
      total += allocated[i][j];
    avail[j] = tres[j] - total;
    work[j] = avail[j];
    printf("%d ", work[j]);
  }
  do
  {
    for (i = 1; i <= pno; i++)
      for (j = 1; j <= rno; j++)
        need[i][j] = max[i][j] - allocated[i][j];
    printf("\n\nAllocated\tMax\t\tNeed\n");
    for (i = 1; i <= pno; i++)
    {
      for (j = 1; j <= rno; j++)
        printf("%d ", allocated[i][j]);
      printf("\t\t");
      for (j = 1; j <= rno; j++)
        printf("%d ", max[i][j]);
      printf("\t\t");
      for (j = 1; j <= rno; j++)
        printf("%d ", need[i][j]);
      printf("\n");
    }
    prc = 0;
    for (i = 1; i <= pno; i++)
    {
      if (flag[i] == 0)
      {
        prc = i;
        for (j = 1; j <= rno; j++)
          if (work[j] < need[i][j])
          {
            prc = 0;
            break;
          }
      }
      if (prc != 0)
        break;
    }
    if (prc != 0)
    {
      printf("\nProcess %d completed", i);
      count++;
      printf("\nAvailable Resources:");
      for (j = 1; j <= rno; j++)
      {
        work[j] += allocated[prc][j];
        allocated[prc][j] += allocated[prc][j];
        printf("%d ", work[j]);
      }
      flag[prc] = 1;
    }
  } while (count != pno && prc != 0);
  if (count == pno)
    printf("\n\nSystem is in safe state");
  else
    printf("\n\nSystem is in unsafe state");
  getch();
}