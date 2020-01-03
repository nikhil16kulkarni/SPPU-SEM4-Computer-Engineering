//============================================================================
// Name        : Ass1.cpp
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
//	friend class Tree;
	friend class queue;
	friend class stack;
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


class queue
{
  Node* d[20];
  int front,rear;
  public:
  queue()
  {
  	front=rear=-1;
  }

  void push(Node* temp)
  {
  	if(front==-1)
  	{
  		front=0;

	 }
	  rear++;
	  d[rear]=temp;
  }

  Node* pop()
  {
  	Node* temp;
  	if(front==-1)
  	  cout<<"Queue is empty ";

  	else
    {
      temp=d[front];
      if(front==rear)
      {
      	front=rear=-1;
	  }
	  else
	  front++;

	}
  	return temp;
  }

  int isempty()
  {
	if(front==-1)
 	return 1;
 	else
 	return 0;
  }

  Node* first()
  {
	return d[front];
  }

  void pop1()
  {
  	front++;
  }
};

class stack
{
	int top;
	Node* s[20];
public:
	stack()
    {
		top=-1;
    }
	void push(Node* temp)
	{
    	s[++top]=temp;
	}
	Node* pop()
	{
		Node* t;
		if(top==-1){
			cout<<"\nStack is empty ";
		return NULL;}
		else
		{
			t=s[top];
			top=top-1;
			return t;
		}
	}
	int isempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

};


class Tree{
	Node *root;
public:
	Tree(){
		root=NULL;
	}
	void createnr();//Non-Recursive(Not Completed)
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
	int equality(Node*,Node*);
	void mirror(Node*);
	void internalnodes();
	void leafnodes(Node*);


};



void Tree::deletenode(Node *p){
	if(p!=NULL){
		deletenode(p->lchild);
		deletenode(p->rchild);
		delete(p);
	}
}


/*void Tree::createnr(){
		queue q;
		Node* t;
		int x;
		cout<<"\nEnter root ";
		cin>>x;
		root=new Node(x);
		q.push(root);

		while(!q.isempty())
		{
		 t=q.pop();
		 	cout<<"Enter left data of  "<<t->data<<" or -1 for exit ";
		 	cin>>x;
		 	if(x!=-1)
		 	{
		 		t->lchild=new Node(x);
		 		q.push(t->lchild);
			 }
			cout<<"Enter right data of  "<<t->data<<" or -1 for exit ";
			cin>>x;
			if(x!=-1)
			{
				t->rchild=new Node(x);
		 		q.push(t->rchild);
			}
		}
}*/

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


/*void Tree::inordernr(Node* t){
	stack a;
		Node* p=root;

		while(1)
		{
			while(p!=NULL)
			{
				a.push(p);
				p=p->lchild;
			}
			if(a.isempty())
			   return;
			p=a.pop();
			cout<<p->data<<"\t";
			p=p->rchild;
		}
}

void Tree::preordernr(Node* t){
	stack a;
		Node* p=root;
		while(1)
		{
			while(p!=NULL)
	        {
				cout<<p->data<<"\t";
				if(p->rchild!=NULL)
				  a.push(p->rchild);

	            p=p->lchild;
	        }
			if(a.isempty())
				return;
			p=a.pop();
		}
}

void Tree::postordernr(Node* t){
		stack a;
		stack b;
		Node* p=root;
		Node *k,*l;
		a.push(p);
		while(!a.isempty())
		{
			k=a.pop();
			b.push(k);
			if(k->lchild!=NULL)
				a.push(k->lchild);
			if(k->rchild!=NULL)
				a.push(k->rchild);
		}
		while(!b.isempty())
		{
			l=b.pop();
			cout<<l->data<<"\t";
	    }
}*/

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

void Tree::leafnodes(Node* p)
{

	if(!p)
	 return;
	if(!p->lchild && !p->rchild)
	{
		cout<<p->data<<" ";
		return;
	}
	if(p->lchild)
	 leafnodes(p->lchild);
	if(p->rchild)
	 leafnodes(p->rchild);
}
/*void Tree::internalnodes()
{
	queue q;
	q.push(root);
	bool flag;
	while(!q.isempty())
	{
	  Node* p=q.first();
	  q.pop1();
	  flag=0;
	  if(p->lchild)
	  {
	  	flag=1;
	  	q.push(p->lchild);
	  }
	  if(p->rchild)
	  {
	  	flag=1;
	  	q.push(p->rchild);
	  }
	   if(flag==1)
	    cout<<p->data<<" ";
	}

}*/


void Tree::mirror(Node* p)
{
	if(p==NULL)
	    return;
	else
	{
	 	Node* temp;
	 	mirror(p->lchild);
	 	mirror(p->rchild);
	 	temp=p->lchild;
	 	p->lchild=p->rchild;
	 	p->rchild=temp;
	}
}


int Tree::equality(Node* p,Node* q)
{
	if(p==NULL && q==NULL)
	return 1;
	if(p!=NULL && q!=NULL)
    	return (p->data==q->data  && equality(p->lchild,q->lchild) && equality(p->rchild,q->rchild));
	return 0;
}


/*Node* Tree::copy(Node* t)
{
	Node* temp;
	temp=NULL;
	if(t!=NULL)
			{
				temp=new Node(t->data);
				temp->lchild=copy(t->lchild);
				temp->rchild=copy(t->rchild);
			}
	return temp;
}
void Tree::operator = (Tree t)
{
	root=copy(t.root);
}*/


int main() {
	int a;
	char yn;
	Tree t,t1,obj,obj1,obj2;
	Node *l,*p;
//	Node* p=new Node();
	do{

		cout<<"1.Enter Tree Recursive\n2.Enter Tree Non-Recursive\n9.Delete All Nodes\n10.Copy the given tree\n11.Find Mirror Image\n12.Find Leaf Nodes\n13.Find Internal Nodes\n14.Check if given tree is equal or not";
		cin>>a;
		switch(a){
		case 1: t.set_root();
				p=t.get_root();
				t.inorderr(p);
				t.preorderr(p);
				t.postorderr(p);
				break;
		/*case 2: p=t.get_root();
				t.inorderr(p);
				break;
		case 3: p=t.get_root();
				t.preorderr(p);
				break;
		case 4: p=t.get_root();
				t.postorderr(p);
				break;*/
		/*case 2:	t.createnr();
				t.inordernr(p);
				t.preordernr(p);
				t.postordernr(p);
				break;*/
	/*	case 6:	t.inordernr(p);
				break;
		case 7: t.preordernr(p);
				break;
		case 8: t.postordernr(p);
				break;*/
		case 9: cout<<"Deleting all the nodes\n";
				t.deletenode(p);
				break;
		case 10:cout<<"Copying.....\n";
				t1=t;
				cout<<"Tree Copied\nNow Printing the copied Tree using Inorder Traversal\n";
				t1.inorderr(p);
				break;
		case 11:cout<<"Mirror Image";
				p=obj.get_root();
				obj.mirror(p);
				cout<<"\nInorder traversal of mirror image of tree ";
				obj.inorderr(p);
				break;
		case 12:cout<<"Find Leaf Nodes";
				p=obj.get_root();
				obj.leafnodes(p);
				cout<<endl;
				break;
	/*	case 13:cout<<"Find Internal Nodes";
				p=obj.get_root();
				obj.internalnodes(p);
				break;*/
		case 14:l=obj.get_root();
				p=obj1.get_root();
				if(obj2.equality(l,p))
					cout<<"\nBoth trees are equal ";
				else
					cout<<"\nBoth trees are not equal ";
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
