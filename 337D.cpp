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

ll n,m,d,i,p,mark[MAX],visited[MAX],u,v,distdown[MAX],distUp[MAX];
vll g[MAX];

void dfs(ll x)
{
	visited[x]=1;
	distdown[x] = mark[x]-1;
	for(auto it:g[x])
	{
		if(visited[it]) continue;
		dfs(it);
		if(distdown[it]>-1) distdown[x] = max(distdown[x],distdown[it]+1);
	}
}

void dfs1(ll x,ll par)
{
	visited[x]=1;
	//top 2 max values of child nodes
	ll mx1 = -1, mx2 = -1;
	for(auto it:g[x])
	{
		if(it==par) continue;
		if(distdown[it]>mx1)
		{
			mx2 = mx1;
			mx1 = distdown[it];
		}
		else if(distdown[it]>mx2) mx2 = distdown[it];
	}
	for(auto it:g[x])
	{
		if(it==par) continue;
		ll sibdist = (distdown[it]==mx1)?mx2:mx1;
		distUp[it] = sibdist + ((sibdist==-1)?0:2);
		if(distUp[x]!=-1) distUp[it] = max(distUp[it],distUp[x]+1);
		if(mark[it]) distUp[it] = max((ll)0,distUp[it]);
		if(!visited[it]) dfs1(it,x);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>d;
	for(i=0;i<m;i++)
	{
		cin>>p;
		p--;
		mark[p]=1;
	}
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	memset(visited,0,sizeof visited);
	distUp[0]=mark[0]-1;
	dfs1(0,-1);
	ll cnt=0;
	for(i=0;i<n;i++)
	{
		if(distUp[i]<=d && distdown[i]<=d) cnt++;
	}
	cout<<cnt;
	return 0;
}