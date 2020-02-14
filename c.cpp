//============================================================================
// Name        : c.cpp
// Author      : Nikhil Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		char mo;
		ll ti;
		ll m[n],t[n];
		for(ll i=0;i<n;i++){
			cin>>mo>>t;
			m[i]=mo-65;
			if(t==12)	t[i]=0;
			else if(t[i]==3)	t[i]=1;
			else if(t[i]==6)	t[i]=2;
			else	t[i]==3;
			//cout<<m[i]<<" "<<t[i]<<endl;
		}
		ll mat[4][4]={0};
		for(ll i=0;i<4;i++){
			for(ll j=0;j<4;j++){

			}
		}

	}
}
