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
