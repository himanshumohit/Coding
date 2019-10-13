#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* create(struct Node *head){
	struct Node *t1=(struct Node *)malloc(sizeof(struct Node));
	struct Node *p;
	
	cout<<"Enter Data: "<<endl;
	cin>>t1->data;
	t1->next=NULL;
	
	if(head==NULL)
		head=t1;
	else{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=t1;
	}
	return head;
}

void display(struct Node *head){
	struct Node *p=head;
	cout<<"Display: "<<endl;
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}

void ReverseDisplay(struct Node* p){
	if(p!=NULL){
		ReverseDisplay(p->next);
		cout<<p->data<<endl;
	}
	else
		return;
}

int CountNode(struct Node *p){
	int c=0;
	while(p!=NULL){
		c++;
		p=p->next;
	}
	return c;
}

int SumNodes(struct Node *p){
	int c=0;
	while(p!=NULL){
		c+=p->data;
		p=p->next;
	}
	return c;
}

int MaxNode(struct Node *head){
	int c=0;
	struct Node *p=head;
	while(p!=NULL){
		if(p->data > c)
			c=p->data;
		p=p->next;
	}
	return c;
}

int FindNode(struct Node *p,int n){
	int c=1;
	while(p!=NULL){
		if(p->data == n){
			return c;
		}
		c++;
		p=p->next;
	}
	c=0;
	return c;
}

struct Node* InsertNode(struct Node *head,int n){
	struct Node *p=head, *temp=NULL;
	if(n==0){
		cout<<"Enter Element to be Inserted: "<<endl;
		temp=(struct Node*)malloc(sizeof(struct Node));
		cin>>temp->data;
		temp->next=head;
		head=temp;
		cout<<"Element Inserted"<<temp->data<<endl;
	}
	else if(n>0 && n<CountNode(head)){
		while(n>=1){
			p=p->next;
			n--;
		}
		cout<<"Enter Element to be Inserted: "<<endl;
		temp=(struct Node*)malloc(sizeof(struct Node));
		cin>>temp->data;
		temp->next=p->next;
		p->next=temp;
		cout<<"Element Inserted"<<endl;
	}
	else if(n ==  CountNode(head)){
		while(p->next!=NULL)
			p=p->next;
		cout<<"Enter Element to be Inserted: "<<endl;
		temp=(struct Node*)malloc(sizeof(struct Node));
		cin>>temp->data;
		temp->next=NULL;
		p->next=temp;
		cout<<"Element Inserted"<<endl;
	}
	else
		cout<<"Position not Found"<<endl;
	return head;
}
 
struct Node* DeleteNode(struct Node *head, int n){
	struct Node *p,*temp;
	if(n>CountNode(head)){
		cout<<"Location not Found"<<endl;
	}
	else if(n==1){
		temp=head;
		head=temp->next;
		temp->next=NULL;
		free(temp);
	}
	else{
		p=head;
		int i=1;
		while(i<n-1){
			p=p->next;
			i++;
		}
		temp=p->next;
		p->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
	return head;
}

int SortedCheck(struct Node *head){
	struct Node *p=head;
	int d=p->data;
	cout<<"1. Check for Ascending"<<endl<<"2. Check for descending"<<endl;
	int n;
	cin>>n;
	if(n==1){
		while(p!=NULL){
			if(p->data < d)
			{
				d=0;
				return d;
			}
			d=p->data;
			p=p->next;
		}
	}
	else{
		while(p!=NULL){
			if(p->data > d)
			{
				d=0;
				return d;
			}
			d=p->data;
			p=p->next;
		}
	}
	return d;
}

struct Node* ReverseList(struct Node *head){
	struct Node *p,*q,*r;
	p=head;
	q=NULL;
	r=NULL;
	while(p!=NULL){
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	cout<<"List Reversed"<<endl;
	head=q;
	display(head);
	return head;
}

int main(){
	struct Node *head=NULL;
	while(1){
		cout<<"______________________________________________"<<endl;
		cout<<"Choose: "<<endl<<"1. Add an Element"<<endl<<"2. Display "<<endl<<"3. Reverse Display"<<endl;
		cout<<"4. Count Numeber of Nodes"<<endl<<"5. Sum of All Elements"<<endl<<"6. Find Max Element"<<endl;
		cout<<"7. Search an Element"<<endl<<"8. Insert an Element"<<endl<<"9. Delete a node"<<endl;
		cout<<"10. Check if List is Sorted"<<endl<<"11. Reverse the List"<<endl<<"12. Exit"<<endl;
		cout<<"______________________________________________"<<endl;
		int ch,c=0,n=0;
		cin>>ch;
		switch(ch){
			case 1: head=create(head);
					break;
			case 2: display(head);
					break;
			case 3: cout<<"Reverse Display: "<<endl;
					ReverseDisplay(head);
					break;
			case 4: c=CountNode(head);
					cout<<"Number of Nodes: "<<c<<endl;
					break;
			case 5: c=SumNodes(head);
					cout<<"Sum of all elements: "<<c<<endl;
					break;
			case 6: c=MaxNode(head);
					cout<<"Maximum Element is: "<<c<<endl;
					break;
			case 7: cout<<"Enter Element to be searched: "<<endl;
					cin>>n;
					c=FindNode(head,n);
					if(c)
						cout<<"Element Found on Position: "<<c<<endl;
					else
						cout<<"Element not Found"<<endl;
					break;
			case 8: display(head);
					cout<<"At what Position would you Insert the Element: (0 to Insert before the first elemnt)"<<endl;
					cin>>n;
					head=InsertNode(head,n);
					display(head);
					break;
			case 9:	cout<<"Enter Position to be deleted:"<<endl;
					cin>>n;
					head=DeleteNode(head,n);
					display(head);
					break;
			case 10: c=SortedCheck(head);
					 if(c)
					 	cout<<"List is Sorted"<<endl;
					 else
					 	cout<<"List is not Sorted"<<endl;
					 break;
			case 11: head=ReverseList(head);
					 break; 
			case 12: exit(1);
			default: cout<<"-----Invalid Option-----"<<endl;
		}
	}
}	

