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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>main;
	for(i=0;i<n;i++)
	{
		cin>>pos;
		cin>>s;
		if(pos=="DEF") def.pb(s);
		else atkj.pb(s);
	}
	for(i=0;i<m;i++)
	{
		cin>>s;
		atkc.pb(s);
	}
	sort(all(def)); sort(all(atkj)); sort(all(atkc));
	len1 = def.size();
	len2 = n-len1;
	i=len2-1; j=m-1;

	return 0;
}