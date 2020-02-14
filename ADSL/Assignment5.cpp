//============================================================================
// Name        : Assignment5.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;
class Edge
{
	int s,d,wt;
public:
	Edge()
	{
		s=-1;
		d=-1;
		wt=-1;
	}
	friend class Graph;
};
class Graph
{
	int vertex;
	int edges;
	int mat[20][20];
	bool check[20][20];
	int MST[20][20];
public:
	Graph()
{
		vertex=0;
		edges=0;
		for(int i=0;i<20;i++)
			{
				for(int j=0;j<20;j++)
				{
					mat[i][j]=-1;
					MST[i][j]=-1;
				}
			}
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				check[i][j]=false;
			}
		}
}
	void create();
	void display();
	void prim();
	void kruskal();
	void display_MST(int);
};

void Graph::create()
{
	cout<<"Enter the no. of vertices: ";
	cin>>vertex;
	cout<<"Enter the no. of edges: ";
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		cout<<"ENter source: ";
		int u,v;
		cin>>u;


			cout<<"\n"<<"Enter Destination: ";
		cin>>v;
		int len;
		cout<<"Enter distance: ";
		cin>>len;
		mat[u][v]=len;
		mat[v][u]=len;

	}
}
void Graph::display()
{
	cout<<setw(3)<<" ";
	for(int i=0;i<vertex;i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n\n";
	for(int i=0;i<vertex;i++)
	{
		cout<<setw(3)<<i<<" ";
		for(int j=0;j<vertex;j++)
		{
			cout<<setw(3)<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void Graph::prim()
{
	int r[vertex],unr[vertex];
	for(int i=0;i<vertex;i++)
	{
		r[i]=0;
		unr[i]=1;
	}
	int cnt=0;
	int s=0;
	r[0]=1;
	unr[0]=0;
	int len=0;
	while(cnt!=vertex-1)
	{
		int min=10000;
		int d;
		for(int i=0;i<vertex;i++)
		{
			if(r[i]==1)
			{
				for(int j=0;j<vertex;j++)
				{
					if(min>mat[i][j]&&r[j]==0&&mat[i][j]!=-1)
					{
						min=mat[i][j];
						s=i;
						d=j;
					}
				}
			}
		}
		len+=mat[s][d];
//		cout<<len<<"\n";
		MST[s][d]=mat[s][d];
		MST[d][s]=mat[s][d];
		mat[s][d]=-1;
		mat[d][s]=-1;
		r[d]=1;
		unr[d]=0;
		cnt++;
//		cout<<cnt<<"\n";
	}
	cout<<"Minimum Spanning Tree: \n";
	display_MST(len);
}
void Graph::kruskal()
{
	Edge e[edges];
	int k=0;
	for(int i=0;i<edges;i++)
	{
		for(int j=0;j<edges;j++)
		{
			if(mat[i][j]!=-1&&check[i][j]==false)
			{
				e[k].s=i;
				e[k].d=j;
				e[k].wt=mat[i][j];
				check[i][j]=true;
				check[j][i]=true;
				k++;
			}
		}
	}
	k=0;
	for(int i=0;i<edges;i++)
		{
			k=i;
			for(int j=i+1;j<edges;j++)
			{

				if(e[i].wt>e[j].wt)
				{
					k=j;
				}

			}
			Edge temp ;
			temp=e[i];
			e[i]=e[k];
			e[k]=temp;
		}
	int father[edges];
	for(int i=0;i<edges;i++)
	{
		father[i]=i;
	}
	int len=0;
	for(int i=0;i<edges;i++)
	{
		if(father[e[i].s]!=father[e[i].d])
		{
			MST[e[i].s][e[i].d]=e[i].wt;
			MST[e[i].s][e[i].d]=e[i].wt;
			father[e[i].d]=father[e[i].s];
			len+=e[i].wt;
		}
	}
	cout<<"Minimum Spanning Tree: \n";
	display_MST(len);
}
void Graph::display_MST(int len)
{
	cout<<setw(3)<<" ";
	for(int i=0;i<vertex;i++)
	{
		cout<<setw(3)<<i<<" ";
	}
	cout<<"\n\n";
	for(int i=0;i<vertex;i++)
	{
		cout<<setw(3)<<i<<" ";
		for(int j=0;j<vertex;j++)
		{
			cout<<setw(3)<<MST[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nLength: "<<len<<"\n";

}
int main()
{
	Graph g;
	char ch;
	int a;
	do
	{
		cin>>a;
		switch(a)
		{
		case 1:
			g.create();
			break;
		case 2:
			g.display();
			break;
		case 3:
			g.prim();
			break;
		case 4:
			g.kruskal();
			break;
		}
		cout<<"Do you want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
}
