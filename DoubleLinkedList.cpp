#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef struct Node{
	int data;
	Node *left;
	Node *right;
};

Node* CreateNode(Node *head){
	Node *temp,*p;
	cout<<"Enter data"<<endl;
	temp=(Node*)malloc(sizeof(Node));
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	
	if(head==NULL)
		head=temp;
	else{
		p=head;
		while(p->right!=NULL)
			p=p->right;
		p->right=temp;
		temp->left=p;
	}
	return head;
}
void NodeDisplay(Node *head){
 	Node *p=head;
 	cout<<"---Display---"<<endl;
 	while(p!=NULL){
 		cout<<p->data<<endl;
 		p=p->right;
	 }
}


int CountNode(struct Node *p){
	int c=0;
	while(p!=NULL){
		c++;
		p=p->right;
	}
	return c;
}

int SumNodes(struct Node *p){
	int c=0;
	while(p!=NULL){
		c+=p->data;
		p=p->right;
	}
	return c;
}

Node* InsertAtBegin(struct Node *head){
	Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	cout<<"Enter data"<<endl;
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(head==NULL)
		head=temp;
	else{
		temp->right=head;
		head->left=temp;
		head=temp;
	}
	return head;
}

void AddNodeAfter(Node *head){
	Node *temp,*p,*q;
	int loc,i=1;
	cout<<"Enter location"<<endl;
	cin>>loc;
	if(loc > CountNode(head))
		cout<<"Invalid Input"<<endl;
	else{
		temp=(Node*)malloc(sizeof(Node));
		cout<<"Enter element:"<<endl;
		cin>>temp->data;
		temp->left=NULL;
		temp->right=NULL;
		p=head;
		while(i<CountNode(head)-1){
			p=p->right;
			i++;
		}
		q=p->right;
		temp->right=q;
		q->left=temp;
		temp->left=p;	
		p->right=temp;
	}
}

int main(){
	Node *head=NULL;
	while(1){
		cout<<"Enter choice:"<<endl<<"1. Append"<<endl<<"2. Display"<<endl<<"3. Count Nodes"<<endl<<"4. Sum of Nodes"<<endl;
		cout<<"5. Insert element at Beginning"<<endl<<"6. Add node after"<<endl<<"7. Exit"<<endl;
		int ch,c=0,n=0;
		cin>>ch;
		switch(ch){
			case 1: head=CreateNode(head);
					break;
			case 2: NodeDisplay(head);
					break;
			case 3: c=CountNode(head);
					cout<<endl<<"Number of Nodes: "<<c<<endl;
					break;
			case 4: c=SumNodes(head);
					cout<<"Sum of all elements: "<<c<<endl;
					break;
			case 5: NodeDisplay(head);
					head=InsertAtBegin(head);
					NodeDisplay(head);
					break;
			case 6: AddNodeAfter(head);
					NodeDisplay(head);
					break;
			case 7: exit(1);
			default: cout<<endl<<"Invalid input"<<endl;
		}
	}
}

