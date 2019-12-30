//============================================================================
// Name        : PracticeSLL.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
	int no;
	int pos;
	char name;
	node* next;
	friend class SLL;
};

class SLL{
	int size;
	node *start;
	node *curr;
public:
	SLL(){
		size=0;
		start=NULL;
		curr=NULL;
	}
	void InsertP(int pos,int no);
	void Delete(int no);
	void Display();
};


void SLL::InsertP(int pos, int no){
	//node *getNode = new node();

	if(pos<1||pos>size+1)
		cout << "Invalid position!" << endl;

	else{
		while(pos--){
			if(pos==0) { 	                node* temp = new node();
	                temp->next=curr;
	                curr=temp;
	            }
	            else
	            	curr=curr->next;
	        }
		size++;
	}
}

void SLL::Display(){
	node *p =start;
	while(p!=NULL){
		cout<<p->no<<"\t";
		p=p->next;
	}
}


int main() {
	SLL s;
	int x,loc;
	int data;
	char yn;
	do{
		cout<<"Enter Choice : \n1.Insert Data by Position\n2.Delete Data\n3.Display Linked List";
		cin>>x;
		switch(x){
		case 1: cout<<"Enter location & number to be inserted : ";
				cin>>loc>>data;
				s.InsertP(loc, data);
				break;
		case 3: s.Display();
				break;
		}
		cout<<"Do you want to continue?(y/n)";
		cin>>yn;
		}while(yn=='y');
	return 0;
}
