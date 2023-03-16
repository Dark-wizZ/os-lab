#include <conio.h>
struct process
{
  char name[10];
  int burst, wait;
};
void main()
{
  void read_details_of_process(struct process[], int);
  int calculate_waiting_time(struct process[], int);
  void print_details_of_process(struct process[], int, int);
  struct process p[20];
  int total, n;
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
    printf("Enter the burst time: ");
    scanf("%d", &p[i].burst);
  }
}
int calculate_waiting_time(struct process p[], int n)
{
  int i, j, t, total = 0;
  struct process temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (p[i].burst > p[j].burst)
      {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    if (i == 0)
      p[i].wait = 0;
    else
      p[i].wait = p[i - 1].wait + p[i - 1].burst;
    total += p[i].wait;
  }
  return total;
}
void print_details_of_process(struct process p[], int n, int total)
{
  int i;
  clrscr();
  printf("\nProcess Name\tBurst Time\tWaiting Time");
  for (i = 0; i < n; i++)
  {
    printf("\n%s\t\t%d\t\t%d", p[i].name, p[i].burst, p[i].wait);
  }
  printf("\nTotal Waiting Time: %d", total);
  printf("\nAverage Waiting Time: %0.2f", (total / (n * 1.0)));
}
