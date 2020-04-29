#include<iostream>
#include<string>
using namespace std;
class dictionary;
class avlnode
{
	string keyword;
	string meaning;
	avlnode *left,*right;
	int bf;
	public:
	avlnode()
	{
		keyword='\0';
		meaning='\0';
		left=right=NULL;
		bf=0;
	}
	avlnode(string k,string m)
	{
		keyword=k;
		meaning=m;
		left=right=NULL;
		bf=0;
	}
friend class dictionary;
};

class dictionary
{
	avlnode *par,*loc;
	public:
	avlnode *root;
	dictionary()
	{	
		root=NULL;
		par=loc=NULL;
	}
	void accept();
	void insert(string key,string mean);
	void LLrotation(avlnode*,avlnode*);
	
	void RRrotation(avlnode*,avlnode*);
	
	void inorder(avlnode *root);
	void deletekey(string key);
	void descending(avlnode *);
	void search(string);
	void update(string,string);

};
void dictionary::descending(avlnode *root)
{
	if(root)
	{
		descending(root->right);
		cout<<root->keyword<<" "<<root->meaning<<endl;
		descending(root->left);
	}
}

void dictionary::accept()
{
	string key,mean;
	cout<<"Enter keyword "<<endl;
	cin>>key;
	cout<<"Enter meaning "<<endl;
	cin>>mean;
	insert(key,mean);
}
void dictionary::LLrotation(avlnode *a,avlnode *b)
{
	cout<<"LL rotation"<<endl;	
	a->left=b->right;
	b->right=a;
	a->bf=b->bf=0;
}

void dictionary::RRrotation(avlnode *a,avlnode *b)
{
	cout<<"RR rotation"<<endl;	
	a->right=b->left;
	b->left=a;
	a->bf=b->bf=0;
}







void dictionary::insert(string key,string mean)
{
	//cout<<"IN Insert \n";
	if(!root)
	{
		//create new root
		root=new avlnode(key,mean);
		cout<<"ROOT CREATED \n";
		return;
	}
//	else
//	{
		avlnode *a,*pa,*p,*pp;
		//a=NULL;
		pa=NULL;
		p=a=root;
		pp=NULL;

		while(p)
		{
			cout<<"In first while \n";
			if(p->bf)
			{
			a=p;
			pa=pp;
			}
			if(key<p->keyword){pp=p;p=p->left;}   //takes the left branch
			else if(key>p->keyword){pp=p;p=p->right;} //right branch
			else
			{
				//p->meaning=mean;
				cout<<"Already exist \n";
				return;
			}
		}
		cout<<"Outside while \n";
		avlnode *y=new avlnode(key,mean);		
		if(key<pp->keyword)
		{
			pp->left=y;
		}
		else
			pp->right=y;
		cout<<"KEY INSERTED \n";

		int d;
		avlnode *b,*c;
		//a=pp;
		b=c=NULL;
		if(key>a->keyword)
		{
			cout<<"KEY >A->KEYWORD \n";
			b=p=a->right;
			d=-1;
			cout<<" RIGHT HEAVY \n";
		}
		else
		{
			cout<<"KEY < A->KEYWORD \n";
			b=p=a->left;
			d=1;
			cout<<" LEFT HEAVY \n";
		}

		while(p!=y)
		{
			if(key>p->keyword)
			{
				p->bf=-1;
				p=p->right;

			}
			else
			{
				p->bf=1;
				p=p->left;
			}
		
		}
		cout<<" DONE ADJUSTING INTERMEDIATE NODES \n";
		if(!(a->bf)||!(a->bf+d))
		{
			a->bf+=d;
			return;
		}
		//else
		//{
		if(d==1)
		{
			//left heavy
			if(b->bf==1)
			{
				LLrotation(a,b);
				/*a->left=b->right;
				b->right=a;
				a->bf=0;
				b->bf=0;*/
			}
			else //if(b->bf==-1)
			{
				
				cout<<"LR rotation"<<endl;		
				c=b->right;
				b->right=c->left;
				a->left=c->right;
				c->left=b;
				c->right=a;
				switch(c->bf)
				{
					case 1:
					{
						a->bf=-1;
						b->bf=0;
						break;
					}
					case -1:
					{
						a->bf=0;
						b->bf=1;
						break;
					}

					case 0:
					{
						a->bf=0;
						b->bf=0;
						break;
					}
		
				}
				c->bf=0;
				b=c;   //b is new root

				
			}
			//else
			//	cout<<"Balanced \n";

		}
	
		if(d==-1)
		{
			if(b->bf==-1)
			{
		//		cout<<"RR rotation"<<endl;	
				/*a->right=b->left;
				b->left=a;
				a->bf=b->bf=0;*/
				RRrotation(a,b);
			}
			else// if(b->bf==1)
			{
				c=b->left;
		//		cout<<"RL rotation"<<endl;		
				a->right=c->left;
				b->left=c->right;
				c->left=a;
				c->right=b;
				switch(c->bf)
				{
					case 1:
					{
						a->bf=0;
						b->bf=-1;
						break;
					}
					case -1:
					{
						a->bf=1;
						b->bf=0;
						break;
					}

					case 0:
					{
						a->bf=0;
						b->bf=0;
						break;
					}
		
				}
				c->bf=0;
				b=c;  //b is new root
				
			}

			//else
				//cout<<"Balanced \n";
		}
		//}
		if(!pa)
			root=b;
		else if(a==pa->left)
			pa->left=b;
		else
			pa->right=b;
		cout<<"AVL tree created!! \n";
		//cout<<"AVL \n";
		//inorder(root);
	


}
void dictionary::search(string key)
{
	cout<<"ENTER SEARCH \n";
	loc=NULL;
	par=NULL;
	if(root==NULL)
	{
		cout<<"Tree not created  "<<endl;
		
		loc=NULL;
		par=NULL;
	}

	//par=NULL;loc=NULL;
	avlnode *ptr;
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->keyword==key)
		{

			
			loc=ptr;
			break;                                  
		}
		else if(key<ptr->keyword)
		{
			par=ptr;
			ptr=ptr->left;
		}

		else
		{
			par=ptr;                          
			ptr=ptr->right;
			
		}
	}
	
	if(loc==NULL)
	{
		cout<<"Not found "<<endl;
	}
	
}

