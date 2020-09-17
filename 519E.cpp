#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003
#define logn 20

using namespace std;

ll n,i,u,v,h[MAX],visited[MAX],visited1[MAX],m,subsize[MAX];
ll lastnodeatlevel[MAX],parent[MAX][23];
vll g[MAX];

void find_heights(long long p , long long ht)
{
	h[p] = ht;
	visited[p]=1;
	subsize[p] = 1;
	for(auto it : g[p])
	{
		if(!visited[it])
		{
			parent[it][0] = p;
			find_heights(it,h[p]+1);
			subsize[p] += subsize[it];
		}
	}
}

void parents_find(long long a ,long long cl) 
{
	visited1[a]=1;
	lastnodeatlevel[cl] = a;
	for(ll k=1;k<=logn;k++)
	{
		if((1<<k)<cl)
			parent[a][k] = lastnodeatlevel[cl - (1<<k)];
	}
	for(auto it : g[a]) if(!visited1[it]) parents_find(it,cl+1);
}

ll find_height_parent(ll cur, ll temp)
{
	for(ll in=0;in<=logn;in++)
	{
		if(temp%2==1) cur = parent[cur][in];
		temp = temp/2;
	}
	return cur;
}

long long lca(long long a , long long b)
{
	ll common;
	if(h[a]!=h[b])
	{
		if(h[a]>h[b])
			swap(a,b);
		b = find_height_parent(b,h[b]-h[a]);
	}

	if(a==b) 
		return a;
	for(ll in=logn;in>=0;in--)
	{
		if(parent[a][in] != parent[b][in])
		{
			a = parent[a][in];
			b = parent[b][in]; 
		}
		else
			common = parent[a][in];
	}
	return common;
}


long long equidistCount(long long a , long long b)
{
	ll c = lca(a,b);
	ll len = h[a] + h[b] - (2*h[c]);

	if(len&1) return 0;
	
	ll ans,temp,in,bin,p;
	if(h[a]-h[c]!=h[b]-h[c])
	{	
		if(h[a]<h[b]) swap(a,b);

		temp = (len/2);
		p=find_height_parent(a,temp);
		ans = subsize[p];
		temp = (len/2)-1;
		p=find_height_parent(a,temp);
		ans -= subsize[p];
		return ans;
	}

	temp = (len/2)-1;
	p = find_height_parent(a,temp);
	ans = n-subsize[p];
	temp = (len/2)-1;
	p = find_height_parent(b,temp);
	ans -= subsize[p];
	return ans;
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
		g[u].pb(v);
		g[v].pb(u);
	}

	//lca
	find_heights(1,0);
	parents_find(1,1);
	for(i=1;i<=logn;i++) parent[1][i] = 1;
	
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		if(u==v) 
		{
			cout<<n<<"\n"; 
			continue;
		}
		cout<<equidistCount(u,v)<<"\n";
	}
	return 0;
}