//============================================================================
// Name        : Assignment10.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<iomanip>
using namespace std;
class Student
{
	int roll,div;
	char name[50],address[50];
	public:
	Student()
	{
		roll=div=-1;
		name[0]=address[0]='\0';
	}
	Student(int r,int d,char n[50],char adr[50])
	{
		roll=r;
		div=d;
		strcpy(name,n);
		strcpy(address,adr);
	}
	void displayRecord()
	{
		cout<<name<<"\t\t"<<roll<<"\t\t"<<div<<"\t\t"<<address<<"\n";
	}
	friend class Record;
};
class Record
{
	char fname[50];
	public:
	Record()
	{
		fname[0]='\0';
	}
	Record(char fn[50])
	{
		strcpy(fname,fn);
	}
	void displayAll();
	void insertRec(int,int,char[],char[]);
	void removeRec(char[]);
	void showData(char[]);
};
void Record::insertRec(int roll,int div,char name[50],char address[50])
{
	ofstream fptr(fname,ios::app);
	Student temp(roll,div,name,address);
	fptr.write((char*)&temp,sizeof(temp));
	fptr.close();
}
void Record::showData(char name[50])
{
	ifstream fptr(fname,ios::in);
	Student T1;
	bool found=false;
	fptr.seekg(0,ios::beg);
	while(fptr.read((char*)&T1,sizeof(T1)))
	{
		if(strcmp(T1.name,name)==0)
		{
			found=true;
			break;
		}
	}
	if(!found)
	{
		cout<<"Record not present in the database\n";
		return;
	}
	cout<<"Name\t\tRoll no\t\tDiv\t\tAddress\n";
	T1.displayRecord();
	fptr.close();
	//fptr.clear();
}
void Record::displayAll()
{
	//cout<<"ALL RECORDS IN FILE ARE\n";
	ifstream fptr(fname);
	Student T1;
	if(fptr.good())
		cout<<"Name\t\tRoll\t\tDiv\t\tAddress\n";
	while(!fptr.eof())
	{
		fptr.read((char*)&T1,sizeof(T1));
		if(!fptr.eof())
		{
			T1.displayRecord();
		}
	}
	fptr.close();
}
void Record::removeRec(char name[50])
{
	bool found=false;
	Student T1;
	ifstream fptr(fname);
	ofstream fout("temp.txt");
	fptr.seekg(0,ios::beg);
	while(fptr.good())
	{
		fptr.read((char*)&T1,sizeof(T1));
		if(strcmp(T1.name,name)!=0&&!fptr.eof())
		{
			fout.write((char*)&T1,sizeof(T1));
		}
		else
			found=true;
	}
	fout.close();
	if(!found)
	{
		remove("temp.txt");
		cout<<"Record is not present in the database\n";
		return;
	}
	fptr.close();
	remove("Database.txt");
	rename("temp.txt","Database.txt");
	fptr.open("Database.txt",ios::in|ios::out|ios::ate);
	//fptr.clear();
	fptr.close();
}
int main()
{
	ofstream fout("Database.txt");
	fout.close();
	Record R1((char*)"Database.txt");
	int choice,roll,div;
	char name[50],address[50];
	do
	{
		cout<<"Enter\n1 To Insert a Record\n2 To Delete a Record\n3 To Display All Records\n";
		cout<<"4 To Display Record of given name\n0 To EXIT\n";
		cin>>choice;
		cin.ignore();
		switch(choice)
		{
		case 1:
			cout<<"Enter Name\n";
			cin.getline(name,48);
			cout<<"Enter Address\n";
			cin.getline(address,48);
			cout<<"Enter Roll no and Div\n";
			cin>>roll>>div;
			R1.insertRec(roll,div,name,address);
			break;
		 case 2:
			cout<<"Enter Name, whose record is to be deleted\n";
			cin.getline(name,48);
			R1.removeRec(name);
			break;
		case 3:
			R1.displayAll();
			break;
		case 4:
			cout<<"Enter Name whose record is to be displayed\n";
			cin.getline(name,48);
			R1.showData(name);
			break;
		case 0:
			cout<<"You have opted to EXIT\n";
			break;
		default:
			cout<<"Invalid Choice\n";
		}
	}while(choice);
	return 0;
}
