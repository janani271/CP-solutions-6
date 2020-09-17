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

ll n,i,u,v,flag,color[MAX],subsize[MAX],cnt;
set<ll> g[MAX];

void findSubtreeSize(ll x, ll par)
{
	cnt++;
	subsize[x] = 1;
	for(auto y:g[x])
	{
		if(y == par) continue;
		findSubtreeSize(y,x);
		subsize[x] += subsize[y];
	}
}

ll findCentroid(ll x, ll par)
{
	for(auto y:g[x])
	{
		if(y==par) continue;
		if(subsize[y]>cnt/2) return findCentroid(y,x);
	}
	return x;
}

void decompose(ll x,ll col)
{
	if(col>=26)
	{
		flag=0;
		return;
	}
	cnt=0;
	findSubtreeSize(x,x);
	ll centroid = findCentroid(x,x);
	for(auto it:g[centroid])
	{
		g[it].erase(centroid);
		decompose(it,col+1);
	}
	color[centroid] = col;
	g[centroid].clear();
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
		cin>>u>>v;
		u--;v--;
		g[u].insert(v);
		g[v].insert(u);
	}
	
	flag=1;
	decompose(0,0);
	if(!flag) cout<<"Impossible!";
	else for(i=0;i<n;i++) cout<<(char)(color[i]+'A')<<" ";

	return 0;
}