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
ll INF = -3000009;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,a[MAX],i,j,cursum,prefix,ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll ans=0;
	for(i=0;i<31;i++)
	{
		ll cursum=0,prefix=0;
		for(j=0;j<n;j++)
		{
			cursum += (a[j]>i)?INF:a[j];
			prefix = min(prefix,cursum);
			ans = max(ans,cursum-prefix-i);
		}
	}
	cout<<ans;
	return 0;
}