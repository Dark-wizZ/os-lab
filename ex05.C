#include<stdio.h>
#include<conio.h>

void main() {
    int no_seg_log, limit[20], base_phy[20], end_phy[20], i;

    clrscr();
    printf("\nEnter the number of segments in logical memory: ");
    scanf("%d", &no_seg_log);

    for(i = 0; i < no_seg_log; i++) {
        printf("\nEnter limit and base address of segment %d: ", i);
        scanf("%d %d", &limit[i], &base_phy[i]);
        end_phy[i] = base_phy[i] + limit[i];
    }

    printf("\nSEGMENT\tLIMIT\tRANGE");
    for(i = 0; i < no_seg_log; i++)
        printf("\n%d\t%d\t%d - %d", i, limit[i], base_phy[i], end_phy[i]);

    getch();
}