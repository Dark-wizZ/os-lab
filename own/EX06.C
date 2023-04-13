#include <stdio.h>
#include <conio.h>
int main(){
	int no_pro, no_res, tres[20], max[20][20], aloc[20][20];
	int avail[20][20],need[20][20],completed[20],i,j,k,flag;

	clrscr();
	printf("Enter number of process: ");
	scanf("%d",&no_pro);
	printf("\nEnter number of resources: ");
	scanf("%d",&no_res);
	printf("\nEnter total number of each resources: ");
	for (i=0; i<no_res; i++)
	scanf("%d",&tres[i]);
	printf("\nEnter max resources for each processes: ");
	for(i=0; i<no_pro; i++){
		printf("\nfor process %d: ",i+1);
		for(j=0; j<no_res; j++){
			scanf("%d", &max[i][j]);
		}
	}
	printf("\nEnter allocated resources for each process: ");
	for(i=0; i<no_pro; i++){
		printf("\nfor process %d: ",i+1);
		for(j=0; j<no_res; j++){
			scanf("%d", &aloc[i][j]);
		}
	}
		//calculate available resources
		for(j=0; j<no_res; j++){
			for(k=0; k<no_pro; k++){
				tres[j] -= aloc[k][j];
			}
		}
	for(i=0; i<no_pro; i++){
		printf("\nAvailable resources: ");
		for(j=0; j<no_res; j++)
		printf("%d ",tres[j]);

		//calculate need
		for(j=0; j<no_pro; j++){
			for(k=0; k<no_res; k++){
				need[j][k] = max[j][k]-aloc[j][k];
			}
		}
		printf("\nAllocated\tMax\tNeed");
		for(j=0; j<no_pro; j++){
			printf("\n");
			for(k=0; k<no_res; k++){
				printf("%d ",aloc[j][k]);
			}
			printf("\t");
			for(k=0; k<no_res; k++){
				printf("%d ",max[j][k]);
			}
			printf("\t");
			for(k=0; k<no_res; k++){
				printf("%d ",need[j][k]);
			}
			printf("\t");
		}
		//check completion
		for(j=0; j<no_pro;j++){
			flag=0;
			for(k=0; k<no_res; k++){
				if(need[j][k]>tres[k]){
					flag=1;
				}
			}
			//ignore completed process
			if(completed[j]) continue;
			if(!flag){
				printf("\nprocess %d completed",j+1);
				//free resources of completed process
				for(k=0; k<no_res; k++){
					tres[k] += aloc[j][k];
					aloc[j][k]=0; max[j][k]=0;
					need[j][k]=0;
				}
				completed[j]=1;
				break;
			}
			getch();
		}
		if(flag) {
			printf("\nThe system is in undafe state!");
			getch();
			return 1;
		}
	}
	printf("\nthe system is in safe state");
	getch();
	return 0;
}