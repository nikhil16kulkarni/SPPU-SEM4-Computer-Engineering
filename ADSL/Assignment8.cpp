#include <bits/stdc++.h>
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
