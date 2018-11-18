#include<bits/stdc++.h>
using namespace std;
int max_size,n;string s;
vector<int> input;

void Knapsack(){
	int dp[n+1][max_size+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=max_size;j++){
			if(input[i-1] <= j){
				dp[i][j] =max(dp[i-1][j] , dp[i-1][j-input[i-1]]+input[i-1]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	int res=dp[n][max_size];
	int temp=res;
	for(int i=n;i>0 && res>0; i--){
		if(dp[i-1][res] ==res){
			continue;
		}
		else{
			cout<<input[i-1]<<" ";
			res-=input[i-1];
		}
	}
	cout<<"sum:"<<temp<<endl;
}
int main(){
	while(getline(cin,s)){
		int i;
		input.clear();
		stringstream ss(s);
		ss>>max_size;
		ss>>n;
		while(ss>>i){
			input.push_back(i);
		}
		Knapsack();
	}
}
