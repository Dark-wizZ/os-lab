#include <stdio.h>
#include <stdlib.h>
void main()
{
  int i, j, z, sum = 0, c = 0, n, n1, st, min, minind, temp;
  int a[20], b[20], dd[20];
  printf("\nEnter the block number between 0 and 200: ");
  scanf("%d", &st);
  printf("\nOur disk head is on the %d block", st);
  a[0] = st;
  printf("\nEnter the no. of request: ");
  scanf("%d", &n);
  printf("\nEnter request: ");
  for (i = 1; i <= n; i++)
  {
    printf("\nEnter %d request: ", i);
    scanf("%d", &a[i]);
  }
  for (i = 0; i <= n; i++)
    dd[i] = a[i];
  // n1 = n;
  // b[0] = dd[0];
  // while (n1 > 0)
  // {
  //   j = 1;
  //   min = abs(dd[0] - dd[1]);
  //   for (i = 2; i < n1 + 1; i++)
  //   {
  //     if (abs(st - dd[i]) <= min)
  //     {
  //       min = abs(st - dd[i]);
  //       j = i;
  //     }
  //   }
  //   c++;
  //   b[c] = dd[j];
  //   st = dd[j];
  //   dd[0] = dd[j];
  //   --n1;
  //   for (z = j; z < n1 + 1; z++)
  //     dd[z] = dd[z + 1];
  //   dd[z] = '\0';
  // }
  b[0] = dd[0];
for(i=1; i<n-1;i++){
  min=abs(dd[i-1]-dd[i]);
  minind=i;
  for(j=i+1; j<n-1; j++){
    if(abs(dd[i]-dd[j])<min){
      minind=j;
    }
  }
  temp = dd[i];
  dd[i]=dd[minind];
  dd[minind]=temp;
}
  printf("\n\t\tSHORTEST SEEK TIME FIRST: ");
  printf("\nDISK QUEUE:");
  for (i = 0; i <= n; i++)
    printf("\t%d", a[i]);
  printf("\n\nACCESS ORDER:");
  for (i = 0; i <= n; i++)
  {
    printf("\t%d",dd[i]);
    if (i != n)
      sum += abs(ddP[i] - dd[i + 1]);
  }
  printf("\n\nTotal no. of head movements: %d", sum);

}