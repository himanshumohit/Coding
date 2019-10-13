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
	
	if(head==NULL){
		head=t1;
		t1->next=head;
	}
	else{
		p=head;
		while(p->next!=head)
			p=p->next;
		p->next=t1;
		t1->next=head;
	}
	return head;
}

void display(struct Node *head){
	struct Node *p=head;
	cout<<"Display: "<<endl;
	do{
		cout<<p->data<<endl;
		p=p->next;
	}while(p!=head);
}

int main(){
	struct Node *head=NULL;
	while(1){
		cout<<"______________________________________________"<<endl;
		cout<<"Choose: "<<endl<<"1. Add an Element"<<endl<<"2. Display "<<endl<<"3.Exit"<<endl;
		cout<<"______________________________________________"<<endl;
		int ch;
		cin>>ch;
		switch(ch){
			case 1: head=create(head);
					break;
			case 2: display(head);
					break;
			case 3: exit(1);
			default: cout<<"-----Invalid Option-----"<<endl;
		}
	}
}	

