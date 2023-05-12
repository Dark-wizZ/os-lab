#include <stdio.h>

struct process{
  char name[100];
  int burst, wait;
};

int i,j,np, total;
struct process p[100], temp;

void getProcess(){
  printf("\nEnter the number of processes: ");
  scanf("%d",&np);
  printf("\nEnter detail for each process: ");
  for(i=0; i<np; i++){
    printf("\nEnter detail of process %d: ",i+1);
    printf("\nEnter process name: ");
    scanf("%s",&p[i].name);
    printf("\nEnter burst time: ");
    scanf("%d",&p[i].burst);
  }
}
void calWaitingTime(){
  p[0].wait = 0;
  for(i=1; i<np; i++){
    p[i].wait = p[i-1].burst+p[i-1].wait;
    total += p[i].wait;
  }
}
void sort(){
  for(i=0; i<np; i++){
    for(j=0; j<np-1; j++){
      if(p[j].burst>p[j+1].burst){
        temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
      }
    }
  }
}
void printStat(){
  printf("\nProcess Name\tBurst Time\tWaiting Time");
  for(i=0; i<np; i++){
    printf("\n%s\t\t%d\t\t%d",p[i].name,p[i].burst,p[i].wait);
  }
  printf("\nTotal wait time: %d",total);
  printf("\nAverage wait time: %0.2f",(total*1.0)/np);
}
void main(){
  getProcess();
  sort();
  calWaitingTime();
  printStat();
}