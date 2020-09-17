#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll mov[5] = {0,1,0,-1,0};
ll t,n,m,i,j,visited[MAX][MAX],x,y,nx,ny,flag;
char a[MAX][MAX];

bool valid(ll p, ll q)
{
	if(p>0 && p<=n && q>0 && q<=m && !visited[p][q] && a[p][q] != '#') return true;
	return false;
}

bool valid2(ll p, ll q)
{
	if(p>0 && p<=n && q>0 && q<=m && visited[p][q]<2 && a[p][q] != '#') return true;
	return false;
}

bool block(ll p, ll q)
{
	// cout<<"\n----------\np : "<<p<<"\tq : "<<q<<"\n";
	for(ll k=0;k<4;k++)
	{
		ll np = p+mov[k];
		ll nq = q+mov[k+1];
		if(np>0 && np<=n && nq>0 && nq<=m)
		{
			if(!visited[np][nq]) continue;
			if(a[np][nq] == 'G') return false;
			if(a[np][nq] != 'B') a[np][nq] = '#';
			// cout<<"np : "<<np<<"\tnq : "<<nq<<"\n";
		}
	}
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		queue<pairs>q;
		q.push({n,m});
		memset(visited,0,sizeof visited);
		visited[n][m]=1;
		while(!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for(i=0;i<4;i++)
			{
				nx = x+mov[i];
				ny = y+mov[i+1];
				if(valid(nx,ny))
				{
					visited[nx][ny]=1;
					q.push({nx,ny});
				}
			} 
		}

		flag=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[i][j] == 'B' && visited[i][j])
				{
					if(!block(i,j))
					{
						cout<<"NO\n";
						flag=0; break;
					}
				}
			}
			if(!flag) break;
		}
		if(!flag) continue;
		
		if(a[n][m]!='#')
		{
			q.push({n,m});
			visited[n][m] = 2;
		} 
		while(!q.empty())
		{
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for(i=0;i<4;i++)
			{
				nx = x+mov[i];
				ny = y+mov[i+1];
				if(valid2(nx,ny))
				{
					visited[nx][ny]=2;
					q.push({nx,ny});
				}
			} 
		}

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				// cout<<a[i][j]<<" ";
				// cout<<"i : "<<i<<"\tj : "<<j<<"\ta : "<<a[i][j]<<"\tvisited : "<<visited[i][j]<<"\n";
				if(a[i][j]=='G' && visited[i][j]!=2)
				{
					flag=0;
					break;
				}
				if(a[i][j]=='B' && visited[i][j]==2)
				{
					flag=0; break;
				}
			}
			// cout<<"\n";
			if(!flag) break;
		}
		if(!flag) cout<<"NO\n";
		else cout<<"Yes\n";
	}
	return 0;
}