void dictionary::update(string oldkey,string newmean)
{
	search(oldkey);
	loc->meaning=newmean;
	cout<<"UPDATE SUCCESSFUL \n";
}
void dictionary::deletekey(string key)
{
	
}
void dictionary::inorder(avlnode *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->keyword<<" "<<root->meaning<<endl;
		inorder(root->right);
	}
}

int main()
{
	string k,m;
	dictionary d;
	int ch;
	string key,mean;
	
	do
	{
	cout<<"1.Insert \n2.Update \n3.Ascending \n4.Descending \n5.Display \n6.Quit \n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			d.accept();
			break;
		}
		case 2:
		{
			cout<<"Enter key whose meaning to update \n";
			cin>>key;
			cout<<"Enter new meaning\n";
			cin>>mean;
			d.update(key,mean);
			break;
		}
		case 3:
			d.inorder(d.root);
			break;
		
		case 4:
			cout<<"Descending \n";
			d.descending(d.root);
			break;
		
		case 5:
			d.inorder(d.root);
			break;
		default:
			break;
	}	
	}while(ch!=6);	
		
		
	
return 0;
}

/* #include <bits/stdc++.h>
using namespace std;

float C[20][20];
int R[20][20];
class node{
char data;
node* lchild;
node* rchild;
	public:
	node(){
		data='\0';
		lchild=rchild=NULL;
	}
	friend class OBST;
};

class OBST{
node* root;
int n;
	public:
	OBST(int d)
	{
	n=d;
	root=NULL;
	}
	void optimal(char[],float[],float[]);

	int find(int,int);
	node* construct(char[],int,int);
	void traversal();
	void postorder(node*);
	void preorder(node*);
	void inorder(node*);
};


void OBST::postorder(node* temp) {
	if (temp != NULL) {
		postorder(temp->lchild);
		postorder(temp->rchild);
		cout << "\t" << temp->data;
	}
	else
        return;
}
void OBST::preorder(node* temp) {
	if (temp != NULL) {
		cout << "\t" << temp->data;
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
	else
	return;
}
void OBST::inorder(node* temp) {
	if (temp != NULL) {
		inorder(temp->lchild);
		cout << "\t" << temp->data;
		inorder(temp->rchild);
	}
	else
        return;
}

void OBST::traversal(){
	cout << "\nTREE TRAVERSAL";
	if(root==NULL){
        cout<<"\n TREE IS EMPTY";
        return ;
        }
        else{
	cout << "\nPRE-ORDER";
	preorder(root);
	cout << "\nIN-ORDER";
	inorder(root);
	cout << "\nPOST-ORDER";
	postorder(root);
}
}

int OBST::find(int i,int j)
{
	float min=9999.00;
	int l,k;

	for(k=i;k<=j;k++)
	if(C[i][k-1]+C[k+1][j]<min)
	{
	min=C[i][k-1]+C[k+1][j];
	l=k;
	}
	return l;

}

node* OBST::construct(char D[],int i,int j)
{
node* p;
if(R[i][j]==0)
	return NULL;
else
{
	p=new node;
	p->data=D[R[i][j]];
	p->lchild=construct(D,i,R[i][j]-1);
	p->rchild=construct(D,R[i][j]+1,j);
	return p;
}

}
void OBST::optimal(char D[],float P[],float Q[])
{
float W[n+1][n+1];

for(int i=0;i<=n;i++)
for(int j=0;j<=n;j++)
C[i][j]=W[i][j]=R[i][j]=0;

for(int i=1;i<=n;i++)
{
	W[i][i]=Q[i-1]+Q[i]+P[i];
	C[i][i]=W[i][i];
	R[i][i]=i;
}
	for(int step=2;step<=n;step++)
	{
		for(int i=1;i<=n-step+1;i++)
		{
			int j=i+step-1;
			W[i][j]=W[i][j-1]+P[j]+Q[j];
			int k=find(i,j);
			C[i][j]=W[i][j]+C[i][k-1]+C[k+1][j];
			R[i][j]=k;
		}
	}
root=construct(D,1,n);
}


int main(){
int n;
cout<<"\n Enter number of keys";
cin>>n;

OBST obj(n);
char d[n+1];
float p[n+1];
float q[n+1];

for(int i=1;i<=n;i++){
	cout<<"\nEnter keys in sorted order";
	cin>>d[i];
}

for(int i=1;i<=n;i++){
	cout<<"\nEnter success probability (pi)";
	cin>>p[i];
	while(p[i]<0||p[i]>1)
	{
		cout<<"\nInvalid Probability. Enter Again: ";
		cin>>p[i];
	}
}

for(int i=0;i<=n;i++){
	cout<<"\nEnter failure probability (qi)";
	cin>>q[i];
	while(q[i]<0||q[i]>1)
	{
		cout<<"\nInvalid Probability. Enter Again: ";
		cin>>q[i];
	}
}
obj.optimal(d,p,q);
obj.traversal();

return 0;
}

*/
