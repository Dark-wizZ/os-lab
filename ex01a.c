#include <stdio.h>

struct process{
  char name[100];
  int hr, sec, min, arr, burst, exit, wait;
};
int np, i, total;
struct process p[100];
void getProcesses(){
  printf("\nEnter the number of processes: ");
  scanf("%d",&np);
  printf("\nEnter the detail of each processes: ");
  for(i=0; i<np; i++){
    printf("\nProcess %d: ",i+1);
    printf("\nEnter the name: ");
    scanf("%s",p[i].name);
    printf("\nEnter the arrival time(hh mm ss): ");
    scanf("%d %d %d",&p[i].hr, &p[i].min, &p[i].sec);
    printf("\nEnter the  burst time: ");
    scanf("%d",&p[i].burst);
    p[i].arr = p[i].hr*60*60 + p[i].min*60 + p[i].sec;
  }
}
void calcWaitingTime(){
  p[0].exit = p[0].arr + p[0].burst;
  p[0].wait = 0;
  for (i=1; i<np; i++){
    if(p[i].arr >= p[i-1].exit){
      p[i].wait=0;
      p[i].exit=p[i].arr + p[i].exit;
    }else{
      p[i].wait = p[i-1].exit - p[i].arr;
      p[i].exit = p[i].arr + p[i].wait + p[i].burst;
    }
    total += p[i].wait;
  }
}
void printStats(){
  printf("\nProcess Name\tArrival Time\tBurst Time\tWaiting Time");
  for(i=0; i<np; i++){
    printf("\n%s\t\t%d:%d:%d\t\t%d\t\t%d",p[i].name,p[i].hr,p[i].min,p[i].sec,p[i].burst,p[i].wait);
  }
  printf("\nTotal waiting time: %d",total);
  printf("\nAverage waiting time: %0.2f",total/(np*1.0));
}
void main(){
  getProcesses();
  calcWaitingTime();
  printStats();
}
