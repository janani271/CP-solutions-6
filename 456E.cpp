#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 300003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll diameter[MAX],size[MAX],parent[MAX],root,visited[MAX],height,id;
vll g[MAX];

void dfs(ll x, ll p, ll ht)
{
	visited[x] = 1;
	if(ht>height)
	{
		height = ht;
		id = x;
	}
	for(auto it:g[x]) if(it!=p) dfs(it,x,ht+1);
}

ll find(ll x)
{
	while(x!=parent[parent[x]]) x = parent[parent[x]];
	return x;
}

void union_find(ll x, ll y)
{
	ll px = find(x);
	ll py = find(y);
	if(px == py) return;

	if(size[px]<size[py]) swap(px,py);
	size[px] += size[py];
	diameter[px] = max((diameter[px]+1)/2+(diameter[py]+1)/2+1,max(diameter[px],diameter[py]));
	parent[py] = px;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll x,y,n,m,q,i,t;

	cin>>n>>m>>q;
	for(i=1;i<=n;i++)
	{
		size[i]=1;
		parent[i]=i;
	}
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		union_find(x,y);
	}

	for(i=1;i<=n;i++)
	{
		root = find(i);
		if(visited[root]) continue;
		height = -1; dfs(i,-1,0);
		height = -1; dfs(id,-1,0);
		diameter[root] = height;
	}
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x;
			cout<<diameter[find(x)]<<"\n";
		}
		else
		{
			cin>>x>>y;
			union_find(x,y);
		}
	}
	return 0;
}