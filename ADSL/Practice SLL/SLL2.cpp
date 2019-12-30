//============================================================================
// Name        : SLL2.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class node{
	int data;
	node* next;
	friend class list;
};

class list{
public:
	node* head;
	list(){
		head=NULL;
	}
	void insert_beg(int);
	void insert_pos(int,int);
	void insert_end(int);
	void insert_bef(int,int);
	void insert_aft(int,int);
	void delete_beg();
	void delete_pos(int);
	void delete_end();
	void delete_val(int x);
	void sort();
	void print();
	void reverse();
	void modify(int,int);
	void search(int);
	void concat(list,list);
};

void list::print(){
	if(head==NULL)
		cout<<"list is empty";
	else{
		cout<<"elements in list are\n";
		node* t=head;
		while(t!=NULL){
			cout<<t->data<<" ";
			t=t->next;
		}
	}
}

void list::insert_beg(int x){
	if(head==NULL){
	head=new node;
	head->data=x;
	}

	else{
		node* t=new node;
		t->data=x;
		t->next=head;
		head=t;
	}
}

void list::insert_end(int x){
	if(head==NULL){
		head=new node;
		head->data=x;
	}
	else{
		node* t=head;
		while(t->next!=NULL){
			t=t->next;
		}
		t->next=new node;
		t->next->data=x;
		t->next->next=NULL;
	}
}

void list::insert_pos(int x,int n){
	node* t=head;
	while((n-1)!=1){
		t=t->next;
		n--;
	}
	node* temp= new node;
	temp->data=x;
	temp->next=t->next;
	t->next=temp;
}

void list::insert_bef(int x1,int x){
	if(head==NULL){
		head=new node;
		head->data=x;
		}
	else{
		node* t=new node;
		t->data=x1;
		node *s=head;
		while(s->data==t->data){
			s=s->next;
		}
		node* temp=new node;
		temp->data=x;
		temp->next=s->next;
		s->next=temp;

	}
}

void list::insert_aft(int x1,int x){
	if(head==NULL){
			head=new node;
			head->data=x;
			}
		else{
			node* t=new node;
			t->data=x1;
			node *s=head;
			while(s->data!=t->data){
				s=s->next;
			}
			node* temp=new node;
			temp->data=x;
			temp->next=s->next;
			s->next=temp;

		}
}

void list::delete_beg(){
	node* t=head;
	head=head->next;
	t->next=NULL;
	delete t;
	t=NULL;
}

void list::delete_end(){
	node* t1=head;
	node* t2=NULL;
	while(t1->next!=NULL){
		t2=t1;
		t1=t1->next;
	}
	t2->next=NULL;
	delete t1;
	t1=NULL;
}

void list::delete_pos(int n){
	node* t1=head;
	node* t2=NULL;
	while(n!=1){
		t2=t1;
		t1=t1->next;
		n--;
	}
	t2->next=t1->next;
	t1->next=NULL;
	delete t1;
	t1=NULL;
}

void list::delete_val(int x){
	node* t1=head;
	//node* t2=new node;
	//t2->data=x;
	node* t3=NULL;

	while(t1->data!=x){
		t3=t1;
		t1=t1->next;
	}
	t3->next=t1->next;
	t1->next=NULL;
	delete t1;
	//t1=NULL;

}

void list::modify(int x,int x1){
	node* t1=head;
	while(t1->data!=x){
		t1=t1->next;
	}
	t1->data=x1;
}

void list::search(int x){
	node* t1=head;
	int cnt=1;
	while(t1->data!=x){
			t1=t1->next;
			cnt++;
	}
	cout<<"Element found at position "<<cnt<<endl;
}

void list::concat(list l, list l1){
	cout<<"Concatenated List is : \n";
	node* t=
}
/*void list::sort(){
	node* t1;
	node* t2;
	int temp;
	for(t1=head;t1->next!=NULL;t1=t1->next){
		for(t2=t1->next;t2!=NULL;t2=t2->next){
			if(t1->data>t2->data){
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
		}
	}
}*/

/*void list::reverse(){
	int i,c=0;
	node* t;
	for(t=head;t!=NULL;t=t->next){
		c++;
	}
	for(t=head,i=0;(t!=NULL)&&(i<(c/2));t=t->next,i++){
		node* t2=head;
		int n=c-i,count=1;
		int temp;
		while(count!=n){
			t2=t2->next;
			count++;
		}
		temp=t->data;
		t->data=t2->data;
		t2->data=temp;
	}
}*/



int main(){
	list l,l2,l3;
	int x,x1,s,pos;
	char yn;
	do{
		cout<<"\n1.Insert at beginning\n2.Insert at position\n3.Insert at end\n4.Delete at beginning\n5.Delete at position\n6.Delete at end\n7.Sort the linked list\n8.Reverse the linked list\n9.Display\n10.Insert before the element\n11.Insert after the element\n12.Delete by value\n13.Modify\n14.Search element\n";
		cin>>s;
		switch(s){
		case 1: cout<<"Enter element to be inserted \n";
				cin>>x;
				l.insert_beg(x);
				l.print();
				break;
		case 2: cout<<"Enter position at which element is to be inserted\n";
				cin>>pos;
				cout<<"Enter element\n";
				cin>>x;
				l.insert_pos(x,pos);
				l.print();
				break;
		case 3: cout<<"Enter element to be inserted\n";
				cin>>x;
				l.insert_end(x);
				l.print();
				break;
		case 4: cout<<"Deleting element at beginning\n";
				l.delete_beg();
				l.print();
				break;
		case 5: cout<<"Enter position at which element is to be deleted\n";
				cin>>pos;
				l.delete_pos(pos);
				l.print();
				break;
		case 6: cout<<"Deleting element at end\n";
				l.delete_end();
				l.print();
				break;
	/*	case 7: cout<<"Sorted linked list is\n";
				l.sort();
				l.print();
				break;
		case 8: cout<<"Reversed linked list is\n";
				l.reverse();
				l.print();
				break; */
		case 9: l.print();
				break;
		case 10: cout<<"Enter element before which new element is to be inserted\n";
				cin>>x1;
				cout<<"Enter new element\n";
				cin>>x;
				l.insert_bef(x1,x);
				l.print();
				break;
		case 11: cout<<"Enter element after which new element is to be inserted\n";
				cin>>x1;
				cout<<"Enter new element\n";
				cin>>x;
				l.insert_aft(x1,x);
				l.print();
				break;
		case 12: cout<<"Enter element which is to be deleted\n";
				cin>>x;
				cout<<"Deleting element "<<x<<endl;
				l.delete_val(x);
				l.print();
				break;
		case 13: cout<<"Enter value to be modified\n";
				cin>>x;
				cout<<"Enter modified value\n";
				cin>>x1;
				l.modify(x,x1);
				l.print();
				break;
		case 14: cout<<"Enter element to be searched\n";
				cin>>x;
				l.search(x);
				break;

		default: cout<<"Invalid Choice\n";
				break;
		}
		cout<<"\nDo you want to continue?(y/n)\n";
		cin>>yn;
	}while(yn=='y'||yn=='Y');
	int a,b;
	cout<<"Enter 2nd list :\n";
	cout<<"Enter no. of elements in list\n";
	cin>>a;
	for(int i=0;i<a;i++){
	cout<<"Enter element :\n";
	cin>>b;
	l2.insert_end(b);
	l2.print();}

}
