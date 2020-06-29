#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100

ll MOD=1e9+7;
ll dp[MAX][MAX],d,n,k,m[MAX],x,i;

ll calc(ll idx, ll sum)
{
	// cout<<"idx : "<<idx<<"\tsum : "<<sum<<"\n";
	if(sum<0 || idx>2*n) return 0;
	if(dp[idx][sum]!=-1)
		return dp[idx][sum];
	if(idx==2*n && sum==0)
		return dp[idx][sum] = 1;
	dp[idx][sum] = calc(idx+1,sum+1);
	if(m[idx+1]!=1)
		dp[idx][sum] += calc(idx+1,sum-1);
	// cout<<"index : "<<idx<<"\tsum : "<<sum<<"\tdp : "<<dp[idx][sum]<<"\n";
	return dp[idx][sum];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	// fastread;

	cin>>d;
	while(d--)
	{
		cin>>n>>k;
		memset(m,0,sizeof m);
		for(i=0;i<k;i++)
		{
			cin>>x;
			m[x]=1;
		}
		memset(dp,-1,sizeof dp);
		cout<<calc(1,1)<<"\n";
	}
	return 0;
}