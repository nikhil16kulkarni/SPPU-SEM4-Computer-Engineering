//============================================================================
// Name        : Assignment4.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include<string.h>
using namespace std;
class CityNode;
class Queue
{
	char *data[100];
	int front,rear;
public:
	Queue()
	{
		front=rear=-1;
	}
	bool empty()
	{
		if(rear==-1)
			return true;
		return false;
	}
	bool full()
	{
		if(front==((rear+1)%100))
			return true;
		return false;
	}
	void push(char *p)
	{
		if(!full())
		{
			if(empty())
				front=0;
			rear=(rear+1)%100;
			data[rear]=p;
		}
	}
	char* pop()
	{
		if(!empty())
		{
			char*p=data[front];
			if(front==rear)
				front=rear=-1;
			else
				front=(front+1)%100;
			return p;
		}
		else
			return NULL;
	}
};
class Node
{
	char *city;
	int time;
	Node *next;
	friend class CityNode;
	friend class Flight;
public:
	Node()
	{
		next=NULL;
		time=-1;
		city=NULL;
	}
	Node(char *s,int t)
	{
		time=t;
		city=new char[strlen(s)+1];
		next=NULL;
		strcpy(city,s);
	}
	~Node()
	{
		delete city;
	}
};
class CityNode
{
	CityNode *down;
	Node *head;
	char *cname;
	friend class Flight;
public:
	CityNode()
	{
		down=NULL;
		head=NULL;
		cname=NULL;
	}
	CityNode(char *s)
	{
		cname=new char[strlen(s)+1];
		down=NULL;
		head=NULL;
		strcpy(cname,s);
	}
	~CityNode()
	{
		Node *p=head,*q;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			delete q;
		}
		head=NULL;
		delete cname;
	}
	void display();
};
void CityNode::display()
{
	Node *p=head;
	while(p->next!=NULL)
	{
		cout<<p->city<<"("<<p->time<<"),";
		p=p->next;
	}
	cout<<p->city<<"("<<p->time<<")\n";
}
class Flight
{
	CityNode *start;
public:
	Flight()
	{
		start=NULL;
	}
	CityNode* get_pos(char*);
	int get_index(char*);
	void set(int *&,int&);
	void create();
	void disp_city();
	void add_city(char*);
	void add_path(char*,char*,int);
	void disp_path();
	bool search_path(char*,char*);
	bool search_city(char*);
	void remove_path(char*,char*);
	void remove_city(char*);
	void degree(char*);
	void DFS_rec();
	void DFS(char*,int*);
	void BFS();
};
void Flight::BFS()
{
	Queue Q;
	int *visited,n;
	set(visited,n);
	char src[50];
	cout<<"Enter the strating vertex\n";
	cin.getline(src,48);
	cout<<"BFS Traversal\n";
	CityNode*p;
	Node*q;
	Q.push(src);
	while(!Q.empty())
	{
		strcpy(src,Q.pop());
		if(!visited[get_index(src)])
			cout<<src<<"\n";
		visited[get_index(src)]=1;
		p=get_pos(src);
		q=p->head;
		while(q!=NULL)
		{
			if(!visited[get_index(q->city)])
				Q.push(q->city);
			q=q->next;
		}
	}
}
void Flight::DFS_rec()
{
	int *visited,n;
	char src[50];
	set(visited,n);
	cout<<"Enter starting vertex\n";
	cin.getline(src,48);
	cout<<"DFS Traversal is\n";
	DFS(src,visited);
}
void Flight::DFS(char *src,int visited[])
{
	cout<<src<<"\n";
	visited[get_index(src)]=1;
	CityNode*p=get_pos(src);
	Node*q=p->head;
	while(q!=NULL)
	{
		if(!visited[get_index(q->city)])
			DFS(q->city,visited);
		q=q->next;
	}
}
void Flight::set(int *&p,int &n)
{
	n=0;
	CityNode*q=start;
	while(q!=NULL)
	{
		n++;
		q=q->down;
	}
	p=new int[n];
	for(int i=0;i<n;i++)
		p[i]=0;
}
int Flight::get_index(char *s)
{
	int i=0;
	CityNode *p=start;
	while(strcmp(p->cname,s))
	{
		i++;
		p=p->down;
	}
	return i;
}
bool Flight::search_city(char *c)
{
	CityNode*p=start;
	while(p!=NULL)
	{
		if(strcmp(c,p->cname)==0)
			return true;
		p=p->down;
	}
	return false;
}
bool Flight::search_path(char s[],char d[])
{
	CityNode *p=get_pos(s);
	Node *q=p->head;
	while(q!=NULL)
	{
		if(strcmp(q->city,d)==0)
			return true;
		q=q->next;
	}
	return false;
}
CityNode* Flight::get_pos(char *s)
{
	CityNode*p=start;
	while(p!=NULL)
	{
		if(strcmp(p->cname,s)==0)
			return p;
		p=p->down;
	}
	return NULL;
}
void Flight::create()
{
	CityNode *p=start;
	char str[100];
	while(true)
	{
		cout<<"Enter City names or STOP\n";
		cin.getline(str,99);
		if(strcmp(str,"STOP")==0)
			break;
		if(p==NULL)
		{
			start=new CityNode(str);
			p=start;
		}
		else
		{
			p=start;
			while(p->down!=NULL)
				p=p->down;
			p->down=new CityNode(str);
		}
	}
}
void Flight::disp_city()
{
	CityNode *p=start;
	if(p==NULL)
	{
		cout<<"No cities present, add city first\n";
		return;
	}
	cout<<"----------------------------------------\n";
	cout<<"List of cities: ";
	while(p->down!=NULL)
	{
		cout<<p->cname<<", ";
		p=p->down;
	}
	cout<<p->cname<<"\n";
	cout<<"----------------------------------------\n";
}
void Flight::add_city(char s[])
{
	CityNode*p=start;
	while(p->down!=NULL)
		p=p->down;
	p->down=new CityNode(s);
}
void Flight::add_path(char s[],char d[],int t)
{
	CityNode *p=get_pos(s);
	Node *q=p->head;
	if(q==NULL)
	{
		p->head=new Node(d,t);
		return;
	}
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=new Node(d,t);
}
void Flight::disp_path()
{
	cout<<"----------------------------------------\n";
	cout<<"ALL the paths are\n";
	CityNode*p=start;
	while(p!=NULL)
	{
		if(p->head!=NULL)
		{
			cout<<p->cname<<" To: ";
			p->display();
		}
		p=p->down;
	}
	cout<<"----------------------------------------\n";
}
void Flight::remove_path(char s[],char d[])
{
	CityNode*p=get_pos(s);
	Node*q=p->head,*r=NULL;
	while(strcmp(q->city,d)!=0)
	{
		r=q;
		q=q->next;
	}
	if(q==p->head)
	{
		p->head=(p->head)->next;
		delete q;
	}
	else
	{
		r->next=q->next;
		delete q;
	}
}
void Flight::remove_city(char ct[])
{
	CityNode*p=get_pos(ct),*q=start;
	while(q!=NULL)
	{
		if(q!=p)
		{
			if(search_path(q->cname,ct))
				remove_path(q->cname,ct);
		}
		q=q->down;
	}
	q=start;
	while(q->down!=p)
		q=q->down;
	if(p==start)
		start=start->down;
	else
		q->down=p->down;
	delete p;
}
void Flight::degree(char ct[])
{
	int in=0,out=0;
	CityNode*p=get_pos(ct);
	Node*q=p->head;
	while(q!=NULL)
	{
		out++;
		q=q->next;
	}
	CityNode*r=start;
	while(r!=NULL)
	{
		if(r!=p)
		{
			q=r->head;
			while(q!=NULL)
			{
				if(strcmp(q->city,ct)==0)
					in++;
				q=q->next;
			}
		}
		r=r->down;
	}
	cout<<"In-degree is "<<in<<"\n";
	cout<<"Out-degree is "<<out<<"\n";
}
int main()
{
	int ch,t;
	char str[100],str2[100],c[100];
	Flight F1;
	cout<<"Add some cities first\n";
	F1.create();
	F1.disp_city();
	do
	{
		cout<<"Enter\n1 To Add City\n2 To Add Path\n3 To Remove Path\n4 To Remove City";
		cout<<"\n5 To Calculate In-degree and Out-degree\n6 For Traversals\n0 To EXIT\n";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{
		case 1:
			cout<<"Enter City name to add\n";
			cin.getline(c,99);
			if(!F1.search_city(c))
				F1.add_city(c);
			else
				cout<<"City Already Present\n";
			F1.disp_city();
			break;
		case 2:
			cout<<"Enter Source City\n";
			cin.getline(str,99);
			cout<<"Enter Destination City\n";
			cin.getline(str2,99);
			cout<<"Enter Time\n";
			cin>>t;
			cin.ignore();
			if(F1.search_city(str)&&F1.search_city(str2))
			{
				if(!F1.search_path(str,str2))
					F1.add_path(str,str2,t);
				else
					cout<<"Such path already exists\n";
			}
			else
				cout<<"Reference City name not present in the list\n";
			F1.disp_path();
			break;
		case 3:
			cout<<"Enter Source City\n";
			cin.getline(str,99);
			cout<<"Enter Destination City\n";
			cin.getline(str2,99);
			if(F1.search_city(str)&&F1.search_city(str2))
			{
				if(F1.search_path(str,str2))
					F1.remove_path(str,str2);
				else
					cout<<"No such path exists\n";
			}
			else
				cout<<"Reference city name not present\n";
			F1.disp_path();
			break;
		case 4:
			cout<<"Enter City Name\n";
			cin.getline(str,99);
			if(F1.search_city(str))
				F1.remove_city(str);
			else
				cout<<"Reference city name not present\n";
			F1.disp_city();
			F1.disp_path();
			break;
		case 5:
			cout<<"Enter City Name\n";
			cin.getline(str,99);
			if(F1.search_city(str))
				F1.degree(str);
			else
				cout<<"Reference city name not present\n";
			break;
		case 6:
			cout<<"TRAVERSALS\n";
			F1.DFS_rec();
			F1.BFS();
			break;
		case 0:
			cout<<"You have opted to EXIT\n";
			break;
		default:
			cout<<"Invalid Choice\n";
		}
	}while(ch);
	return 0;
}


/*#include <iostream>
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


class Gnode{
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

void graph::delete(){

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
