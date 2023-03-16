#include <stdio.h>
#include <conio.h>
struct process
{
	char name[10];
	int hr, min, sec, burst, wait, arrival, exit;
};
void main()
{
	struct process p[20], temp;
	void read_details_of_process(struct process[], int);
	void print_details_of_process(struct process[], int, int);
	int calculate_waiting_time(struct process[], int);
	int n, total;
	clrscr();
	printf("\nEnter the number of process: ");
	scanf("%d", &n);
	read_details_of_process(p, n);
	total = calculate_waiting_time(p, n);
	print_details_of_process(p, n, total);
	getch();
}
void read_details_of_process(struct process p[], int n)
{
	int i, j;
	printf("\nEnter the details of %d processes: ", n);
	for (i = 0; i < n; i++)
	{
		printf("\n\nProcess %d:", (i + 1));
		printf("\nEnter process name: ");
		scanf("%s", &p[i].name);
		printf("Enter arrival time: ");
		printf("\n\tEnter Hour: ");
		scanf("%d", &p[i].hr);
		printf("\tEnter Minute: ");
		scanf("%d", &p[i].min);
		printf("\tEnter Second: ");
		scanf("%d", &p[i].sec);
		printf("Enter the burst time(in terms of seconds): ");
		scanf("%d", &p[i].burst);
		p[i].arrival = p[i].sec + (p[i].min * 60) + (p[i].hr * 3600);
	}
}
int calculate_waiting_time(struct process p[], int n)
{
	struct process temp;
	int i, j, total = 0, t;
	p[0].exit = p[0].arrival + p[0].burst;
	p[0].wait=0;
	for (i = 1; i < n; i++)
	{
		if (p[i].arrival > p[i - 1].exit)
		{
			p[i].wait = 0;
			p[i].exit = p[i].arrival + p[i].burst;
		}
		else if (p[i].arrival < p[i - 1].exit)
		{
			t = p[i].arrival - p[i - 1].arrival;
			p[i].wait = p[i - 1].wait - t + p[i - 1].burst;
			p[i].exit = p[i].arrival + p[i].wait + p[i].burst;
		}
		else
		{
			p[i].wait = p[i - 1].wait + p[i - 1].burst;
			p[i].exit = p[i].arrival + p[i].wait + p[i].burst;
		}
		total += p[i].wait;
	}
	return total;
}
void print_details_of_process(struct process p[], int n, int total)
{
	int i, j;
	clrscr();
	printf("\nProcess Name\tArrival Time\tBurst Time\tWaiting Time");
	for (i = 0; i < n; i++)
	{
		printf("\n%s\t\t%d:%d:%d\t\t%d\t\t%d", p[i].name, p[i].hr, p[i].min, p[i].sec, p[i].burst, p[i].wait);
	}
	printf("\nTotal Waiting Time: %d", total);
	printf("\nAverage Waiting Time: %0.2f", (total / (n * 1.0)));
}