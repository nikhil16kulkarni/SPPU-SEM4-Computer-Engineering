//============================================================================
// Name        : Assignment2.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class Node
{
 public:
 char k[20];
 char m[20];
 class Node  *left;
 class Node * right;
 friend class dictionary;

 public:
 Node(){
	 //k={};
	 //m={};
	 left=right=NULL;
 }

 Node(char kw[],char mn[]){
	 strcpy(k,kw);
	 strcpy(m,mn);
	 left=right=NULL;
 }
};

class dictionary
{


public:

	Node *root;


 dictionary(){
	 root=NULL;
 }

 void create();
 void displaya(Node*);
 void displayd(Node*);
 void insert(Node*,Node*);
 int search(Node*,char []);
 int update(Node*,char []);
 Node* del(Node*,char []);
 Node* min(Node*);
 Node* copy(Node*);
 void operator=(dictionary);


};

void dictionary::create()
{
 Node *temp;
 char ch;

 do
 {
  temp = new Node;

  cout<<"\nEnter Keyword:";
  cin>>temp->k;

  cout<<"\nEnter Meaning:";
  cin>>temp->m;

  temp->left=NULL;
  temp->right=NULL;

  if(root==NULL)
  {
   root=temp;
  }
  else
  {
   insert(root, temp);
  }

  cout<<"\nDo you want to add more keywords?(y/n):";
  cin>>ch;

 }
 while(ch=='y'||ch=='Y');

}

void dictionary::insert(Node* root,Node* temp)
{
if(strcmp(temp->k,root->k)==0){
		cout<<"KeyWord is already present in dictionary\n\n";
		return;
	}
else if(strcmp(temp->k,root->k)<0)
 {
   if(root->left==NULL)
   root->left=temp;
   else
   insert(root->left,temp);
 }
else{
	if(root->right == NULL)
    root->right = temp;
   else
   insert(root->right,temp);
 }

}

void dictionary::displaya(Node* root)
{

 if(root!=NULL)
 {
  displaya(root->left);
  cout<<"\n KeyWord :"<<root->k;
  cout<<"\t Meaning :"<<root->m;
  displaya(root->right);
 }

}

void dictionary::displayd(Node* root){
 if(root!=NULL)
  {
   displayd(root->right);
   cout<<"\n KeyWord :"<<root->k;
   cout<<"\t Meaning :"<<root->m;
   displayd(root->left);
  }

}

int dictionary::search(Node* root,char k[20])
{
 int c=0;

 while(root!=NULL)
 {
  c++;
  if(strcmp(k,root->k)==0)
  {
   cout<<"\nNo of Comparisons are:"<<c;
   return 1;
  }

  if(strcmp(k,root->k)<0)
   root=root->left;

  if(strcmp(k,root->k)>0)
   root = root->right;
 }

 return -1;
}


int dictionary::update(Node * root,char k[20])
{
 while(root!=NULL)
 {
  if(strcmp(k,root->k) == 0)
  {
   cout<<"\nEnter New Meaning of Keyword  "<<root->k;
   cin>>root->m;
   return 1;
  }
  if(strcmp (k,root->k) < 0)
   root=root->left;
  if(strcmp(k, root->k) > 0)
   root=root->right;
 }
 return -1;
}


Node* dictionary::del(Node * root,char k[20])
{
 Node *temp;


 if(root==NULL)
 {
  cout<<"\nElement Not Found";
  return root;
 }


 if(strcmp(k,root->k)<0)
 {
  root->left=del(root->left,k);
  return root;
 }



 if(strcmp(k,root->k)>0)
 {
  root->right=del(root->right,k);
  return root;
 }



 if(root->right==NULL&&root->left==NULL)
 {
  temp = root;
  delete temp;
  return NULL;
 }


 if(root->right==NULL)
 {
  temp=root;
  root=root->left;
  delete temp;
  return root;
 }


 else if(root->left==NULL)
 {
  temp = root;
  root = root->right;
  delete temp;
  return root;
 }


 temp=min(root->right);
 strcpy(root->k,temp->k);
 root->right=del(root->right,temp->k);
 return root;

}

Node* dictionary::min(Node *q)
{
 while(q->left!=NULL)
 {
  q=q->left;
 }
 return q;
}

Node* dictionary::copy(Node* t){
	Node* temp;
	temp=NULL;
	if(t!=NULL){
		temp=new Node;
		temp->left=copy(t->left);
		temp->right=copy(t->right);
	}
	return temp;
}

void dictionary::operator=(dictionary t){
	root=copy(t.root);
}


