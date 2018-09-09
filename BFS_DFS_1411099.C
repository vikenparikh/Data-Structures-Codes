/*  VIKEN PARIKH
    SE B2 1411099
    BFS AND DFS
*/

#include<stdio.h>
#include<stdlib.h>
#define max 10

int bfs(int[][max],int,int);
int dfs(int[][max],int,int);
main()
{
int a[max][max],v,i,j,g,result,ch;
char chr;
clrscr();
printf("Enter the number of vertices : ");
scanf("%d",&v);
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
printf("Enter the value of a[%d][%d] : ",i,j);
scanf("%d",&a[i][j]);
}
}
printf("The matrix is :-\n");
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
while(1)
{
printf("Enter the node you want to search : ");
scanf("%d",&g);
printf("n1>Breadh First Search n2>Depth First Search");
printf("\nEnter choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Traversed path for B.F.S : ");
result=bfs(a,v,g);
break;
}
case 2:
{
printf("Traversed path for D.F.S : ");
result=dfs(a,v,g);
break;
}
default:
{
printf("Invalid choice given!!!");
return;
}
}
printf("\nWant to continue?(give 1 for yes) : ");
scanf("%d",&chr);
if(chr!=1)
{
printf("The program will exit.");
return;
}
}
}

int bfs(int a[max][max],int v,int g)
{
int s,i,t,j,open[max],status[max],f;
void insert(int[],int,int*);
int delete(int[],int*);
int queue_empty(int*,int*);

int front=0;
int rear=0;
f=0;
for(i=0;i<v;i++)
status[i]=10;
s=0;
if(s==g)
{
printf("v%d",s);
f=1;
//return f;
}
insert(open,s,&rear);
while((queue_empty(&front,&rear))==0)
{
t=delete(open,&front);
printf("v%d->",t);
status[t]=20;
for(j=0;j<v;j++)
{
if(a[t][j]==1)
{
if(j==g)
{
printf("v%d",j);
f=1;
return f;
}
if(status[j]!=20)
{
insert(open,j,&rear);
status[j]=20;
}
}
}

}
printf("b bb ");
return f;
}
void insert(int queue[],int data,int* rear)
{
if(*rear>=max)
{
printf("Error Overflown");
return;
}
queue[*rear]=data;
(*rear)++;
}
int delete(int queue[],int* front)
{
int data;
data=queue[*front];
(*front)++;
return data;
}

int queue_empty(int* front,int* rear)
{
if(*front==*rear)
return 1;
else
return 0;
}

int dfs(int a[max][max],int v,int g)
{
int s,i,t,j,open[max],status[max],f;
void push(int[],int,int*);
int pop(int[],int*);
int stack_empty(int*);

int top=0;
f=0;
for(i=0;i<v;i++)
status[i]=10;
s=0;
if(s==g)
{
printf("v%d",s);
f=1;
//return f;
}
push(open,s,&top);
while(stack_empty(&top)==0)
{
t=pop(open,&top);
printf("v%d->",t);
status[t]=20;
for(j=0;j<v;j++)
{
if(a[t][j]==1)
{
if(j==g)
{
printf("v%d",j);
f=1;
return f;
}
if(status[j]!=20)
{
push(open,j,&top);
status[j]=20;
}
}
}
}
printf("b bb ");
return f;
}
void push(int stack[],int data,int* top)
{
if(*top>=max)
{
printf("Error overflown");
return;
}
stack[*top]=data;
(*top)++;
}
int pop(int stack[],int *top)
{
int data;
(*top)--;
data=stack[*top];
return data;
}
int stack_empty(int *top)
{
if(*top==0)
return 1;
else
return 0;
}