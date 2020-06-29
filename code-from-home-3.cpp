#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 1003

ll MOD=1e9+7;

ll n , i , a[MAX], dp[MAX][MAX], k,m,ans,q;

ll calc(ll x, ll y)
{
	if(x<0 || y<0) return 0;
	
	if(dp[x][y]!=-1) return dp[x][y];
	
	if(y==0) return dp[x][y]=1;
	if(x==0) return dp[x][y]=0;

	ll val = ((calc(x-1,y-1)%MOD) * a[x])%MOD;
	val = (val + (calc(x-1,y)%MOD))%MOD;
	return dp[x][y] = val; 
}


int main()
{
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	// fastread;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>q;
	memset(dp,-1,sizeof dp);
	for(i=0;i<q;i++)
	{
		cin>>k>>m;
		ans = calc(k,m);
		cout<<ans<<"\n";
	}
	return 0;
}
