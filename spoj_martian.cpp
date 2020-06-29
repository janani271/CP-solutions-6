#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 503

ll MOD=1e9+7;
ll j,i,n,m,dp[MAX][MAX],v[MAX][MAX],h[MAX][MAX],x;

ll calc(ll l , ll r)
{
	if(l<0 || r<0)
		return 0;

	if(dp[l][r]!=-1)
		return dp[l][r];

	dp[l][r] = max(calc(l,r-1)+v[l][r],calc(l-1,r)+h[l][r]);
	return dp[l][r];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;

	while(n && m)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>x;
				if(j!=0) h[i][j] = h[i][j-1] + x;
				else h[i][j] = x;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>x;
				if(i!=0) v[i][j] = v[i-1][j] + x;
				else v[i][j] = x;
			}
		}
		memset(dp,-1,sizeof dp);
		cout<<calc(n-1,m-1)<<"\n";
		cin>>n>>m;
	}
	return 0;
}