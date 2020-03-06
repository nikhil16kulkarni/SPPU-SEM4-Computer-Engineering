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