int main()
{
 int ch;
 dictionary d,cp;
 d.root = NULL;


 do
 {
  cout<<"\n\n\n\nMenu\n1.Create\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Copy\nEnter your Choice:";
  cin>>ch;

  switch(ch)
  {
  	  case 1: d.create();
  	  	  	  break;


  	  case 2: if(d.root==NULL)
  	  	  	  {
  		  	  	  cout<<"\nNo any Keyword";
  	  	  	  }
  	  	  	  else
  	  	  	  {	cout<<"\nAscending Order : \n";
  	  	  		  d.displaya(d.root);
  	  	  		cout<<"\n\n\n\nDescending Order : \n";
  	  	  			d.displayd(d.root);
  	  	  	  }
  	  	  	  break;


  	  case 3: if(d.root==NULL)
  	  	  	  {
  		  	  cout<<"\nDictionary is Empty.Add some words before searching";
  	  	  	  }
  	  	  	  else
  	  	  	  {
  	  	  		  cout<<"\nEnter Keyword to be searched  :  ";
  	  		  	  char k[20];
  	  		  	  cin>>k;

  	  		  	  if( d.search(d.root,k)==1)
  	  		  		  cout<<"\nKeyword Found\n";
  	  		  	  else
  	  		  		  cout<<"\nKeyword Not Found\n";
  	  	  	  }
  	  	  	  break;

  	  case 4:
  		  	  if(d.root==NULL)
  		  	  {
  		  		  cout<<"\nDictionary is Empty.Add some words before modifying ";
  		  	  }
  		  	  else
  		  	  {
  		  		  cout<<"\nEnter Keyword whose meaning is to be updated :  ";
  		  		  char k[20];
  		  		  cin>>k;
  		  		  if(d.update(d.root,k)==1)
  		  			  cout<<"\nMeaning Updated ";
  		  		  else
  		  			  cout<<"\nKeyWord Not Found ";
  		  	  }
  		  	  break;
  	  case 5:
  		  	  if(d.root == NULL)
  		  	  {
  		  		  cout<<"\nDictionary is Empty.Add some words before deleting ";
  		  	  }
  		  	  else
  		  	  {
  		  		  cout<<"\nEnter Keyword to be deleted : ";
  		  		  char k[20];
  		  		  cin>>k;
  		  		  if(d.root==NULL)
  		  		  {
  		  			  cout<<"\nKeyWord not found";
  		  		  }
  		  		  else
  		  		  {
  		  			  d.root=d.del(d.root,k);
  		  			  cout<<"KeyWord deleted.....\n\n";
  		  		  }
  		  	  }
  		  	  break;

  	  case 6: cp=d;
  	  	  	  cout<<"Tree copied..... Now printing the copied tree\n\n";
  	  	  	  cp.displaya(cp.root);
  	  	  	  break;
  	  }
 }
 while(ch<=6);
 return 0;

}

*/

