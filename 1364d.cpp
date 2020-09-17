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

ll n,m,k,i,u,v,visited[MAX],cnt,max_level,temp;
vll g[MAX],level[MAX],ans;
stack<ll>st;

void level_comp(ll x,ll l)
{
	visited[x]=1;
	max_level = max(max_level,l);
	level[l].pb(x);
	for(auto it:g[x])
	{
		if(visited[it]) continue;
		level_comp(it,l+1);
	}	
}

void dfs(ll x, ll h, ll p)
{
	// cout<<"entering : "<<x<<"\n";
	visited[x]=h;
	st.push(x);
	ll final_len = INF;
	for(auto it:g[x])
	{
		if(!visited[it] || it==p) continue;
		ll cycle_len = visited[x] - visited[it] + 1;
		final_len = min(final_len,cycle_len);
	}

	if(final_len!=INF)
	{
		if(final_len<=k)
		{
			cout<<"2"<<"\n";
			cout<<final_len<<"\n";
			while(final_len--)
			{
				cout<<st.top()<<" ";
				st.pop();
			}
			// cout<<st.top();
		}
		else
		{
			cout<<"1\n";
			for(i=1;i<=temp/2;i++)
			{
				cout<<st.top()<<" ";
				st.pop(); st.pop();
			}
		}
		exit(0);
	}

	for(auto it:g[x]) if(!visited[it]) dfs(it,h+1,x);
	// cout<<"leaving : "<<x<<"\n";
	st.pop();
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>k;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	if(m==n-1)
	{
		level_comp(1,1);
		if(k&1) k++;
		i=1; cnt=0;
		while(i<=max_level)
		{
			for(auto it:level[i])
			{
				ans.pb(it);
				cnt++;
			}
			i+=2;
		}
		if(cnt<k/2)
		{
			i=2; cnt=0;
			ans.clear();
			while(i<=max_level)
			{
				for(auto it:level[i])
				{
					ans.pb(it);
					cnt++;
				}
				i+=2;
			}	
		}
		cout<<"1\n";
		for(i=0;i<k/2;i++) cout<<ans[i]<<" ";
	}
	else
	{
		temp = k;
		if(k&1) temp++;
		dfs(1,1,0);
	}
	return 0;
}