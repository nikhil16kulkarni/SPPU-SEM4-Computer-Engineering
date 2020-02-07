//============================================================================
// Name        : Assignment4.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#define max 10
using namespace std;
class Node
{
	string city;
	int timeCost;
	Node *next;
public:
	Node()
	{
		city="";
		next=NULL;
		timeCost=0;
	}
	Node(string cityName,int weight)
	{
		city=cityName;
		timeCost=weight;
		next=NULL;
	}
	friend class Flight;
};
class Flight
{
	Node *head[max];
	string v[max];
	int n;
public:
	Flight()
	{
		for(int i=0;i<max;i++)
		{
			head[i]=NULL;
		}
		n=0;
	}
	void readGraph();
	void insertDirected(string city1,string city2,int cost);
	int getIndex(string s);
	void display_adj_list();
	void add_edge();
	void delete_edge();
	void add_vertex();
	void delete_vertex();
	Node* delete_whole_vertex(Node *temp);
	void inDegree();
	void outDegree();
	void DFS(int);
	void BFS(string);

};

void Flight::readGraph()
{
	int flights,cost;
	string city1,city2;
	cout<<"\nEnter the No of Cities : ";
	cin>>n;
	int flag=0;

	cout<<"Enter the Details Of Cities \n";
	for(int i=0;i<n;i++)
	{
		cout<<"Enter City "<<i+1<<" : ";
		cin>>v[i];
		head[i]=new Node;
		head[i]->city=v[i];
	}
	cout<<"\nEnter the Number Of Flights : ";
	cin>>flights;
	for(int i=0;i<flights;i++)
	{
		cout<<"Enter the Details of Flight "<<i+1<<"\n";
	x:	cout<<"Enter the Source : ";
		cin>>city1;
		for(int j=0;j<n;j++)
		{
			if(city1==v[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"\nInvaid City Entered \nPlease Enter Proper City Name\n";
			goto x;
		}
		flag=0;
	y:	cout<<"Enter the Destination : ";
		cin>>city2;
		for(int j=0;j<n;j++)
		{
			if(city2==v[j])
			{
					flag=1;
					break;
			}
		}
		if(flag==0)
		{
			cout<<"\nInvaid City Entered \nPlease Enter Proper City Name\n";
			goto y;
		}
		cout<<"Enter the Cost : ";
		cin>>cost;
		insertDirected(city1,city2,cost);

	}
}
void Flight::insertDirected(string city1,string city2,int cost)
{
	Node *src,*dest;
	dest=new Node(city2,cost);
	int ind=getIndex(city1);

	if(head[ind]==NULL)
		head[ind]=dest;
	else
	{
		src=head[ind];
		while(src->next!=NULL)
		{
			src=src->next;
		}
		src->next=dest;
	}
}

int Flight::getIndex(string s)
{
	for(int i=0;i<n;i++)
	{

		if(head[i]->city==s)
			return i;
	}
	return -1;
}
void Flight::display_adj_list()
{
	if(head[0]==NULL)
		cout<<"\nList is Empty\n";
	else
	{
	 for(int i=0;i<n;i++)
	 {
		cout<<head[i]->city;
		Node *temp=head[i]->next;
		while(temp!=NULL)
		{
			cout<<"->"<<temp->city<<"|"<<temp->timeCost;
			temp=temp->next;
		}
		cout<<endl<<endl;
	 }
	}
}
void Flight::add_edge()
{
	string city1,city2;
	int cost;
	int flag=0;
x:	cout<<"\nEnter the Source : ";
	cin>>city1;
	for(int j=0;j<n;j++)
	{
		if(city1==v[j])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nInvaid City Entered \nPlease Enter Proper City Name\n";
		goto x;
	}
	flag=0;
	y:	cout<<"\nEnter the Destination : ";
		cin>>city2;
		for(int j=0;j<n;j++)
		{
			if(city2==v[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"\nInvaid City Entered \nPlease Enter Proper City Name\n";
			goto y;
		}
	cout<<"\nEnter the Cost : ";
	cin>>cost;
	insertDirected(city1,city2,cost);

}
void Flight::delete_edge()
{
	string city1,city2;
	int flag=0,flag1=0;
	cout<<"\nEnter the Source : ";
	cin>>city1;
    cout<<"Enter the Destination whose Flight from "<<city1<<" is to Be Deleted\n";
	cin>>city2;
    int ind=getIndex(city1);
	Node *p,*q;
	q=head[ind];
	p=NULL;
	while(q->city!=city2)
	{
	 p=q;
	 q=q->next;
    }
	p->next=q->next;
	q->next=NULL;
	delete q;
}
void Flight::add_vertex()
{
	string city1;
	cout<<"\nEnter the City To Be inserted ";
	cin>>city1;

		head[n]=new Node;
		head[n]->city=city1;
		n=n+1;

	cout<<"\nCity "<<city1<<" Inserted Successfully\n";
}
void Flight::delete_vertex()
{
	string city1;
	Node *temp,*temp1;
	int flag=0;
	x:cout<<"\nEnter the City To Be Deleted : ";
	cin>>city1;

	for(int j=0;j<n;j++)
	{
		if(city1==v[j])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nInvaid City Entered \nPlease Enter Proper City Name\n";
		goto x;
	}
	for(int i=0;i<n;i++)
    {
        temp=head[i];
        temp1=head[i]->next;
        while(temp1!=NULL)
        {
            if(temp1->city==city1)
            {
                temp->next=temp1->next;
                delete temp1;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    int ind=getIndex(city1);
    Node *p=head[ind];
    p->next=delete_whole_vertex(p->next);
    delete p;
    p=NULL;
    while(ind<n)
    {
        head[ind]=head[ind+1];

        ind++;
    }
    n=n-1;
    cout<<city1<<" Deleted Successfully\n";

}
Node* Flight::delete_whole_vertex(Node *temp)
{
	if(temp!=NULL)
	{
		temp->next=delete_whole_vertex(temp->next);
		delete temp;
	}
	return NULL;
}
void Flight::inDegree()
{
	int count;
	Node *p;
	for(int i=0;i<n;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			p=head[j]->next;
			while(p!=NULL)
			{
				if(p->city==head[i]->city)
					count=count+1;
				p=p->next;
			}
		}
		cout<<"\nFlights To "<<head[i]->city<<" Are : "<<count<<endl;
	}

}
void Flight::outDegree()
{
	int count;
	for(int i=0;i<n;i++)
	{
		count=0;

		Node *p=head[i]->next;
		while(p!=NULL)
		{
			count++;
			p=p->next;
		}
		cout<<"\nFlights From "<<head[i]->city<<" Are :"<<count<<endl;
	}
}





void Flight::BFS(string ){

}














int main() {


	Flight f;
	int ch;
	do
	{
		cout<<"\n1.Insert Cities and Flights\n2.Display Adjacency List\n3.Add Edge\n4.Delete Edge\n5.Add Vertex\n6.Delete Vertex\n7.InDegree\n8.OutDegree\n9.BFS Traversal\n10.DFS Traversal";
		cout<<"\nEnter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			f.readGraph();
			f.display_adj_list();
			break;
		case 2:
			f.display_adj_list();
			break;
		case 3:
			f.add_edge();
			f.display_adj_list();
			break;
		case 4:
			f.delete_edge();
			f.display_adj_list();
			break;
		case 5:
			f.add_vertex();
			f.display_adj_list();
			break;
        case 6:
            f.delete_vertex();
            f.display_adj_list();
            break;
        case 7:
        	f.inDegree();
        	break;
        case 8:
        	f.outDegree();
        	break;
        case 9:
        	f.BFS();
        	break;
        case 10:
        	f.DFS();
        	break;
        default:
        	cout<<"\nInvalid Choice\n";

		}



	}while(ch!=0);
	return 0;
}


/*class Gnode{
	string dest;
	int cost;
	Gnode *next;

public:
	Gnode(){
		cost=0;
		next=NULL;
		dest="";
	}

	Gnode(string s, int c){
		dest=s;
		cost=c;
		next=NULL;
	}

	friend class graph;
};


class Stack
{
	int top;
	Gnode *data[MAX];
	public:
	Stack()
	{	top=-1;	}
	void push(Gnode *p)
	{
		if(!full())
			data[++top]=p;
		else
			cout<<"Full\n";
	}
	Gnode *pop()
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


class graph{
	int edge;
	string city[MAX];
	Gnode* g[MAX];
	int vertex;

public:
	graph(){
		edge=vertex=0;
		for(int i=0;i<MAX;i++){
			g[i]=NULL;
			city[i]="";
		}
	}
	int search(string);
	void create();
	void display();
	void addedge(int, int, int);
//	void delete();
	void addnewedge();

};


int graph::search(string temp){
	for(int i=0;i<vertex;i++){
			if(temp==city[i]){
				return i;
			}
		}
		return -1;
}


void graph::create(){
	cout<<"\nEnter no. of cities\n";
	cin>>vertex;
	cout<<"\nEnter city names\n";
	for(int i=0;i<vertex;i++){
		cin>>city[i];
	}
	cout<<"Enter no. of edges\n";
	cin>>edge;
	for(int i=0;i<edge;i++){
		//addnewedge();
	}
}

/*void graph::delete(){

}*/


/*void graph::display(){
    for(int i=0;i<vertex;i++){
    	Gnode* temp=g[i];
    	while(temp!=NULL){
    		cout<<city[i]<<"-->"<<temp->dest<<"--- Cost:  "<<temp->cost<<endl;
    		temp=temp->next;
    	}
    }
}


void graph::addedge(int si, int di, int costn){
	if(g[si]==NULL){
		Gnode* p=new Gnode(city[di],costn);
		g[si]=p;
	}
	else {
		Gnode* temp=g[si];
		while(temp->next!=NULL){
			temp=temp->next;
		}
		Gnode *p=new Gnode(city[di],costn);
		temp->next=p;
	}
}

void graph::addnewedge(){


	string src;
	cout<<"Enter Source City "<<endl;
	cin>>src;
	int ssrc=search(src);
	if(ssrc==-1){
		cout<<"Enter Valid Name "<<endl;
		cin>>src;
		ssrc=search(src);
	}


	string dst;
	cout<<"Enter Destination City "<<endl;
	cin>>dst;
	int sdst=search(dst);
	if(sdst==-1){
		cout<<"Enter Valid Name "<<endl;
		cin>>dst;
		sdst=search(dst);
	}

	int costn;
	cout<<"Enter Distance between them : "<<"\t";
	cin>>costn;

	addedge(ssrc,sdst,costn);
}


int main() {
	graph g1;
	int a;
	char yn;
	string ct;
	do{
		cout<<"1.Create\n2.Display\n3.Add New Node\n";
		cin>>a;
		switch(a){

		case 1: g1.create();
				break;
		case 2: g1.display();
				break;
	//	case 3: g1.addnew
		}
		cout<<"Do you want to continue?(y/n)";
		cin>>yn;
	}while(yn=='y' || yn=='Y');
}*/
