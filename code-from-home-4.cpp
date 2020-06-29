#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003

ll MOD=1e9+7;

ll visited[MAX], dp[MAX][5], tp[MAX],n,i,u,v;
vll g[MAX]; 

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

void dfs(ll x)
{
	visited[x]=1;
	dp[x][tp[x]]=1;

	ll a , b , c , d;
	for(auto it:g[x])
	{
		if(!visited[it])
		{
			dfs(it);
			a = mul(dp[x][0],dp[it][0]);
			b = add(mul(dp[x][1],dp[it][0]),mul(dp[x][0],dp[it][1]));
			c = add(mul(dp[x][2],dp[it][0]),mul(dp[x][0],dp[it][2]));
			d = add(add(mul(dp[x][0],dp[it][3]),mul(dp[x][3],dp[it][0])),add(mul(dp[x][1],dp[it][2]),mul(dp[x][2],dp[it][1])));

			a = add(a , dp[x][0] * dp[it][3]);
			b = add(b , dp[x][1] * dp[it][3]); 
			c = add(c , dp[x][2] * dp[it][3]);
			d = add(d , dp[x][3] * dp[it][3]);
			
			dp[x][0]=a; dp[x][1]=b; dp[x][2]=c; dp[x][3]=d;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(i=0;i<n;i++)
	{
		cin>>tp[i];
	}
	dfs(0);
	cout<<dp[0][3];

	return 0;
}