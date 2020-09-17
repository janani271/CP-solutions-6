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

ll n,m,i,u,v,w,tot;
vll g[MAX];
map<pairs,ll>p;

void dfs(ll x)
{
	for(auto it:g[x])
	{
		for(auto i:g[it])
		{
			if(i!=x) p[{x,i}]++;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
	}

	for(i=0;i<n;i++) dfs(i);

	tot=0;
	for(auto it:p)
	{
		u = it.first.first;
		v = it.first.second;
		w = it.second;
		if(w>=2) tot += (w*(w-1))/2;	
	}
	cout<<tot;
	return 0;
}