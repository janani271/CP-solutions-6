#include<bits/stdc++.h>
using namespace std;

long long n , m , i , u , v ,visited[100];
vector<int>g[100],h[100],st;


void dfs1(long long x)
{ 
	visited[x]=0;
	cout<<x<<" ";
	for(auto it=h[x].begin();it!=h[x].end();it++)
	{
		if(visited[*it])
			dfs1(*it);
	}
}

void dfs(long long x)
{ 
	visited[x]=1;
	for(auto it=g[x].begin();it!=g[x].end();it++)
	{
		if(!visited[*it])
		{
			dfs(*it);
		}
	}
	st.push_back(x);
}

int main()
{
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>u>>v; //edge from u to v
		g[u].push_back(v);
		h[v].push_back(u);//transpose graph
	}

	memset(visited,0,sizeof visited);
	fin=0;
	for(i=1;i<=n;i++)
	{
		if(!visited[i])
			dfs(i);
	}

	reverse(st.begin(),st.end());

	for(auto it:st)
	{
		if(visited[it])
		{
			cout<<"\n";
			dfs1(it);
		}
	}

	return 0;
}