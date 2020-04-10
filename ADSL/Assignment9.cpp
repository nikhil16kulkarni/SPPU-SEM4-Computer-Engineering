//============================================================================
// Name        : Assignment9.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
template<class T>class Set;
template<class T>class Iterator;
template<class T>
class Node
{
	T data;
	Node<T> *next;
	public:
	Node()
	{
		next=NULL;
	}
	Node(T x)
	{
		data=x;
		next=NULL;
	}
	friend class Set<T>;
	friend class Iterator<T>;
};
template<class T>
class Iterator
{
	Node<T> *ptr;
	friend class Set<T>;
	public:
	Iterator()
	{	ptr=NULL;	}
	void set(Node<T> *&t)
	{	ptr=t;	}
	void operator++(int)
	{	ptr=ptr->next;	}
	void next()
	{	ptr=ptr->next;	}
	bool operator!=(Iterator<T> a)
	{	if(a.ptr!=NULL&&ptr!=NULL)
		{
			if((a.ptr)->data==(ptr)->data)
				return false;
			return true;
		}
		if(a.ptr==NULL&&ptr==NULL)
			return false;
		return true;
	}
	void del()
	{	delete ptr;	}
};
template<class T>
class Set
{
	Node<T> *head;
	public:
	Set()
	{
		head=NULL;
	}
	Iterator<T> begin()
	{
		Iterator<T> a;
		a.ptr=head;
		return a;
	}
	Iterator<T> end()
	{
		Iterator<T> a;
		a.ptr=NULL;
		return a;
	}
	int size();
	void display();
	void insert(T);
	bool remove(T);
	bool contain(T);
	bool subSet(Set&);
	Set unionOf(Set&);
	Set intersectionOf(Set&);
	Set differenceOf(Set&);
};
template<class T>
int Set<T>::size()
{
	Iterator<T> it;
	it.set(head);
	int cnt=0;
	while(it!=end())
	{
		cnt++;
		it++;
	}
	return cnt;
}
template<class T>
void Set<T>::insert(T x)
{
	Node<T> *curr=head,*prev=NULL;
	while(curr!=NULL&&curr->data<x)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr!=NULL&&curr->data==x)
	{
		cout<<x<<" is already present, duplicate entry not allowed\n";
		return;
	}
	if(prev==NULL)
	{
		head=new Node<T>(x);
		head->next=curr;
	}
	else
	{
		prev->next=new Node<T>(x);
		prev->next->next=curr;
	}
}
template<class T>
void Set<T>::display()
{
	Iterator<T> it;
	it.set(head);
	while(it!=end())
	{
		cout<<it.ptr->data<<" ";
		it.next();
	}
	cout<<"\n";
}
template<class T>
bool Set<T>::contain(T x)
{
	Iterator<T> it;
	it.set(head);
	while(it!=end())
	{
		if(it.ptr->data==x)
			return true;
		it++;
	}
	return false;
}
template<class T>
bool Set<T>::remove(T x)
{
	if(contain(x))
	{
		Iterator<T> curr,prev;
		curr=begin();
		while(curr.ptr->data!=x)
		{
			prev=curr;
			curr.next();
		}
		if(prev.ptr==NULL)
			head=head->next;
		else
			prev.ptr->next=curr.ptr->next;
		curr.del();
		return true;
	}
	else
		return false;
}
template<class T>
bool Set<T>::subSet(Set &S2)
{
	if(head==NULL)
		return true;
	if(S2.head==NULL)
		return false;
	Iterator<T> p,q;
	p=begin();
	q=S2.begin();
	int cnt=0;
	while(q!=S2.end()&&p!=end())
	{
		if(p.ptr->data==q.ptr->data)
		{
			cnt++;
			p++;
		}
		q.next();
	}
	if(cnt==size())
		return true;
	return false;
}
template<class T>
Set<T> Set<T>::unionOf(Set &S2)
{
	Set<T> U;
	Iterator<T> p=begin(),q=S2.begin();
	Node<T> *r=NULL;
	if(p!=end()&&q!=S2.end())
	{
		if(p.ptr->data<q.ptr->data)
		{
			U.head=new Node<T>(p.ptr->data);
			p++;
		}
		else
		{
			U.head=new Node<T>(q.ptr->data);
			if(p.ptr->data==q.ptr->data)
				p++;
			q++;
		}
	}
	r=U.head;
	while(p!=end()&&q!=S2.end())
	{
		if(p.ptr->data<q.ptr->data)
		{
			r->next=new Node<T>(p.ptr->data);
			p++;
		}
		else
		{
			r->next=new Node<T>(q.ptr->data);
			if(p.ptr->data==q.ptr->data)
				p++;
			q++;
		}
		r=r->next;
	}
	if(r==NULL)
	{
		if(p.ptr==NULL)
		{
			U.head=new Node<T>(q.ptr->data);
			q++;
		}
		else
		{
			U.head=new Node<T>(p.ptr->data);
			p++;
		}
		r=U.head;
	}
	while(p!=end())
	{
		r->next=new Node<T>(p.ptr->data);
		r=r->next;
		p++;
	}
	while(q!=S2.end())
	{
		r->next=new Node<T>(q.ptr->data);
		r=r->next;
		q++;
	}
	return U;
}
template<class T>
Set<T> Set<T>::intersectionOf(Set &S2)
{
	Set<T> I;
	Iterator<T> p=begin(),q=S2.begin();
	Node<T> *r=NULL;
	while(p!=end()&&q!=S2.end())
	{
		if(p.ptr->data==q.ptr->data)
		{
			if(I.head==NULL)
			{
				I.head=new Node<T>(p.ptr->data);
				r=I.head;
			}
			else
				r->next=new Node<T>(p.ptr->data);
			q++;
			p++;
		}
		else if(p.ptr->data>q.ptr->data)
			q++;
		else
			p++;
	}
	return I;
}
template<class T>
Set<T> Set<T>::differenceOf(Set &S2)
{
	Node<T> *r;
	Iterator<T> p,q;
	if(head==NULL)
	{
		Set<T> D;
		return D;
	}
	Set<T> D;
	p=begin();
	q=S2.begin();
	while(p!=end()&&q!=S2.end())
	{
		if(p.ptr->data==q.ptr->data)
		{
			p.next();
			q.next();
		}
		else
		{
			if(D.head==NULL)
			{
				D.head=new Node<T>(p.ptr->data);
				r=D.head;
			}
			else
			{
				r->next=new Node<T>(p.ptr->data);
				r=r->next;
			}
			p++;
		}
	}
	if(D.head==NULL&&p!=end())
	{
		D.head=new Node<T>(p.ptr->data);
		p.next();
		r=D.head;
	}
	while(p!=end())
	{
		r->next=new Node<T>(p.ptr->data);
		p.next();
		r=r->next;
	}
	return D;
}
template<class T>
void operations(T var)
{
	Set <T>S1,S2,Res;
	T ele;
	int work,choice;
	do
	{
		cout<<"Enter\n1 To Work with Set 1\n2 To Work with Set 2\n0 To EXIT\n";
		cin>>work;
		switch(work)
		{
		case 1:
			do
			{
				cout<<"Enter\n1 To Insert\n2 To Remove\n3 To Search\n4 To Print Size\n5 To Check if Subset\n";
				cout<<"6 To Find Union\n7 To Find Intersection\n8 To Find Difference\n0 To Previous Menu\n";
				cin>>choice;
				switch(choice)
				{
					case 1:
						cout<<"Enter the Element to Insert\n";
						cin>>ele;
						S1.insert(ele);
						S1.display();
						break;
					case 2:
						cout<<"Enter the Element to Remove\n";
						cin>>ele;
						if(S1.remove(ele))
							cout<<"Element Removed\n";
						else
							cout<<"Element Not Present\n";
						S1.display();
						break;
					case 3:
						cout<<"Enter the Element to search\n";
						cin>>ele;
						if(S1.contain(ele))
							cout<<"Element Present\n";
						else
							cout<<"Element Not Present\n";
						break;
					case 4:
						cout<<"Set Size is "<<S1.size()<<"\n";
						break;
					case 5:
						if(S1.subSet(S2))
							cout<<"Set 1 is SubSet of Set 2\n";
						else
							cout<<"Not a SubSet\n";
						break;
					case 6:
						Res=S1.unionOf(S2);
						cout<<"Union of 2 Sets is\n";
						Res.display();
						break;
					case 7:
						cout<<"Intersection of 2 Sets is\n";
						Res=S1.intersectionOf(S2);
						Res.display();
						break;
					case 8:
						cout<<"Difference of 2 Sets is\n";
						Res=S1.differenceOf(S2);
						Res.display();
						break;
					case 0:
						break;
					default:
						cout<<"Invalid Choice\n";
				}
			}while(choice);
		break;
		case 2:
			do
			{
				cout<<"Enter\n1 To Insert\n2 To Remove\n3 To Search\n4 To Print Size\n5 To Check if Subset\n";
				cout<<"6 To Find Union\n7 To Find Intersection\n8 To Find Difference\n0 To Previous Menu\n";
				cin>>choice;
				switch(choice)
				{
					case 1:
						cout<<"Enter the Element to Insert\n";
						cin>>ele;
						S2.insert(ele);
						S2.display();
						break;
					case 2:
						cout<<"Enter the Element to Remove\n";
						cin>>ele;
						if(S2.remove(ele))
							cout<<"Element Removed\n";
						else
							cout<<"Element Not Present\n";
						S2.display();
						break;
					case 3:
						cout<<"Enter the Element to search\n";
						cin>>ele;
						if(S2.contain(ele))
							cout<<"Element Present\n";
						else
							cout<<"Element Not Present\n";
						break;
					case 4:
						cout<<"Set Size is "<<S2.size()<<"\n";
						break;
					case 5:
						if(S2.subSet(S1))
							cout<<"Set 2 is SubSet of Set 1\n";
						else
							cout<<"Not a SubSet\n";
						break;
					case 6:
						Res=S2.unionOf(S1);
						cout<<"Union of 2 Sets is\n";
						Res.display();
						break;
					case 7:
						cout<<"Intersection of 2 Sets is\n";
						Res=S2.intersectionOf(S1);
						Res.display();
						break;
					case 8:
						cout<<"Difference of 2 Sets is\n";
						Res=S2.differenceOf(S1);
						Res.display();
						break;
					case 0:
						break;
					default:
						cout<<"Invalid Choice\n";
				}
			}while(choice);
		break;
		case 0:
			cout<<"You have opted to EXIT\n";
			break;
		default:
			cout<<"Invalid Choice\n";
		}
	}while(work);
}
int main()
{
	int ch;
	cout<<"Enter Choice of Datatype\n1 For Integer\n2 For Float\n3 For Character\n";
	cin>>ch;
	if(ch==1)
		operations((int)1);
	else if(ch==2)
		operations((float)1.0f);
	else if(ch==3)
		operations('a');
	else
		cout<<"Invalid Choice\n";
	return 0;
}
