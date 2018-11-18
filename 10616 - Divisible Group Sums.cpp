#include<bits/stdc++.h>
using namespace std;
int n,noQueries,size,number,ans=0;
vector<int> input(200);	
int dp[205][200][15];
int calc(int size,int number,int sum, int start){
	if(size == 0 && sum%number == 0) return 1;
	if(size<=0) return 0;
	if(dp[start][sum][size] != -1) return dp[start][sum][size];
	int ret=0;
	for(int i=start;i<n;i++){
		ret+=calc(size-1,number,sum+input[i]%number,i+1);
	}
	return dp[start][sum][size]=ret;
}
int main(){
	int set=1;
	while(cin>>n>>noQueries){
	if(n==0 && noQueries==0) return 0;
	cout<<"SET "<<set++<<":"<<endl;
	memset(dp,-1,sizeof(dp));
	int q=1;
		for(int i=0;i<n;i++)cin>>input[i];
		for(int i=0;i<noQueries;i++){
			ans=0;
			cin>>number>>size;
			cout<<"QUERY "<<q++<<": ";
			cout<<calc(size,number,0,0)<<endl;
		}
	}
	return 0;
}
