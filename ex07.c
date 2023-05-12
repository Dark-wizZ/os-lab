#include <stdio.h>

struct phil{
  char state, name;
};

int i,j,np,max, c=0;
struct phil p[20];
char ch;

void getData(){
  printf("\nEnter number of philosopher: ");
  scanf("%d",&np);
  max = np/2;
  printf("\n%d philosopher can eat at a time to avoid deadlock.",max);
  printf("\nEnter %d philosphers name: ",np);
  for(i=0; i<np; i++){
    printf("\nposition %d: ",i);
    scanf(" %c",&p[i].name);
    p[i].state='t';
  }
}
int pindex(char name){
  for(i=0; i<np; i++) if(p[i].name==name) return i;
}
int canEat(char name){
  int index = pindex(name);
  int left = (index-1<0)? np-1: index-1;
  int right = (index+1>=np)? 0 : index+1;
  if(p[left].state=='e' || p[right].state=='e') return 0;
  return 1;
}
void printStat(){
  printf("\nCURRENT STATUS:");
  printf("\nPhilosopher\tState");
  for(i=0; i<np; i++){
    printf("\n%c\t\t%c",p[i].name,p[i].state);
  }
}
void grandEat(char hp){
    if(canEat(hp)){
      p[pindex(hp)].state='e';
      c++;
      printf("\nHungry philosopher %c is granted to eat.",hp);
    }else{
      p[pindex(hp)].state='h';
      printf("\n%c must wait since her neighour is eating",hp);
    }
}
void prompt(){
  char hp;
  printf("\nEnter %d philosophers who wants to eat",max-c);
  while(c<max){
    printf("\nEnter hungry philosopher %d: ",c+1);
    scanf(" %c",&hp);
    grandEat(hp);
  }
}
void refresh(){
  c=0;
  for(i=0; i<np; i++){
    if(p[i].state!='h'){
      p[i].state='t';
    }
  }
}
void autoEat(){
  for(i=0; i<np; i++){
    if(p[i].state=='h'){
      grandEat(p[i].name);
    }
  }
}
void main(){
  getData();
  printStat();
  prompt();
  printStat();
  while(1){
    printf("\nDo you want to continue?(y/n) ");
    scanf(" %c",&ch);
    if(ch=='n') break;
    refresh();
    printStat();
    autoEat();
    prompt();
    printStat();
  }
}