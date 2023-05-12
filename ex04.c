#include <stdio.h>

struct page{
  int fno, cont[100];
};

int pSize, lmSize, pmSize;
char pMem[100][100];
int nf, np, i, j;
struct page lMem[100];

void getData(){
  printf("\nEnter the page size(power 2): ");
  scanf("%d",&pSize);
  printf("\nEnter the logical memory size(power 2): ");
  scanf("%d",&lmSize); np=lmSize/pSize;
  printf("\nno of pages in logical memory is %d.",np);
  printf("\nEnter the physical memory size(power of 2): ");
  scanf("%d",&pmSize); nf=pmSize/pSize;
  printf("\nno of frames in physical memory is %d.",nf);
  printf("\nEnter content of the logical memory:");
  for(i=0; i<np; i++){
    for(j=0; j<pSize; j++){
      scanf(" %c",&lMem[i].cont[j]);
    }
  }
}
void printLMem(){
  printf("\nLOGICAL MEMORY:");
  for(i=0; i<np; i++){
    printf("\nPAGE %d: ",i);
    for(j=0; j<pSize; j++){
      printf("\nLogical address %d: %c",i*4+j,lMem[i].cont[j]);
    }
  }
}
void getFrameNo(){
  for(i=0; i<np; i++){
    printf("\nEnter frame no for page %d: ",i);
    scanf("%d",&lMem[i].fno);
  }
}
void paging(){
  for(i=0; i<nf; i++){
    for(j=0; j<pSize; j++){
      pMem[i][j]='-';
    }
  }
  for(i=0; i<np; i++){
    for(j=0; j<pSize; j++){
      pMem[lMem[i].fno][j]=lMem[i].cont[j];
    }
  }
}
void printPMem(){
  printf("\nPhysical Memory: ");;
  for(i=0; i<nf; i++){
    printf("\nFrame %d",i);
    for(j=0; j<pSize; j++){
      printf("\nPhysical address %d: %c",i*4+j,pMem[i][j]);
    }
  }
}
void main(){
  getData();
  printLMem();
  getFrameNo();
  paging();
  printPMem();
}