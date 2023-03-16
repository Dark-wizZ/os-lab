#include <stdio.h>
#include <conio.h>
int next = 0, f1, p, c, l, sum;
int asize[30], fsize[30], f1size[30], bsize[30];
void main()
{
  char ch;
  int blsize, i, k;
  void first_fit(int);
  clrscr();
  printf("\nEnter the number of free block: ");
  scanf("%d", &f1);
  sum = 50;
  printf("\nEnter within the width 480.");
  printf("\nEnter width within the limit.\n");
  for (i = 0; i < f1; i++)
  {
    printf("Enter the size of the block%d: ", i);
    scanf("%d", &fsize[i]);
    if (fsize[i] > 481)
    {
      printf("\nExceeding the limit, re-enter the value!");
      continue;
    }
    f1size[i] = fsize[i];
    asize[i] = 0;
    sum = sum + fsize[i];
  }
  printf("\nEnter the number of process: ");
  scanf("%d", &p);
  for (i = 0; i < p; i++)
  {
    printf("Enter the size of allocated memory process%d: ", i);
    scanf("%d", &bsize[i]);
  }
  for (i = 0; i < p; i++)
    first_fit(bsize[i]);
  getch();
}
void first_fit(int n)
{
  int k = 0, i, s1;
  for (i = 0; i < f1; i++)
  {
    if (fsize[i] >= n)
    {
      asize[i] = asize[i] + n;
      next = i + 1;
      printf("\n\nMEMORY ALLOCATION IN BLOCK:%d ", i);
      s1 = 50;
      for (l = 0; l < i; l++)
        s1 = s1 + fsize[l] + asize[l];
      printf("\nMemory allocated for process:%d ", asize[l]);
      fsize[i] = -n;
      k = 1;
      break;
    }
  }
  if (k == 0)
    printf("\n\nNo matching block for %d \n", n);
}