//============================================================================
// Name        : Assignment2.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class entry
{
	char *word;
	char *meaning;
	entry *lchild, *rchild;
public :
	entry()
{
		word=NULL;
		meaning=NULL;
		lchild=rchild=NULL;
}
	entry(char *w,char *m)
	{
		word=new char[strlen(w)+1];
		meaning=new char[strlen(m)+1];
		strcpy(word,w);
		strcpy(meaning,m);
		lchild=rchild=NULL;
	}
	char* get_meaning()
	{
		return meaning;
	}
	char* get_word()
	{
		return word;
	}
	friend class dictionary;
};
class dictionary
{
	entry *root;
public :
	dictionary()
{
		root=NULL;
}
	entry *get_root();
	void set_root(entry *);
	void create();
	void inorder(entry *);
	void descending(entry *);
	entry *search(char *w);
	void modify(char *w);
	void operator = (dictionary &);
	entry *copy(entry *);
	void del(entry *,entry *);
	void del_search(char []);
};
entry* dictionary::get_root()
{
	return root;
}
void dictionary::set_root(entry *t)
{
	root =t;
}
void dictionary::create()
{
	int n;
		cout<<"Enter the no of words\n";
		cin>>n;
		while(n--)
		{
			char w[20],m[20];
			cout<<"Enter the word and its meaning\n";
			cin>>w>>m;
			entry *temp=new entry(w,m);
			if(root==NULL)
				root=temp;
			else
			{
				entry *p,*q;
				p=root;
				q=NULL;
				while(p!=NULL)
				{
					q=p;
					if(strcmp(w,p->word)<0)
						p=p->lchild;
					else
						p=p->rchild;
				}
				if(strcmp(w,q->word)<0)
					q->lchild=temp;
				else if(strcmp(w,q->word)>0)
					q->rchild=temp;
				else
				{
					cout<<"Duplicate Data\n\n";
					delete temp;
				}
			}
		}
}
void dictionary::inorder(entry *p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		cout<<p->word<<" : "<<p->meaning<<endl;
		inorder(p->rchild);
	}
}
entry *dictionary::search(char *w)
{
	int c;
	int cnt=0;
	entry* curr = root;
	while(curr!=NULL)
	{
		cnt++;
		c = strcmp(w,(curr->word));
		if(c<0)
		{
			curr = curr->lchild;
		}
		else if(c>0)
		{
			curr = curr->rchild;
		}
		else if(c == 0)
		{
			cout<<"Word found\n";
			cout<<cnt<<"\n";
			return curr;
		}
		else
		{
			cout<<"Word not found\n";
			return NULL;
		}

	}
}
void dictionary::modify(char *w)
{
	char m[100];
	entry *p = search(w);
	if(p==NULL)
	{
		cout<<"Word Not Found\n";
		return;
	}
	else
	{
		cout<<"Entry the modified meaning of word\n";
		cin>>m;
		strcpy(p->meaning,m);
		cout<<"Modified word is:\n";
		cout<<p->word<<":"<<p->meaning<<"\n";
	}


}
void dictionary :: operator = (dictionary &t)
{
	root=copy(t.root);
}
entry* dictionary::copy(entry *t)
{
	if(t==NULL)
	{
		return NULL;
	}
	else
	{
		entry* temp = new entry(t->word,t->meaning);
		temp->lchild = copy(t->lchild);
		temp->rchild = copy(t->rchild);
		return temp;
	}
}
void dictionary::del_search(char w[])
{
	entry* p;
	entry* q;
	p=root;
	q=NULL;
	int found=0;
	while(p!=NULL&&found==0)
	{
		if(strcmp(p->word,w)==0)
		{
			del(q,p);
			found=1;
		}
		else
		{
			if(strcmp(p->word,w)<0)
			{
				q=p;
				p=p->rchild;
			}
			else
			{
				q=p;
				p=p->lchild;
			}
		}
	}

}
void dictionary::del(entry* p,entry* c)
{
	if(c->lchild!=NULL&&c->rchild!=NULL)
	{
		entry* c_s=c->rchild;
		p=c;
		while(c_s->lchild!=NULL)
		{
			p=c_s;
			c_s=c_s->lchild;

		}

		strcpy(c->word,c_s->word);
		strcpy(c->meaning,c_s->meaning);
		if(p->lchild==c_s)
		{
			p->lchild=NULL;
		}
		else
		{
			p->rchild=NULL;
		}
		c=c_s;
		delete(c);
	}
	if(c->lchild!=NULL&&c->rchild==NULL)
	{
		if(p->rchild==c)
		{
			p->rchild=c->lchild;
		}
		else
		{
			p->lchild=c->lchild;
		}
		delete(c);
	}

	if(c->lchild==NULL&&c->rchild!=NULL)
	{
		if(p->rchild==c)
		{
			p->rchild=c->lchild;
		}
		else
		{
			p->lchild=c->rchild;

		}
		delete(c);
	}
	if(c->lchild==NULL&&c->rchild==NULL)
		{

			if(p->rchild==c)
			{
				p->rchild=NULL;
			}
			else
			{
				p->rchild=NULL;
			}
			delete(c);
		}
}
int main()
{
	dictionary d1,d2;
	int x;
	char ch;
	do{
		char w[50];
		cout<<"Enter the choice\n1.create\n2.search\n3.modify\n4.copy\n5.delete\n6.exit\n";
		cin>>x;
		switch(x)
		{
		case 1:
			d1.create();
			d1.inorder(d1.get_root());
			break;
		case 2:
		{
			cout<<"Enter the word you want to search\n";
			cin>>w;
			entry *t = d1.search(w);
			if(t==NULL)
			{
				cout<<"Word not found\n";
			}
			else
				cout<<"Required word is:"<<t->get_word()<<": "<<t->get_meaning()<<"\n";
			break;
		}
		case 3:
		{
			cout<<"Enter the word you want to modify\n";
			cin>>w;
			d1.modify(w);
			break;
		}
		case 4:
		{	d2 =d1;
			d2.inorder(d2.get_root());
			break;
		}
		case 5:
		{	cout<<"Enter the word you want to delete\n";
			cin>>w;
			d1.del_search(w);
			d1.inorder(d1.get_root());
			break;
		}
		case 6:
			exit(-1);


		}
		cout<<"Do you want to continue(y/n)?";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}


