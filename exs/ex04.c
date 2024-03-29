#include<stdio.h>
#include<math.h>
int main() {
		int pageSize, logMemorySize, numPages, physMemorySize, numFrames;
		char logicalMemory[100][100];
		char physicalMemory[100][100];
		int pageTable[100];
		int i,j,k;

		printf("Enter the page size(power of 2): ");
		scanf("%d", &pageSize);

		printf("Enter the logical memory size(power of 2): ");
		scanf("%d", &logMemorySize);

		numPages = logMemorySize / pageSize;

		printf("No. of pages in logical memory: %d\n", numPages);

		printf("Enter the physical memory size(power of 2): ");
		scanf("%d", &physMemorySize);

		numFrames = physMemorySize / pageSize;

		printf("No. of frames in physical memory: %d\n", numFrames);

		printf("Enter the contents of logical memory:\n");

		for(i=0; i<numPages; i++) {
				for(j=0; j<pageSize; j++) {
						char c;
						scanf(" %c", &c);
						logicalMemory[i][j] = c;
				}
		}

		printf("Logical Memory:\n");

		for(i=0; i<numPages; i++) {
				printf("PAGE %d:\n", i);

				for(j=0; j<pageSize; j++) {
						printf("Logical address %d: %c\n", i*pageSize+j, logicalMemory[i][j]);
				}
		}

		for(i=0; i<numPages; i++) {
				printf("Enter frame no for page %d(0-%d): ", i, numFrames-1);
				scanf("%d", &pageTable[i]);
		}

		printf("Physical Memory:\n");

		for(i=0; i<numFrames; i++) {
				printf("FRAME %d:\n", i);

				for(j=0; j<pageSize; j++) {
						int pageNum = -1;

						for(k=0; k<numPages; k++) {
                if(pageTable[k] == i) {
                    pageNum = k;
                    break;
                }
            }

            if(pageNum != -1) {
                printf("Physical Address %d: %c\n", i*pageSize+j, logicalMemory[pageNum][j]);
                physicalMemory[i][j] = logicalMemory[pageNum][j];
            }
            else {
                printf("Physical Address %d: -\n", i*pageSize+j);
                physicalMemory[i][j] = '-';
            }
        }

        printf("Press any key.\n");
        getchar();
    }

    return 0;
}
