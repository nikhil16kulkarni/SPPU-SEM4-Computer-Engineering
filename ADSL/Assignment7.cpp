/*

//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define N 30

class Symbol{
	char name[50],type[20],divi[1];
	int rollno;
	Symbol *next;

public:


	friend class Table;
};


class Table{
	int chain[N];
public:
	int Hashfun(string);
	void with_replacement();
	void without_replacement();
};

int Table::Hashfun(string str){

}

int main() {

	return 0;
}







/*


#include<iostream>
#define MAX 10
using namespace std;
#include<string.h>
class Student
{
	public : char name[50],type[20],divi[1];
			  int rollno;
			  Student *next;
	public  :
			  friend void getstud(Student *pt);
			  friend void putstud(Student *pt);
};

void putstud(Student *pt)
{
	cout << " -> " <<pt->name;
	cout << " -> " <<pt->divi;
	cout << " -> " <<pt->rollno;
	cout<< " -> "<<pt->type;
}

void getstud(Student *pt)
{
		cout << "\n Enter the name :\n";
		cin >> pt->name;
		cout<<"Enter division :\n";
		cin>>pt->divi;
		cout<<"Enter roll no :\n";
		cin>>pt->rollno;
		cout<<"Enter your branch\n";
		cin>>pt->type;
}

class Symboltable
{
	public  : 	int data;
				Student *next;
};


class Database
{
	private : Symboltable s[MAX];
	public  : Database()
			  {
					for(int i=0;i<MAX;i++)
					{
						s[i].data=i;
						s[i].next = NULL;
					}
			 }
			 int division_method(char[]);
			 Student * getnode();
			 void add();
			 void display();
			 void search(char name[]);
			void delete1(char name[]);
			 void modify(char name[]);
			 void menu();
};
void Database :: search(char name[])
{
	int key,flag=0;
	Student *last=NULL;

	key = division_method(name);

	last = s[key].next;
	while(last!=NULL)
	{
		if(strcmp(last->name,name) == 0)
		{
				flag=1;
				break;
		}

		last = last->next;
	}

	if(flag==1)
			cout << "\n Search record found ....";
	else
			cout << "\n Search record not found ";
}

void Database :: delete1(char name[])
{
	int key,flag=0,i=0;
	Student *last=NULL,*prev=NULL,*pt=NULL;

	key = division_method(name);


	prev = last = s[key].next;
	while(last!=NULL)
	{
		if(strcmp(last->name,name) == 0)
		{
				flag=1;
				break;
		}
		prev = last;
		i++;
		last = last->next;
	}

	if(flag==1)
	{
			pt = last;
			if(last==prev) // found first.
			{
				if(last->next==NULL)
					s[i].next = NULL;
				else
					s[i].next = last->next;

			}
			else
			{
				prev->next = last->next;
			}

			delete pt;
	}
	else
			cout << "\n Search record not found ";
}


void Database :: modify(char name[])
{
	Student *last=NULL;
	int flag=0,key=0,ch;

	key = division_method(name);

	last = s[key].next;
	while(last!=NULL)
	{
		if(strcmp(last->name,name) == 0)
		{
				flag=1;
				break;
		}

		last = last->next;
	}

	if(flag==1)
	{
			cout << "\n Search record found ....";
			do
			{
				cout << "\n 1 : Division 2: Class 3 : rollno 4 : Exit ";
				cout << "\n Enter u  choice  : ";
				cin >> ch;
				switch(ch)
				{
					case 1 : cout << "\n Enter new division : ";
							 cin >> last->divi;
							 break;
					case 2 : cout << "\n Enter new branch : ";
							 cin >> last->type;
							 break;
					case 3 : cout << "\n Enter new rollno : ";
							 cin >> last->rollno;
							 break;
				}
			}while(ch!=4);
	}
	else
			cout << "\n Search record not found ";
}
void Database :: display()
{
	Student *last=NULL;

	for(int i=0;i<MAX;i++)
	{
		cout << "\n Elements at key "<<s[i].data ;

		last = s[i].next;
		while(last!=NULL)
		{
			putstud(last);
			last = last->next;
		}
	}
}
Student * Database :: getnode()
{
	Student *temp=NULL;

	temp = new Student;
	if(temp == NULL)
		cout << "\n Memory allocaiton error ";
	else
	{
		temp->next = NULL;
	}
	return temp;
}

void Database :: add()
{
	Student *temp=NULL,*last=NULL;
	char ch;
	int key;
	do
	{

		temp = getnode();
		getstud(temp);

		cout << " " << temp->name;
		key = division_method(temp->name);


		if( s[key].next == NULL)
		{
			s[key].next = temp;
		}
		else
		{
			last = s[key].next;
			while(last->next!=NULL)
				last = last->next;

			last->next = temp;
		}

		cout << "\n Node added ... "<<temp->name;

		cout << "\n Do you want to add more y.n -> ";
		cin >> ch;
	}while(ch!='n');
}


int Database :: division_method(char name[])
{
	int i=0,sum=0;


	while(name[i]!='\0')
	{
		sum = sum + name[i];
		i++;
	}

	return sum % MAX;
}

void Database::menu(){
	char ch;
	char name[20];
	int x;

	do{
		cout<<"Which method do you want to implement ?"<<endl;
		cout<<"1.Add record"<<endl;
		cout<<"2.Display"<<endl;
		cout<<"3.Delete record"<<endl;
		cout<<"4.Modify record"<<endl;
		cout<<"5.Search record"<<endl;
		cin>>x;
		switch(x){
			case 1:
					add();
					break;
			case 2:
					display();
					 break;
			case 3:         cout<<"Enter name to be searched:\n";
					cin>>name;
				       // delete1(name);
					break;
			case 4:		cout<<"Enter name to be searched:\n";
					cin>>name;
					modify(name);
					break;
			case 5:		cout<<"Enter name to be searched:\n";
					cin>>name;
					search(name);
					break;

			default :
					cout<<  "Invalid Operation"<<endl;
					break;
		}
		cout<<"\nDo you want to continue the operation"<<endl;
		cin>>ch;
	}
	while(ch=='y' || ch=='Y');

}
int main()
{
	Database obj;
	obj.menu();
}


 */

