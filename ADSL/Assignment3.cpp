//============================================================================
// Name        : Assignment3.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Node{
	int data;
	Node *left;
	Node *right;
	bool rightThread, leftThread;
	friend class tbt;
public:
	Node(){
		data=0;
		left=right=NULL;
		rightThread=leftThread=false;
	}

	Node(int x){
		data=x;
		left=right=NULL;
		rightThread=leftThread=false;
	}

	friend class tbt;
	friend class queue;
};


class tbt{

public:
	Node* root;
	Node* head;

	tbt(){
		head=root=NULL;
	}

	void insert(int);
	void inorder();
	void preorder();
};

void tbt::insert(int x){
	Node *temp, *ptr;
	if(root==NULL)
			{
				head=new Node(-99);
				head->right=head;
				root=new Node(x);
				head->leftThread=1;
				head->left=root;
				root->left=root->right=head;
			}
			else
			{
				ptr=root;
				while(1)
				{
					if(ptr->data>x)
					{
						if(ptr->leftThread!=0)
							ptr=ptr->left;
						else
						{
							temp=new Node(x);
							ptr->leftThread=1;
							temp->left=ptr->left;
							temp->right=ptr;
							ptr->left=temp;
						    return;
						}
					}
					else if(ptr->data<x)
					{
					    if(ptr->rightThread!=0)
							ptr=ptr->right;
					    else
					    {
					       temp=new Node(x);
					       ptr->rightThread=1;
					       temp->left=ptr;
					       temp->right=ptr->right;
					       ptr->right=temp;
					       return;
					    }
					}
					else
					{
						cout<<"\nData is already present ";
					    break;
					}
				}
			}
}


void tbt::inorder(){
	Node* t=root;
		while(t->leftThread)
		{
			t=t->left;
		}
		while(t!=head)
		{
			cout<<t->data<<"\t";
			if(t->rightThread)
			{
				t=t->right;
				while(t->leftThread)
				{
					t=t->left;
				}
			}
			else
			{
				t=t->right;
			}
		}
}

void tbt::preorder(){
	Node* t=head->left;
		while(1)
		{
			if(t==head)
			{
				return ;
			}
			cout<<t->data<<"\t";
			if(t->leftThread)
			{
				t=t->left;
			}
			else
			{
				if(t->rightThread)
				{
					t=t->right;
				}
				else
				{
					while(t->rightThread==false&&t!=head)
					{
						t=t->right;
					}
					t=t->right;
				}
			}
		}
}



int main() {
	tbt t;
	char ch;
		do
		{
			cout<<"Enter data: ";
			int a;
			cin>>a;
			t.insert(a);
			cout<<"Do you want to continue(y/n)??: ";
			cin>>ch;
		}while(ch=='y');

		cout<<"Inorder  : ";
		t.inorder();
		cout<<"\n";
		cout<<"Preorder: ";
		t.preorder();
}
