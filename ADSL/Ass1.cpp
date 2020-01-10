//============================================================================
// Name        : Ass1.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Node{
	int data;
	Node* lchild;
	Node* rchild;
	friend class Tree;
//	friend class Tree;
	friend class Queue;
	friend class Stack;
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


class Stack
{
	int top;
	Node *data[MAX];
	public:
	Stack()
	{	top=-1;	}
	void push(Node *p)
	{
		if(!full())
			data[++top]=p;
		else
			cout<<"Full\n";
	}
	Node *pop()
	{
		if(!empty())
			return data[top--];
		else
			return NULL;
	}
	bool empty()
	{
		if(top==-1)
			return true;
		return false;
	}
	bool full()
	{
		if(top==MAX-1)
			return true;
		return false;
	}
};
class Queue
{
	Node *data[MAX];
	int front,rear;
public:
	Queue()
	{
		front=rear=-1;
	}
	void push(Node*);
	Node * pop();
	bool empty();
	bool full();
	Node* first();
};
void Queue::push(Node *p)
{
	if(!full())
	{
		if(empty())
		{
			front=0;
		}
		rear=(rear+1)%MAX;
		data[rear]=p;
	}
}
Node * Queue::pop()
{
	if(!empty())
	{
		Node *p=data[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX;
		}
		return p;
	}
	else
		return NULL;
}
bool Queue::empty()
{
	if(rear==-1)
		return 1;
	return 0;
}
bool Queue::full()
{
	if(front==(rear+1)%MAX)
		return 1;
	return 0;
}

Node* Queue::first()
  {
	return data[front];
  }


class Tree{
	Node *root;
public:
	Tree(){
		root=NULL;
	}
	void createnr();//Non-Recursive(Not Completed) ----> Completed
	Node* creater();//Recursive
//	Node* insert(Node*);
	void inorderr(Node*);//Recursive
	void preorderr(Node*);//Recursive
	void postorderr(Node*);//Recursive
	Node* get_root();
	void set_root();
	void inordernr();//Non Recursive
	void preordernr();//Non Recursive
	void postordernr();//Non Recursive
	void deletenode(Node*);
	Node* copy(Node*);
	void operator=(Tree &);
	int equality(Node*,Node*);//Not Completed ----> Completed
	void create_mirror(Tree);
	Node* mirror(Node*,Node*);
	int internalnodes(Node*);//Not Completed ----> Completed
	int leafnodes(Node*);//Not Completed ----> Completed
	void print();//Not Completed ----> Completed


};



void Tree::deletenode(Node *p){
	if(p!=NULL){
		deletenode(p->lchild);
		deletenode(p->rchild);
		delete(p);
	}
}

void Tree::createnr()
{
	Queue obj;
	Node *p=NULL;
	int x;
	if(root==NULL)
	{
		cout<<"Enter Data or -1 to STOP\n";
		cin>>x;
		if(x==-1)
			return;
		root=new Node(x);
		obj.push(root);
	}
	p=root;
	while(!obj.empty())
	{
		p=obj.pop();
		cout<<"Enter Left of "<<p->data<<" OR -1 \n";
		cin>>x;
		if(x!=-1)
		{
			p->lchild=new Node(x);
			obj.push(p->lchild);
		}
		cout<<"Enter Right of "<<p->data<<" OR -1 \n";
		cin>>x;
		if(x!=-1)
		{
			p->rchild=new Node(x);
			obj.push(p->rchild);
		}
	}//end of while
}

void Tree::preordernr()
{
	cout<<"PREORDER TRAVERSAL\n";
	Stack S;
	Node *p=root;
	S.push(p);
	while(!S.empty())
	{
		p=S.pop();
		cout<<p->data<<"\t";
		if(p->rchild!=NULL)
			S.push(p->rchild);
		if(p->lchild!=NULL)
			S.push(p->lchild);
	}
	cout<<"\n";
}


void Tree::inordernr()
{
	cout<<"INORDER TRAVERSAL\n";
	Stack S;
	Node *p=root;
	while(p!=NULL)
	{
		S.push(p);
		p=p->lchild;
	}
	while(!S.empty())
	{
		p=S.pop();
		cout<<p->data<<"\t";
		p=p->rchild;
		while(p!=NULL)
		{
			S.push(p);
			p=p->lchild;
		}
	}
	cout<<"\n";
}


