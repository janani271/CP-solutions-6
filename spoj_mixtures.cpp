#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 200

ll MOD=1e9+7;
ll n , p[MAX] , a[MAX], dp[MAX][MAX] , res,i;

ll calc(ll l , ll r)
{
	if(l>r || l<=0 || l>n || r<=0 || r>n)
		return 0;
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l==r)
		return dp[l][r]=0;
	if(abs(l-r)==1)
		return dp[l][r] = a[l]*a[r];

	ll lh , rh , ans , cur , k;
	ans = 1e18;
	// lh = calc(l,l);
	// rh = calc(l+1,r);
	// cur = a[l] * ((p[r]-p[l])%100);
	// ans = lh + rh + cur;
	for(k=l;k<r;k++)
	{
		lh = calc(l,k);
		rh = calc(k+1,r);
		cur = ((p[k]-p[l-1])%100) * ((p[r]-p[k])%100);
		ans = min(ans, lh+rh+cur);
	}
	return dp[l][r] = ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	// fastread;

	while(scanf("%d",&n)!=EOF)
	{
		p[0]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			p[i] = p[i-1]+a[i];
		}
		memset(dp,-1,sizeof dp);
		res = calc(1,n);
		cout<<res<<"\n";
	}
	return 0;
}