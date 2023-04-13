#include <stdio.h>
void main(){
  int no_phil, max_eat, i, j, k, round=1, c;
  int left, right, curr, ch;
  char phil[100], state[100], curr_phil;

  int getIndex(char[], char, int);
  printf("\nEnter number of philosopher: ");
  scanf("%d",&no_phil);
  max_eat = no_phil/2;
  printf("\n%d philosophers can eat at a time to avoid deadlock.",max_eat);
  printf("\nEnter %d philosopher name one by one: \n",no_phil);
  for(i=0; i<no_phil; i++){
    scanf(" %c",&phil[i]);
    state[i]='t';
  }
  for(i=0; i<no_phil; i++){
    printf("\nposition %d: %c",i+1,phil[i]);
  }
  //print status
  printf("\nStatus: ");
  printf("\nPHILOSOPHER\tSTATE");
  for(i=0; i<no_phil; i++){
    printf("\n%c\t\t%c",phil[i],state[i]);  
  }
  printf("\nEnter %d philosopher who wants to eat: ",max_eat);
  c=1;
  while(1){
    printf("\nEnter hungry philosopher %d",c);
    scanf(" %c",&curr_phil);
    curr = getIndex(phil,curr_phil, no_phil);
    printf("curr= %d",curr);
    left = (curr-1 < 0)? no_phil-1 : curr-1;
    right = (curr+1 >= no_phil)? 0 : curr+1;
    if(state[left]!='e' && state[right]!='e'){
      state[curr]='e';
      printf("\nHungry philosopher %c is granted to eat",curr_phil);
      c++;
    }else{
      state[curr]='h';
      printf("\n%c must wait since her neighbour is eating", phil[curr]);
    }
    if(c>max_eat) break;
  }
  //print current status
  printf("\ncurrent Status: ");
  printf("\nPHILOSOPHER\tSTATE");
  for(i=0; i<no_phil; i++){
    printf("\n%c\t\t%c",phil[i],state[i]);  
  }
}
int getIndex(char c[], char e, int n){
  int i;
  for(i=0; i<n; i++){
    if(c[i]==e){
      return i;
    }
  }
  return -1;
}