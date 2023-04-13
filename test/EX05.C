#include <conio.h>
#include <stdio.h>
void main(){
	int n, limit[20], base[20], end[20], i;
	clrscr();
	printf("Enter the no segment in logical memory: ");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("Enter the limit and base address of segment %d: ",i+1);
		scanf("%d %d",&limit[i], &base[i]);
		end[i] = limit[i]+base[i];
	}
	printf("Segment\tLimit\tRange");
	for(i=0; i<n; i++){
		printf("\n%d\t%d\t%d - %d",i+1,limit[i],base[i],end[i]);
	}
	getch();
}