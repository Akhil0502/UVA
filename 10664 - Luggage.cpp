#include<bits/stdc++.h>
using namespace std;
vector<int> input;
string s;
int i;long long sum=0,te;
string Knapsack(){
	sum/=2;
	int n=input.size();
	int dp[n+1][sum+1];memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(input[i-1] <= j ){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-input[i-1]]+input[i-1]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][sum]*2==te?"YES":"NO";
}
int main(){
	int t;cin>>t;getline(cin,s);
	while(t--){
		input.clear();
		getline(cin,s);sum=0;
		stringstream ss(s);
		while(ss>>i){
			input.push_back(i);
			sum+=i;
		}
		te=sum;
		cout<<Knapsack()<<endl;
	}
}