//============================================================================
// Name        : Assignment7.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright  : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string>
using namespace std;
class Symbol
{
	public:
	string identef;
	int val;
	friend class HashTable;
};
class HashTable
{
	Symbol S[50];
	int chain[50];
	public:
	HashTable()
	{
		for(int i=0;i<50;i++)
		{
			S[i].identef="\0";
			S[i].val=chain[i]=-1;
		}
	}
	int hashFunc(string);
	void disp();
	void printInfo(int);
	void insertWithReplacement(string,int);
	int searchWithReplacement(string,int&);
	void modifyWithReplacement(string,int);
	void delWithReplacement(string);
	void insertWoReplacement(string,int);
	int searchWoReplacement(string,int&);
	void modifyWoReplacement(string,int);
	void delWoReplacement(string);
	void upAdjust(int);
};
void HashTable::printInfo(int i)
{
	cout<<"Idx\t\tIdent\t\tVal\n";
	cout<<i<<"\t\t"<<S[i].identef<<"\t\t"<<S[i].val<<"\n";
}
void HashTable::disp()
{
	cout<<"Idx\t\tIdent\t\tVal\t\tChain\n";
	for(int i=0;i<50;i++)
	{
		if(S[i].identef!="\0")
			cout<<i<<"\t\t"<<S[i].identef<<"\t\t"<<S[i].val<<"\t\t"<<chain[i]<<"\n";
	}
}
int HashTable::hashFunc(string str)
{
	int i=0,ans=0;
	while(str[i]!='\0')
	{
		ans=ans+(int)str[i];
		i++;
	}
	return ans%50;
}
void HashTable::insertWithReplacement(string idnt,int v)
{
	int idx=hashFunc(idnt);
	if(S[idx].identef=="\0")
	{
		S[idx].identef=idnt;
		S[idx].val=v;
		return;
	}
	int temp=hashFunc(S[idx].identef);
	if(temp==idx)
	{
		int c=idx,i=idx+1;
		while(S[i].identef!="\0")
			i=(i+1)%50;
		while(chain[c]!=-1)
			c=chain[c];
		S[i].identef=idnt;
		S[i].val=v;
		chain[c]=i;
	}
	else
	{
		int i=idx+1;
		while(S[i].identef!="\0")
			i=(i+1)%50;
		int c=temp;
		while(chain[c]!=idx)
			c=chain[c];
		chain[c]=chain[idx];
		while(chain[c]!=-1)
			c=chain[c];
		S[i]=S[idx];
		chain[c]=i;
		S[idx].identef=idnt;
		S[idx].val=v;
		chain[idx]=-1;
	}
}
int HashTable::searchWithReplacement(string str,int &col)
{
	int idx=hashFunc(str);
	if(S[idx].identef==str)
	{
		col=0;
		return idx;
	}
	if(hashFunc(S[idx].identef)==idx)
	{
		col=1;
		int c=idx;
		while(chain[c]!=-1)
		{
			c=chain[c];
			if(S[c].identef==str)
				return c;
			else
				col++;
		}
		col=-1;
		return -1;
	}
	else//Ele not present
	{
		col=-1;
		return -1;
	}
}
void HashTable::modifyWithReplacement(string str,int tar)
{
	int col=0,idx=searchWithReplacement(str,col);
	if(idx==-1)
	{
		cout<<"Identifier Not Present\n";
		return;
	}
	S[idx].val=tar;
}
void HashTable::delWithReplacement(string str)
{
	int col=0,idx=searchWithReplacement(str,col);
	if(idx==-1)
	{
		cout<<"Identifier Not Present\n";
		return;
	}
	int i=hashFunc(str);
	if(i==idx)//First Ele in Chain
	{
		if(chain[i]==-1)
		{
			S[i].identef="\0";
			S[i].val=-1;
			return;
		}
		int c=chain[i];
		S[i]=S[c];
		chain[i]=chain[c];
		S[c].identef="\0";
		S[c].val=-1;
		return;
	}
	int c=i;
	while(chain[c]!=idx)
		c=chain[c];
	chain[c]=chain[idx];
	S[idx].identef="\0";
	S[idx].val=-1;
}
void HashTable::insertWoReplacement(string str,int val)
{
	int idx=hashFunc(str);
	if(S[idx].identef=="\0")
	{
		S[idx].identef=str;
		S[idx].val=val;
		return;
	}
	int i=(idx+1)%50;
	bool flag=true;
	while(S[i].identef!="\0")
		i=(i+1)%50;
	int c=idx;
	while(hashFunc(S[c].identef)!=idx)
	{
		c=(c+1)%50;
		if(c==idx)
		{
			break;
			flag=false;
		}
	}
	while(chain[c]!=-1)
		c=chain[c];
	if(flag&&hashFunc(S[c].identef)==idx)
		chain[c]=i;
	S[i].identef=str;
	S[i].val=val;
}
int HashTable::searchWoReplacement(string str,int &col)
{
	int idx=hashFunc(str);
	if(S[idx].identef==str)
	{
		col=0;
		return idx;
	}
	if(idx==hashFunc(S[idx].identef))
	{
		int c=chain[idx];
		col=1;
		while(c!=-1)
		{
			if(S[c].identef==str)
				return c;
			else
				col++;
			c=chain[c];
		}
		return -1;
	}
	int i=idx+1;
	col=1;
	while(hashFunc(S[i].identef)!=idx&&i!=idx)
	{
		col++;
		i=(i+1)%50;
	}
	if(i==idx)
		return -1;
	if(S[i].identef==str)
		return i;
	int c=chain[i];
	while(c!=-1&&S[c].identef!=str)
		c=chain[c];
	return c;
}
void HashTable::modifyWoReplacement(string str,int v)
{
	int col=0,idx=searchWoReplacement(str,col);
	if(idx==-1)
	{
		cout<<"Identifier Not Present\n";
		return;
	}
	S[idx].val=v;
}
void HashTable::delWoReplacement(string str)
{
	int col=0,idx=searchWoReplacement(str,col);
	if(idx==-1)
	{
		cout<<"Identifier Not Present\n";
		return;
	}
	int i=hashFunc(str),pos=0;
	while(S[pos].identef=="\0")
		pos=(pos+1)%50;
	while(hashFunc(S[pos].identef)!=i)
	{	
		pos=(pos+1)%50;
		while(S[pos].identef=="\0")
			pos=(pos+1)%50;
		if(pos==0)
			break;
	}
	i=pos;
	if(i==idx)
	{
		if(chain[i]==-1)
		{
			S[i].identef="\0";
			S[i].val=-1;
			upAdjust(i);
			return;
		}
		int c=chain[i];
		S[i]=S[c];
		chain[i]=chain[c];
		S[c].identef="\0";
		S[c].val=-1;
		chain[c]=-1;
		upAdjust(c);
		return;
	}
	int c=i;
	while(chain[c]!=idx)
		c=chain[c];
	chain[c]=chain[idx];
	S[idx].identef="\0";
	S[idx].val=-1;
	chain[idx]=-1;
	upAdjust(idx);
}
void HashTable::upAdjust(int i)
{
	int start=i,idx=i;
	i=(idx+1)%50;
	//cout<<i<<"\n";
	while(true)
	{
		if(idx==hashFunc(S[i].identef))
		{
			S[idx]=S[i];
			chain[idx]=chain[i];
			S[i].identef="\0";
			S[i].val=-1;
			chain[i]=-1;
			idx=i;
		}
		i=(i+1)%50;
		if(i==start)
			break;	
	}
}
int main()
{
	HashTable H1,H2;
	string str,tar;
	int ch1,ch2,val,col=0;
	do
	{
		cout<<"Enter\n1 For Without Replacement\n2 For With Replacement\n0 To EXIT\n";
		cin>>ch1;
		switch(ch1)
		{
			case 1:
			do
			{
				cout<<"Enter\n1 To Insert\n2 To Search\n3 To Modify\n4 To Remove\n0 To Prev Menu\n";
				cin>>ch2;
				cin.ignore();
				switch(ch2)
				{
					case 1:
						cout<<"Enter the Identifier\n";
						getline(cin,str);
						cout<<"Enter it's value\n";
						cin>>val;
						H1.insertWoReplacement(str,val);
						H1.disp();
						break;
					case 2:
					{
						cout<<"Enter the Identifier To Search\n";
						getline(cin,str);
						int i=H1.searchWoReplacement(str,col);
						if(i!=-1)
						{
							H1.printInfo(i);
							cout<<"No.of Collisions is/are "<<col<<"\n";
						}
						else
							cout<<"Element not found\n";
						break;
					}
					case 3:
						cout<<"Enter the Identifier to Modify\n";
						getline(cin,str);
						cout<<"Enter new Value\n";
						cin>>val;
						H1.modifyWoReplacement(str,val);
						H1.disp();
						break;
					case 4:
						cout<<"Enter the String to Remove\n";
						getline(cin,str);
						H1.delWoReplacement(str);
						H1.disp();
						break;
					case 0:
						break;
				}
			}while(ch2);
			break;
			case 2:
			do
			{
				cout<<"Enter\n1 To Insert\n2 To Search\n3 To Modify\n4 To Remove\n0 To Prev Menu\n";
				cin>>ch2;
				cin.ignore();
				switch(ch2)
				{
					case 1:
						cout<<"Enter the Identifier\n";
						getline(cin,str);
						cout<<"Enter it's value\n";
						cin>>val;
						H2.insertWithReplacement(str,val);
						H2.disp();
						break;
					case 2:
					{
						cout<<"Enter the Identifier To Search\n";
						getline(cin,str);
						int i=H2.searchWithReplacement(str,col);
						if(i!=-1)
						{
							H2.printInfo(i);
							cout<<"No.of Collisions is/are "<<col<<"\n";
						}
						else
							cout<<"Element not found\n";
						break;
					}
					case 3:
						cout<<"Enter the Identifier to Modify\n";
						getline(cin,str);
						cout<<"Enter new Value\n";
						cin>>val;
						H2.modifyWithReplacement(str,val);
						H2.disp();
						break;
					case 4:
						cout<<"Enter the String to Remove\n";
						getline(cin,str);
						H2.delWithReplacement(str);
						H2.disp();
						break;
					case 0:
						break;
				}
			}while(ch2);
			break;
			case 0:
				cout<<"You have opted to EXIT\n";
				break;
			default:
				cout<<"Invalid Choice\n";
		}
	}while(ch1);
	return 0;
}
