/* 2.WAP to insert and delete in a queue.*/
#include<stdio.h>
# define MAX 10
struct queue
{
int info[MAX];
int front,rear;
};
typedef struct queue Q;
void insert(Q *,int );
void delet(Q *);
int main()
{
Q q;
int i,x;
q.front=q.rear=-1;
do
{
printf("\n 1.Insert an element");
printf("\n 2.Delete an element");
printf("\n 0.To exit");
printf("\n \nEnter your choice: ");
scanf("%d",&i);
switch(i)
{
case 1:printf("\n Give element to insert:");
scanf("%d",&x);
insert(&q,x);
break;
case 2:delet(&q);
break;
case 0:printf("\n THE END");
break;
default:printf("\n Invalid choice.");
}
}while(i!=0);
}
void insert(Q *p,int item)
{
if(p->rear==MAX-1)
{
printf("\n Queue Overflow.");
return;
}
p->info[++p->rear]=item;
}
void delet(Q *p)
{
if(p->front==p->rear)
{
printf("\n Queue Underflow.");
return;
}
printf("\n Deleted element is %d",p->info[++p->front]);
}
