/* 1.WAP to implement stack using array.*/
#include<stdio.h>
# define MAX 10
struct stack
{
int info[MAX];
int top;
};
typedef struct stack STK;
void push(STK *,int );
void pop(STK *);
int main()
{
STK stk;
int i,x;
stk.top=-1;
do
{
printf("\n 1.Push an element");
printf("\n 2.Pop an element");
printf("\n 0.To exit");
printf("\n \nEnter your choice: ");
scanf("%d",&i);
switch(i)
{
case 1:printf("\n Give element to push:");
scanf("%d",&x);
push(&stk,x);
break;
case 2:pop(&stk);
break;
case 0:printf("\n THE END");
break;
default:printf("\n Invalid choice.");
}
}while(i!=0);
}
void push(STK *p,int item)
{
if(p->top==MAX-1)
{
printf("\n Stack Overflow.");
return;
}
p->info[++p->top]=item;
}
void pop(STK *p)
{
if(p->top==-1)
{
printf("\n Stack Underflow.");
return;
}
printf("\n Popped element is %d",p->info[p->top--]);
}
