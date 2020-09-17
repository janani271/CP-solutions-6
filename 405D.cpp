#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1000003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll mx,n,i,j,x[MAX],y[MAX],comp,visited[MAX],z;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	//visited: 0(not used), 1(in x), 2(in y)
	mx = 1000000;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
		visited[x[i]] = 1;
	}
	j=0;
	for(i=0;i<n;i++)
	{
		comp = mx - (x[i] - 1);
		if(visited[comp]==1) z++;
		else
		{ 
			visited[comp] = 2;
			y[j++] = comp;
		}
	}
	for(i=1;i<=mx/2 && z>0;i++)
	{
		if(visited[i]) continue;
		comp = mx-(i-1);
		if(!visited[comp] && !visited[i])
		{
			y[j++] = i;
			y[j++] = comp;
			z--;
		}
	}
	cout<<n<<"\n";
	for(i=0;i<n;i++) cout<<y[i]<<" ";
	return 0;
}