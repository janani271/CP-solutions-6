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

ll l,r,ans;

//pos->current bit
//la=1 if a>l, ra=1 if a<r, lb=1 if b>1, rb=1 if b<r
ll calc(ll pos, ll la, ll ra, ll lb, ll rb)
{
	if(pos==-1) return 0;
	if(dp[pos][la][ra][lb][rb]!=-1) return dp[pos][la][ra][lb][rb];
	cur = 1<<pos;
	if((r&cur || ra) && (lb || !(r&cur)))
	{
		if(la==0 && !(l&cur))
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>l>>r;
	ans=0;
	ans = calc(63,0,0,0,0);
	cout<<ans;
	return 0;
}