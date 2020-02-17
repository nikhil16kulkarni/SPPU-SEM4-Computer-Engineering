//============================================================================
// Name        : Assignment6.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#define MAX 50
using namespace std;

class Entry{
	string word;
	string mean;
public:

	friend class HashTable;

};

class HashTable{
	Entry e[MAX];

public:
	HashTable(){
		int i;
		for(i=0;i<MAX;i++){
			e[i].word="";
			e[i].mean="";
			//strcpy(e[i].word,"NULL");
			//strcpy(e[i].mean,"NULL");
		}
	}


	void insert(string, string);
	void display();
	int search(string);
	void delete_word(string);

};

int HashTable::search(string w){
	int i;
	for(int i=0;i<MAX;i++){
		if(e[i].word==w){
			cout<<"\n"<<e[i].word<<" Found at location "<<i<<" having meaning "<<e[i].mean<<"\n";
			return i;
		}
	}
	if(i==MAX){
		cout<<"\nWord "<<w<<" not found !\n";
		return -1;
	}
}

void HashTable::delete_word(string w){
	int found=search(w);
	if(found==-1){
		cout<<"\n Word not found \n";
	}
	else{
		strcpy(e[found].word,"NULL");
		strcpy(e[found].mean,"NULL");
		cout<<"\nWord Deleted !\n";
	}
}

void HashTable::display(){
	int i;
	cout<<"\n\tWORD\t\tMEANING";
	for(i=0;i<MAX;i++){
		cout<<"\n\t"<<e[i].word<<"\t\t"<<e[i].mean;
	}
}

void HashTable::insert(){



}

int main() {
	HashTable h;
	int ch;
	char yn;
	do{
		cout<<"\nEnter Choice : \n1.Create\n2.Display\n3.Search\n4.Delete\n";
		cin>>ch;
		switch(ch){
		case 1: h.insert();
				break;
		case 2: h.display();
				break;
	/*	case 3: char s[20];
				cout<<"Enter word to be searched : \n";
				cin>>s;
				h.search(s);
				break;
		case 4: char d[20];
				cout<<"Enter word to be deleted : \n";
				cin>>d;
				h.delete_word(d);
				break;*/
		default: cout<<"Incorrect Choice Entered\n";
		}
		cout<<"Do you want to continue?(y/n)";
		cin>>yn;
	}while(yn=='y' || yn=='Y');
}
