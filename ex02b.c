#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
  int i, j, z, sum = 0, c = 0, n, n1, st, min;
  int a[20], b[20], dd[20];
  clrscr();
  do
  {
    printf("\nEnter the block number between 0 and 200: ");
    scanf("%d", &st);
  } while ((st >= 200) || (st < 0));
  printf("\nOur disk head is on the %d block", st);
  a[0] = st;
  printf("\nEnter the no. of request: ");
  scanf("%d", &n);
  printf("\nEnter request: ");
  for (i = 1; i <= n; i++)
  {
    printf("\nEnter %d request: ", i);
    scanf("%d", &a[i]);
    do
    {
      if ((a[i] > 200) || (a[i] < 0))
      {
        printf("\nBlock number must be between 0 and 200!");
      }
    } while ((a[i] > 200) || (a[i] < 0));
  }
  for (i = 0; i <= n; i++)
    dd[i] = a[i];
  n1 = n;
  b[0] = dd[0];
  st = dd[0];
  while (n1 > 0)
  {
    j = 1;
    min = abs(dd[0] - dd[1]);
    for (i = 2; i < n1 + 1; i++)
    {
      if (abs(st - dd[i]) <= min)
      {
        min = abs(st - dd[i]);
        j = i;
      }
    }
    c++;
    b[c] = dd[j];
    st = dd[j];
    dd[0] = dd[j];
    --n1;
    for (z = j; z < n1 + 1; z++)
      dd[z] = dd[z + 1];
    dd[z] = '\0';
  }
  printf("\n\t\tSHORTEST SEEK TIME FIRST: ");
  printf("\nDISK QUEUE:");
  for (i = 0; i <= n; i++)
    printf("\t%d", a[i]);
  printf("\n\nACCESS ORDER:");
  for (i = 0; i <= c; i++)
  {
    printf("\t%d", b[i]);
    if (i != c)
      sum += abs(b[i] - b[i + 1]);
  }
  printf("\n\nTotal no. of head movements: %d", sum);
  getch();
}