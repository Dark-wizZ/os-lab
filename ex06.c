#include <stdio.h>

struct process
{
  int max[20],alloc[20],need[20];
  int comp;
};

int np, nr, ares[20];
int i,j;
struct process p[20];

void getData(){
  for(i=0; i<np; i++) p[i].comp=0;
  printf("\nEnter the number of processes: ");
  scanf("%d",&np);
  printf("\nEnter the number of resources: ");
  scanf("%d",&nr);
  printf("\nEnter the total number of each resources: ");
  for(i=0; i<nr; i++){
    scanf("%d",&ares[i]);
  }
  printf("\nEnter the max resources for each process: ");
  for(i=0; i<np; i++){
    printf("\nfor process %d: ",i+1);
    for(j=0; j<nr; j++){
      scanf("%d",&p[i].max[j]);
    }
  }
  printf("\nEnter the allocated resources for each process: ");
  for(i=0; i<np; i++){
    printf("\nfor process %d: ",i+1);
    for(j=0; j<nr; j++){
      scanf("%d",&p[i].alloc[j]);
    }
  }
}
void calcNeed(){
  for(i=0; i<np; i++){
    for(j=0; j<nr; j++){
      p[i].need[j] = p[i].max[j] - p[i].alloc[j];
    }
  }
}
void calcAres(){
  for(i=0; i<nr; i++){
    for(j=0; j<np; j++){
      ares[i] -= p[j].alloc[i];
    }
  }
}
void printAres(){
  printf("\nAvailable resources: ");
  for(i=0; i<nr; i++){
    printf("%d ",ares[i]);
  }
}
void printStat(){
  printf("\nAllocated\tMax\tNeed");
  for(i=0;i<np;i++){
    printf("\n");
    for(j=0;j<nr;j++){
      printf("%d ",p[i].alloc[j]);
    }
    printf("\t");
    for(j=0;j<nr;j++){
      printf("%d ",p[i].max[j]);
    }
    printf("\t");
    for(j=0; j<nr; j++){
      printf("%d ",p[i].need[j]);
    }
  }
}
void freePros(int pi){
  p[i].comp=1;
  for(i=0; i<nr; i++){
    ares[i] += p[pi].alloc[i];
    p[pi].alloc[i]=p[pi].max[i]=p[pi].need[i]=0;
  }
}
void  process(){
  int flag, k;
  for(k=0; k<np; k++){
    printAres();
    printStat();
    for(i=0; i<np; i++){
      flag=1;
      if(p[i].comp) continue;
      for(j=0; j<nr; j++){
        if(p[i].need[j]>ares[j]){
          flag=0;
        }
      }
      if(flag){
        printf("\nProcess %d completed.",i+1);
        freePros(i);
        break;
      }
    }
    if(!flag){
      printf("\nThis system is in unsafe condition! ");
      return;
    }
  }
  printf("\nThis system is in Safe condition. ");
}
void main(){
  getData();
  calcNeed();
  calcAres();
  process();
}

