#include <stdio.h>

int nb, np, b[100], p[100];
int i, j;

void getData(){
  printf("\nEnter the number of free blocks: ");
  scanf("%d", &nb);
  printf("\nEnter the size of each block(within 480):");
  for(i=0; i<nb; i++){
    printf("\nBlock %d: ",i+1);
    scanf("%d", &b[i]);
  }
  printf("\nEnter the number of processes: ");
  scanf("%d", &np);
  printf("\nEnter the size of allocated memory of each process: ");
  for(i=0; i<np; i++){
    printf("\nProcess %d: ", i+1);
    scanf("%d", &p[i]);
  }
}
void worstFit(){
  int flag;
  for(i=0; i<np; i++){
    flag=1;
    for(j=0; j<nb; j++){
      if(b[j]>=p[i]){
        b[j] -= p[i];
        flag=0;
        printf("\nMemory allocated for process %d in Block %d .",i+1, j+1);
        break;
      }
    }
    if(flag){
      printf("\nNo memory block for process %d.",i+1);
    }
  }
}
void main(){
  getData();
  worstFit();
}