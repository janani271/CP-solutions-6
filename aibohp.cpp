#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 6105
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

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
string a,b;
ll t,n,i,lcs[MAX][MAX],j,dp[MAX][MAX];
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	while(t--)
	{
		cin>>a;
		b = a;
		reverse(a.begin(),a.end());
		n = a.length();
		for(i=0;i<=n;i++)
		{
			lcs[i][0]=0;
			lcs[0][i]=0;
		}
		// lcs[0][0]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j] = 1 + dp[i-1][j-1];
				}
				else
				{
					dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}

		cout<<n-dp[n][n]<<"\n";
	}
	return 0;
}