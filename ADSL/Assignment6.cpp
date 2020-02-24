//============================================================================
// Name        : Assignment6.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*#include <iostream>
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
	}.////////////////////
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
	/.*	case 3: char s[20];
				cout<<"Enter word to be searched : \n";
				cin>>s;
				h.search(s);
				break;
		case 4: char d[20];
				cout<<"Enter word to be deleted : \n";
				cin>>d;
				h.delete_word(d);
				break; *./
		default: cout<<"Incorrect Choice Entered\n";
		}
		cout<<"Do you want to continue?(y/n)";
		cin>>yn;
	}while(yn=='y' || yn=='Y');
} */

/*
#include <iostream>
#include <string>
using namespace std;

const int N = 30;

class Pair{
	private:
		string key ,val;
		int id;
		bool already, probed;
	public:
		Pair(){
			key.clear(), val.clear();
			id = 0, already = false, probed = false;
		}
		friend class hashTable;
};

class hashTable{
	private:
		int sz;
		Pair table[N];
	public:
		hashTable(){
			sz = N;
		}
		int hash(string &key){
			int func = 0;
			for(int i = 0; i < (int)key.size(); i++)
				func += (key[i] - (key[i] >= 'a' && key[i] <= 'z'? 'a':'A') + 1) * (i);
			func %= sz;
			return func;
		}
		void insert(string &key, string &val){
			int idx = hash(key);
			Pair &curr = table[idx];
			if(curr.already == false){
				curr.already = true;
				curr.key = key;
				curr.val = val;
				curr.id = idx;
				cout << "Hash achieved ;)" << '\n';
			}else{
				if(curr.key == key){
					cout << "Key " << key << " already present" << '\n';
					return;
				}
				int i = 0;
				for(; i < sz; i++){
					if(table[i].already == false)
						break;
				}

				Pair &curr = table[i];
				curr.already = true;
				curr.probed = true;
				curr.key = key , curr.val = val;
				curr.id = i;
				cout << "Linearly probed :(" << '\n';
			}
		}
		void search(string key){
			int itr = 0;
			int id = hash(key);
			if(table[id].key == key){
				cout << key << " was searched using hashed function " << '\n';
				cout << key << " : " << table[id].val << '\n';
			}else{
				int ind = 0;
				for(int i = id; i < sz; i++, itr++)
					if(table[i].key == key){ << "====================" 
						ind = i;
						break;
					}
				cout << key << " was searched linearly in " << itr << " operations " << '\n';
				cout << key << " : " << table[ind].val << '\n';
			}
		}
		void seeContents(){
			for(int i = 0; i < sz; i++){
				Pair &curr = table[i];
				cout << i+1 << ") " << curr.key << " : " << curr.val << " ";
				cout << (curr.probed ? "Probed" : "Hashed") << " ";
				cout << "id = " << curr.id << '\n';
			}
		}

};


int main() {

	//Without replacement
	hashTable T;
	cout << "Linear probing without replacement " << endl;
	char ch = 'y';
	while(ch == 'y'){
		cout << "1) Insert an entry " << '\n';
		cout << "2) Search meaning of a key" << '\n';
		cout << "3) See contents of the Hash Table " << '\n';
		int tc;	cin >> tc;
		if(tc == 1){
			cout << "Key = ";	string key;	cin >> key;
			cout << "Meaning = ";	string val;	cin >> val;
			T.insert(key, val);
		}else if(tc == 2){
			cout << "Enter the key to search for :";
			string key;	cin >> key;
			T.search(key);
		}else if(tc == 3){
			T.seeContents();
		}else break;
	}

	//With replacement

	return 0;
} */

#include <iostream>
using namespace std;

class node{
	string key,meaning;
public:
	friend class HashTable;
};

class HashTable{
	node* HT;
	int n;
public:
	HashTable(int d){
		n=d;
		HT=new node[n];
		for(int i=0;i<n;i++)
			HT[i].key="#";
	}
	void create();
	void withoutinsert(node); //linear probing without replacement
	void withinsert(node);	//linear probing with replacement
	void find();
	void del();
	void disp(){
		for(int i=0;i<n;i++)
			cout<<HT[i].key<<"\n";
	}

};


void HashTable::del(){
	string k;
	cout<<"\nEnter key of element to be deleted";
	cin>>k;

	int l=k.length()%n;

	if(HT[l].key==k){
		HT[l].key="#";
		HT[l].meaning="";
		cout<<"\nDELETED SUCCESSFULLY";
	}
	else{
		int i;
		for(i=(l+1)%n;i!=l && HT[i].key!=k;i=(i+1)%n);
		if(i==l)
			cout<<"\nENTRY DOES NOT EXISTS";
		else{
			HT[i].key="#";
			HT[i].meaning="";
			cout<<"\nDELETED SUCCESSFULLY";
		}
	}
}



void HashTable::find()
{
string k;

cout<<"\nEnter key of element to be found";
cin>>k;

int l=k.length()%n;

	if(HT[l].key==k)
		cout<<"\nFOUND!\n"<<HT[l].key<<" - "<<HT[l].meaning;
	else
	{	int i;
		for(i=(l+1)%n;i!=l && HT[i].key!=k;i=(i+1)%n);
		if(i==l)
			cout<<"\nNOT FOUND!";
		else
			cout<<"\nFOUND!\n"<<HT[i].key<<" - "<<HT[i].meaning;
	}
}




void HashTable::withoutinsert(node nn){
	int l=nn.key.length()%n;
	int i;
	for(i=l;HT[i].key!="#";i=(i+1)%n);
	HT[i]=nn;
	
	for(int i=0;i<n;i++)
		cout<<HT[i].key<<"\n";
}


void HashTable::withinsert(node nn){
	int l=nn.key.length()%n;
	if(HT[l].key=="#"){
		HT[l]=nn;
	}
	else{
		if(HT[l].key.length()%n==l){
			int i;
			for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
			HT[i]=nn;
		}
		else{
			node temp;
			temp=HT[l];
			HT[l]=nn;
			int i;
			for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
			HT[i]=temp;
		}
	}
	for(int i=0;i<n;i++)	
		cout<<HT[i].key<<"\n";
}

void HashTable::create(){
	string k,m;
	int ch;
	cout<<"\nEnter type of Linear Probing: \n1. Without Replacement\n2. With Replacement";
	cin>>ch;
	while(ch!=1 && ch!=2)}
		cout<<"\nInvalid!";
		cout<<"\nEnter type of Linear Probing: \n1. Without Replacement\n2. With Replacement";
		cin>>ch;
	}

	for(int i=0;i<n;i++){
		node nn;
		cout<<"\n"<<i+1<<" Entry";
		cout<<"\nEnter key: ";
		cin>>nn.key;
		cout<<"Enter meaning: ";
		cin>>nn.meaning;
		if(ch==1)
			withoutinsert(nn);
		if(ch==2)
			withinsert(nn);
	}
}




int main() {
	int n;
	cout<<"\nEnter number of dictionary entries: ";
	cin>>n;
	HashTable obj(n);
	obj.create();
	do{
		cout<<"\nSELECT OPTION\n1. Retrieve\n2. Delete\n3. Display";
		cin>>n;
		if(n==1)
		obj.find();
		if(n==2)
		obj.del();
		if(n==3)
		obj.disp();
	}
	while(n!=4);
	return 0;
}
