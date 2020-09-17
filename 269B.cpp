#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 5003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,i,s[MAX],mx,j,dp[MAX];
long double x;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i]>>x;
	}

	ll mx=1;
	for(i=0;i<n;i++) dp[i] = 1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s[j]<=s[i])
				dp[i] = max(dp[i],dp[j]+1);
		}
		mx = max(dp[i],mx);
	}
	cout<<n-mx;
	return 0;
}