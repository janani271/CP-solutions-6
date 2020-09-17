#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 2004

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll dp[MAX][MAX],a,n,m,rain[MAX],umb[MAX],idx,weight[MAX];

ll calc(ll i, ll j)
{
	if(i==a) return 0;
	if(dp[i][j]!=-1) return dp[i][j]; 
	
	dp[i][j] = INF;
	//continue with or without umbrella
	if(j>0) dp[i][j] = min(dp[i][j], calc(i+1,j)+weight[j]); 
	//drop at i
	if(rain[i]==0) dp[i][j] = min(dp[i][j], calc(i+1,0));
	//pick up at i
	if(umb[i]!=-1) dp[i][j] = min(dp[i][j], calc(i+1,umb[i])+weight[umb[i]]);
	// cout<<"i : "<<i<<"\tj : "<<j<<"\tdp : "<<dp[i][j]<<"\n";
	return dp[i][j];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll l,r;
	cin>>a>>n>>m;
	for(ll i=1;i<=n;i++)
	{	
		cin>>l>>r;
		for(ll j=l;j<r;j++) rain[j] = 1;
	}
	for(ll i=0;i<a;i++) umb[i] = -1;
	for(ll i=1;i<=m;i++)
	{
		cin>>idx>>weight[i];
		if(umb[idx]==-1) umb[idx] = i;
		else if(weight[i]<weight[umb[idx]]) umb[idx] = i;
	}
	memset(dp,-1,sizeof dp);
	ll ans = calc(0,0);
	if(ans==INF) cout<<-1;
	else cout<<ans;
	return 0;
}