void Tree::postordernr()
{
	cout<<"POSTORDER TRAVERSAL\n";
	Stack S1,S2;
	Node *p=root;
	S1.push(p);
	while(!S1.empty())
	{
		p=S1.pop();
		S2.push(p);
		if(p->lchild!=NULL)
			S1.push(p->lchild);
		if(p->rchild!=NULL)
			S1.push(p->rchild);
	}
	while(!S2.empty())
	{
		p=S2.pop();
		cout<<p->data<<"\t";
	}
	cout<<"\n";
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

/*void Tree::leafnodes(Node* p)
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
}*/


void Tree::print(){
    int c;
	cout<<"Internal Nodes is/are\n";
	c=internalnodes(root);
	cout<<"\nNo.of Internal Nodes is/are "<<c<<"\n";
	cout<<"\nLeaf Nodes is/are\n";
	c=leafnodes(root);
	cout<<"\nNo.of Leaf Nodes is/are "<<c<<"\n";
}

int Tree::internalnodes(Node* p)
{   //cout<<"Internal Nodes are\n";
	if(p==NULL)
		return 0;
	if(p->lchild==NULL&&p->rchild==NULL)
		return 0;
	else
	{
		int l,r;
		cout<<p->data<<" ";
		l=internalnodes(p->lchild);
		r=internalnodes(p->rchild);
		return 1+l+r;
	}
}

int Tree::leafnodes(Node* p){
    if(p==NULL)
		return 0;
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		cout<<p->data<<" ";
		return 1;
	}
	else
	{
		return leafnodes(p->lchild)+leafnodes(p->rchild);
	}
}

void Tree::create_mirror(Tree T)
{
	root=mirror(root,T.root);
}



Node* Tree::mirror(Node* p,Node *q)
{
	if(q==NULL)
		return NULL;
	else
	{
		p=new Node(q->data);
		p->lchild=mirror(p->lchild,q->rchild);
		p->rchild=mirror(p->rchild,q->lchild);
		return p;
	}
}


int Tree::equality(Node* p,Node* q)
{
	if(q==NULL&&p==NULL)
		{
			return true;
		}
		if(p==NULL||q==NULL)
		{
			return false;
		 }
		 Queue q1,q2;
		 q1.push(q);
		 q2.push(p);
		 while(!q1.empty()&&!q2.empty())
		 {
		 	Node* n1=q1.first();
		 	Node* n2=q2.first();
		 	if(n1->data!=n2->data)
		 	{
		 		return false;
			 }
			 q1.pop();
			 q2.pop();
			 if(n1->lchild&&n2->lchild)
			 {
			 	q1.push(n1->lchild);
			 	q2.push(n2->lchild);
			 }
			 else if(n1->lchild||n2->lchild)
			{
				return false;
			}
			if(n1->rchild&&n2->rchild)
	        {
	            q1.push(n1->rchild);
	            q2.push(n2->rchild);
	        }
	        else if(n1->rchild||n2->rchild)
	        {
			    return false;
			}

		 }
		 return true;
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
	Tree t,t1,obj,obj1,obj2,Mir;
	Node *l,*p;
//	Node* p=new Node();
	do{

		cout<<"1.Enter Tree Recursive\n2.Enter Tree Non-Recursive\n3.Delete All Nodes\n4.Copy the given tree\n5.Find Mirror Image\n6.Find Internal & Leaf Nodes\n7.Check if given tree is equal or not\n";
		cin>>a;
		switch(a){
		case 1: t.set_root();
				p=t.get_root();
				cout<<"Inorder Traversal :"<<endl;
				t.inorderr(p);
				cout<<endl;
				cout<<"Preorder Traversal :"<<endl;
				t.preorderr(p);
				cout<<endl;
				cout<<"Postorder Traversal :"<<endl;
				t.postorderr(p);
				cout<<endl;
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
		case 2:	t.createnr();
				t.inordernr();
				t.preordernr();
				t.postordernr();
				break;
	/*	case 6:	t.inordernr(p);
				break;
		case 7: t.preordernr(p);
				break;
		case 8: t.postordernr(p);
				break;		*/
		case 3: cout<<"Deleting all the nodes\n";
				t.deletenode(p);
				break;
		case 4:cout<<"Copying.....\n";
				t1=t;
				cout<<"Tree Copied\nNow Printing the copied Tree using Inorder Traversal\n";
				t1.inorderr(p);
				break;
		case 5:
			    cout<<"Mirror Image of Tree is\n";
			    Mir.create_mirror(t);
			    Mir.inordernr();
				Mir.preordernr();
				Mir.postordernr();
			    break;
	/*	case 6:cout<<"Find Leaf Nodes";
				p=obj.get_root();
				obj.leafnodes(p);
				cout<<endl;
				break;		*/
		case 6://cout<<"Find Internal Nodes";
				p=t.get_root();
				t.print();
				break;
		case 7: cout<<"Enter First Tree\n";
				obj.set_root();
				l=obj.get_root();
				cout<<"Enter Second Tree\n";
				obj1.set_root();
				p=obj1.get_root();
				if(obj2.equality(l,p))
					cout<<"\nBoth trees are equal ";
				else
					cout<<"\nBoth trees are not equal ";
		        break;
		default: cout<<"Incorrect choice entered :\n";
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
 1.1 Create an empty stack
 2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
 2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child 
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
 2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
 */
