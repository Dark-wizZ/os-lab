#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int np, i, d[100], init, total;

void getRequest(){
  printf("\nEnter the initial position of the head: ");
  scanf("%d",&init);
  printf("\nNow the head is in %d block",init);
  printf("\nEnter the number of requests: ");
  scanf("%d",&np);
  d[0]=init;
  for(i=1; i<=np; i++){
    printf("\nEnter %d request: ",i);
    scanf("%d",&d[i]);
  }
}
void calcHeadMove(){
  for(i=0; i<np; i++){
    total+= abs(d[i]-d[i+1]);
  }
}
void printStat(){
  printf("\nFIRST COME FIRST SERVE: ");
  printf("\nDisk Queue: ");
  for(i=0; i<np; i++){
    printf("\t%d",d[i]);
  }
  printf("\nAccess Order: ");
  for(i=0; i<np; i++){
    printf("\t%d",d[i]);
  }
  printf("\nTotal number of head movements: %d",total);
}
void main(){
  getRequest();
  calcHeadMove();
  printStat();
}