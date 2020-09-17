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


ll n,i,u[MAX],v[MAX],w[MAX],mxleaf,tot,cost[MAX];
vector<pairs> g[MAX];
stack<pairs>st;
map<pairs,int>m;

void dfs(ll x, ll par, ll c)
{
	cost[x] = c;
	for(auto it:g[x])
	{
		if(it.first==par) continue;
		dfs(it.first,x,c+it.second);
	}
}

void find_path(ll x, ll par)
{
	if(x==mxleaf)
	{
		while(!st.empty())
		{
			pairs cur = st.top();
			st.pop();
			ll x = cur.first, y = cur.second;
			m[{min(x,y),max(x,y)}] = 1;
		}
		return;
	}
	for(auto it:g[x])
	{
		if(it.first==par) continue;
		st.push({x,it.first});
		find_path(it.first,x);
		if(!st.empty()) st.pop();
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		g[u[i]].pb({v[i],w[i]});
		g[v[i]].pb({u[i],w[i]});
	}
	dfs(1,-1,0);
	mxleaf = -1;
	for(i=1;i<=n;i++)
	{
		if(g[i].size()==1) //leaf node
		{
			if(mxleaf == -1) mxleaf = i;
			else if(cost[mxleaf]<cost[i]) mxleaf = i;
		}
	}
	find_path(1,-1);
	for(i=0;i<n-1;i++)
	{
		tot += w[i];
		ll x = u[i], y = v[i];
		if(m.find({min(x,y),max(x,y)})==m.end()) tot+=w[i];
	}
	cout<<tot;
	return 0;
}