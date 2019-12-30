//============================================================================
// Name        : Assignment.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node* lchild;
	Node* rchild;
	friend class Tree;
public:
	Node(){
		data=0;
		lchild=rchild=NULL;
	}
	Node(int x){
		data=x;
		lchild=rchild=NULL;
	}

};


class Tree{
	Node *root;
public:
	Tree(){
		root=NULL;
	}
	//Node* createnr();//Non-Recursive(Not Completed)
	Node* creater();//Recursive
//	Node* insert(Node*);
	void inorderr(Node*);//Recursive
	void preorderr(Node*);//Recursive
	void postorderr(Node*);//Recursive
	Node* get_root();
	void set_root();
	void inordernr(Node*);//Non Recursive
	void preordernr(Node*);//Non Recursive
	void postordernr(Node*);//Non Recursive
	void deletenode(Node*);
	Node* copy(Node*);
	void operator=(Tree &);


};



void Tree::deletenode(Node *p){
	if(p!=NULL){
		deletenode(p->lchild);
		deletenode(p->rchild);
		delete(p);
	}
}


//Node* Tree::createnr(){
//	Node *p;
//	int x;
//	cout<<"Enter data else enter -1\n";
//	cin>>x;
//	if(x==-1){	return NULL;}
//	else{
//	if(root==NULL)	{
//		cout<<"Enter 1st root of tree"<<endl;
//		p=new Node(x);
//		root=p;
//	}
//	else{
//		cout<<"Tree root is already created. Now calling Insert function\n";
//		root=insert(root,x);
//	}}
//}

Node* Tree::creater(){
	int x;
	cout<<"Enter data else enter -1\n";
	cin>>x;
	if(x==-1){	return NULL;	}
	else{
		Node* p=new Node(x);
		p->data=x;
		cout<<"Enter data of left child of "<<x<<endl;;
		p->lchild=creater();
		cout<<"Enter data of right child of"<<x<<endl;
		p->rchild=creater();
		return p;
	}
}

void Tree::set_root(){
	root=creater();
}

Node* Tree::get_root(){
	return root;
}



//Node* Tree::insert(Node* t,int x){
//	Node* p;
//	int lr;
//	if(t==NULL){
//		p=new Node(x);
//		return p;
//	}
//	else{
//		cout<<"Where do you want to insert on left or right(l/r)\n";
//		cin>>lr;
//		if(lr=='l'||lr=='L')	t->lchild=insert(t->lchild,x);
//		else	t->rchild=insert(t->rchild,x);
//		return t;
//	}
//}

//Node* Tree::insert(Node* root)
//{
//    Node* p = new Node(x);
//    Node* r = root;
//    Node* y = NULL;
//
//    while (r != NULL) {
//
//        y = r;
//        if (x < r->x)
//            r = r->lchild;
//        else
//            r = r->rchild;
//    }
//
//
//    if (y == NULL)
//        y = new Node;
//
//    else if (x < y->x)
//        y->lchild = new Node;
//
//
//    else
//        y->rchild = new Node;
//
//
//    return y;
//}

void Tree::inorderr(Node* t){
	if(t!=NULL){
		inorderr(t->lchild);
		cout<<t->data<<"\t";
		inorderr(t-> rchild);
	}

}

void Tree::preorderr(Node* t){
	if(t!=NULL){
		cout<<t->data<<"\t";
		preorderr(t->lchild);
		preorderr(t->rchild);
	}
}

void Tree::postorderr(Node* t){
	if(t!=NULL){
		postorderr(t->lchild);
		postorderr(t->rchild);
		cout<<t->data<<"\t";
	}
}


void Tree::inordernr(Node* t){
	stack<Node *>s;
	Node* curr=t;
	while(curr!=NULL || !s.empty()){
		while(curr!=NULL){
			s.push(curr);
			curr=curr->lchild;
		}
		curr=s.top();
		s.pop();
		cout<<curr->data<<"\t";
		curr=curr->rchild;
	}
}

void Tree::preordernr(Node* t){
	if(t==NULL)		return;
	stack<Node *>s;
	s.push(t);
	while(!s.empty()){
		Node* curr=s.top();
		cout<<curr->data<<"\t";
		s.pop();
		if(curr->rchild)	s.push(curr->rchild);
		if(curr->lchild)	s.push(curr->lchild);
	}
}

