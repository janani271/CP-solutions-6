#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,q,i,c[MAX],val[MAX],mx1,mx2,a,b,dp[MAX],mx;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>q;
	for(i=0;i<n;i++) cin>>val[i];
	for(i=0;i<n;i++)
	{
		cin>>c[i];
		c[i]--;
	}
	while(q--)
	{
		cin>>a>>b;
		for(i=0;i<n;i++) dp[i]=-INF;
		mx1 = c[0];
		mx2 = c[0];
		dp[c[0]] = b*val[0];
		ll res = max((ll)0,dp[c[0]]);
		for(i=1;i<n;i++)
		{
			if(dp[c[i]]!=-INF) dp[c[i]] = max(dp[c[i]],dp[c[i]] + (val[i]*a));
			dp[c[i]] = max(dp[c[i]],b*val[i]);

			if(mx1!=c[i]) mx = dp[mx1];
			else if(mx2!=c[i]) mx = dp[mx2]; 
			else mx=0;

			dp[c[i]] = max(dp[c[i]],mx+(b*val[i]));

			if(c[i]!=mx1)
			{
				if(dp[c[i]]>dp[mx1])
				{
					mx2 = mx1;
					mx1 = c[i];
				}
				else if(dp[c[i]]>dp[mx2]) mx2 = c[i];
			}
			res = max(res,dp[c[i]]);
		}
		cout<<res<<"\n";
	}
	return 0;
}