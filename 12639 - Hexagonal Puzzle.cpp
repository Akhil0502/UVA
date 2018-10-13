#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int index(vector<int> &d, int p){
	for(int i=0;i<6;i++){
		if(d[i] == p)
			return i;
	}
	return -1;
}

bool isPresent(vector<vector<int> > &data, int a, int b, int c, int d){
	int l=index(data[b],data[a][d-1]);
	int r=index(data[c],data[a][d%6]);
	if(l == 0){l=5;}
	else {l--;}
	if(r==5){r=0;}
	else {r++;}
	return data[b][l] == data[c][r];
}

bool arrange(bool visit[], vector<vector<int> > &data,int a,int b, int c, int n){
	if(n == 6){	
		return isPresent(data,a,c,b,n);
	}
	else{
		for(int i=0;i<7;i++){	
			if( !visit[i] ){
				if( c == -1 || isPresent(data,a,c,i,n)){
					visit[i]=true;
					if(n == 0)b=i;
					if(arrange(visit,data,a,b,i,n+1)){
						return true;
					}
					visit[i]=false;
				}				
			}
		}	
		return false;
	}	
}

string util(vector<vector<int> > &data){
		bool visit[7];
		memset(visit,0,sizeof(visit));
		for(int i=0;i<7;i++){
		
			visit[i] = true;
			if(arrange(visit,data,i,-1,-1,0))
				return "YES";
			visit[i] =false;
		}
		return "NO";
}
int main()
{
	int p;
	vector<vector<int> > data;
	vector<int> v;
	while(cin>>p)
	{
		v.push_back(p);
		if(v.size() == 6){
			data.push_back(v);
			v.clear();
		}
		if(data.size() == 7){
			cout<<util(data)<<endl;
			data.clear();
		}
	}


    return 0;
}