void Tree::postordernr(Node* t){
	if(t==NULL)		return;
	stack<Node *>s1;
	Node* curr;
	s1.push(t);
	stack<Node *>s2;
	while(!s1.empty()){
		curr=s1.top();
		s1.pop();
		s2.push(s1.top());

		if(curr->lchild)
			s1.push(curr->lchild);
		if(curr->rchild)
			s1.push(curr->rchild);
	}
	while(!s2.empty()){
		cout<<s2.top()<<"\t";
		s2.pop();
	}
}

Node* Tree::copy(Node*t){
	Node* n;
	n=NULL;
	if(t!=NULL){
		n=new Node(t->data);
		n->lchild=copy(t->lchild);
		n->rchild=copy(t->rchild);
	}
	return n;
}

void Tree::operator=(Tree &t){
	root=copy(t.root);
}



int main() {
	int a;
	char yn;
	Tree t,t1;
	Node* p=new Node();
	do{

		cout<<"1.Enter Tree Recursive\n2.Recursive Inorder Traversal\n3.Recursive Preorder Traversal\n4.Recursive Postorder Traversal\n5.Enter Tree Non-Recursive\n6.Non Recursive Inorder\n7.Non Recursive Preorder\n8.Non Recursive Postorder\n9.Delete All Nodes";
		cin>>a;
		switch(a){
		case 1: t.set_root();
				break;
		case 2: p=t.get_root();
				t.inorderr(p);
				break;
		case 3: p=t.get_root();
				t.preorderr(p);
				break;
		case 4: p=t.get_root();
				t.postorderr(p);
				break;
//		case 5:	t.createnr();
//				break;
		case 6:	t.inordernr(p);
				break;
		case 7: t.preordernr(p);
				break;
		case 8: t.postordernr(p);
				break;
		case 9: cout<<"Deleting all the nodes\n";
				t.deletenode(p);
				break;
		case 10:cout<<"Copying.....\n";
				t1=t;
				cout<<"Tree Copied\nNow Printing the copied Tree using Inorder Traversal\n";
				t1.inorderr(p);
				break;
		case 11:cout<<"Mirror Image";
				break;
		case 12:cout<<"Find Leaf Nodes";
				break;
		case 13:cout<<"Find Internal Nodes";
				break;
		}
		cout<<"\nDo you want to continue(y/n)?        ";
		cin>>yn;
	}while(yn=='y'||yn=='Y');
}

/*  INORDER NON-RECURSIVE ALGO

           1
          / \
         2   3
        / \
       4   5

Step 1 Creates an empty stack: S = NULL

Step 2 sets current as address of root: current -> 1

Step 3 Pushes the current node and set current = current->left until current is NULL
     current -> 1
     push 1: Stack S -> 1
     current -> 2
     push 2: Stack S -> 2, 1
     current -> 4
     push 4: Stack S -> 4, 2, 1
     current = NULL

Step 4 pops from S
     a) Pop 4: Stack S -> 2, 1
     b) print "4"
     c) current = NULL (right of 4) and go to step 3
Since current is NULL step 3 doesn't do anything.

Step 4 pops again.
     a) Pop 2: Stack S -> 1
     b) print "2"
     c) current -> 5 (right of 2)  and go to step 3

Step 3 pushes 5 to stack and makes current NULL
     Stack S -> 5, 1
     current = NULL

Step 4 pops from S
     a) Pop 5: Stack S -> 1
     b) print "5"
     c) current = NULL (right of 5)  and go to step 3
Since current is NULL step 3 doesn't do anything

Step 4 pops again.
     a) Pop 1: Stack S -> NULL
     b) print "1"
     c) current -> 3 (right of 5)

Step 3 pushes 3 to stack and makes current NULL
     Stack S -> 3
     current = NULL

Step 4 pops from S
     a) Pop 3: Stack S -> NULL
     b) print "3"
     c) current = NULL (right of 3)

Traversal is done now as stack S is empty and current is NULL.
*/







/* PREORDER NON-RECURSIVE ALGO
 	 1) Create an empty stack nodeStack and push root node to stack.
	 2) Do following while nodeStack is not empty.
	  ….a) Pop an item from stack and print it.
      ….b) Push right child of popped item to stack
      ….c) Push left child of popped item to stack
 */

/* POSTORDER NON-RECURSIVE ALGO
 *
 *
 */
