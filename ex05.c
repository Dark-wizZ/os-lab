#include <stdio.h>

struct seg
{
  int base, limit, range;
};
int np, i;
struct seg s[20];
void getData(){
  printf("\nEnter the no of segments in logical memory: ");
  scanf("%d",&np);
  for(i=0; i<np; i++){
    printf("\nEnter base address and limit of segment %d: ",i);
    scanf("%d %d",&s[i].base, &s[i].limit);
    s[i].range=s[i].base+s[i].limit;
  }
}
void printData(){
  printf("\nSEGMENT\tLIMIT\tRANGE");
  for(i=0; i<np; i++){
    printf("\n%d\t\t%d\t\t%d-%d",i,s[i].limit,s[i].base,s[i].range);
  }
}
void main(){
  getData();
  printData();
}