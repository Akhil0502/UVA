#include<bits/stdc++.h>
using namespace std;
vector<int> input(100);int n;long long sum=0,te;
int Knapsack(){
	int dp[n+1][sum+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(input[i-1] <= j ){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-input[i-1]]+input[i-1]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return abs(te-(2*dp[n][sum]));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;sum=0;
		for(int i=0;i<n;i++){cin>>input[i];sum+=input[i];}
		te=sum;
		sum/=2;
		cout<<Knapsack()<<endl;
	}
}
