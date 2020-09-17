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

ll comps,comp[2*MAX],n,p,cnt,deg[MAX],in[MAX],len,rcnt,visited[2*MAX];
string a[MAX],c[MAX],d[MAX];
stack<ll> st,dup;
vll v,g[MAX],f[MAX],h[MAX];
vector<pairs> s,ans;
map<string,ll>m;
map<pairs,ll>seen; 

void dfs(ll node)
{
	visited[node] = 1;
	for(auto it:g[node]) if(!visited[it]) dfs(it);
	st.push(node);
}

void dfs1(ll node)
{
	visited[node] = 1;
	v.pb(node);
	for(auto it:h[node]) if(!visited[it]) dfs1(it);
}

void kosaraju()
{
	for(ll i=0;i<cnt;i++) if(!visited[i]) dfs(i);
	
	comps = 0;
	pairs cur;
	memset(visited,0,sizeof visited);
	while(!st.empty())
	{
		if(!visited[st.top()])
		{
			v.clear();
			dfs1(st.top());
			cur = {INF,INF};
			for(auto i:v)
			{
				comp[i] = comps;
				if(s[i].first < cur.first)
				{
					cur.first = s[i].first;
					cur.second = s[i].second;
				}
				else if(s[i].first==cur.first && s[i].second<cur.second)
					cur.second = s[i].second;
			}
			ans.pb(cur);
			comps++;
		}
		st.pop();
	}
}

void dfs2(ll cnum)
{
	visited[cnum]=1;
	pairs cur = ans[cnum],temp;
	for(auto it:f[cnum])
	{
		if(!visited[it]) dfs2(it);
		temp = ans[it];
		if(temp.first < cur.first)
		{
			cur.first = temp.first;
			cur.second = temp.second;
		}
		else if(temp.first==cur.first && temp.second<cur.second) cur.second = temp.second;
	}
	ans[cnum] = cur;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
		transform(a[i].begin(),a[i].end(),a[i].begin(),::tolower);
	}
	cin>>p;
	cnt=0;	
	for(ll i=0;i<p;i++)
	{
		string x,y;
		cin>>x>>y;
		transform(x.begin(),x.end(),x.begin(),::tolower);
		transform(y.begin(),y.end(),y.begin(),::tolower);
		c[i] = x; d[i] = y;
		if(m.find(x)==m.end())
		{
			m[x] = cnt++;
			len = x.length();
			rcnt=0; for(auto it:x) if(it=='r') rcnt++;
			s.pb({rcnt,len});
		}
		if(m.find(y)==m.end())
		{
			m[y] = cnt++;
			len = y.length();
			rcnt=0; for(auto it:y) if(it=='r') rcnt++;
			s.pb({rcnt,len});
		}
		in[m[x]]++;
		g[m[x]].pb(m[y]);
		h[m[y]].pb(m[x]);
	}

	memset(comp,-1,sizeof comp);
	kosaraju();

	for(ll i=0;i<p;i++)
	{
		ll x,y;
		x = comp[m[c[i]]];
		y = comp[m[d[i]]];
		if(!seen[{x,y}] && x!=y)
		{
			seen[{x,y}] = 1;
			f[x].pb(y);
			deg[y]++;
		}
	}

	memset(visited,0,sizeof visited);
	for(ll i=0;i<comps;i++) if(!visited[i] && deg[i]==0) dfs2(i);

	ll comp_num,res=0,fr=0;
	for(ll i=0;i<n;i++)
	{
		if(m.find(a[i])==m.end() || (m.find(a[i])!=m.end() && in[m[a[i]]]==0))
		{
			res += a[i].length();
			for(auto it:a[i]) if(it=='r') fr++;
			continue;
		}
		comp_num = comp[m[a[i]]];
		res += ans[comp_num].second;
		fr += ans[comp_num].first;
	}
	cout<<fr<<" "<<res;
	return 0;
}