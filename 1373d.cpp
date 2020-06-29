#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200009

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,a[MAX],dp[MAX][5],i;

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
		cin>>n;
		for(i=0;i<n;i++) cin>>a[i];
		
		for(i=0;i<n;i++)
		{
			dp[i+1][0] = dp[i][0]+(i&1?0:a[i]);

			if(i+2<=n)
			dp[i+2][1] = max(dp[i][0],dp[i][1])+(i&1?a[i]:a[i+1]);

			dp[i+1][2] = max(dp[i][2],max(dp[i][0],dp[i][1]))+(i&1?0:a[i]);
		}
		cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<"\n";
	}
	return 0;
}