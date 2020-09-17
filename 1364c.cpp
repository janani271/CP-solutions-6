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
ll INF = 100001;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,i,a[MAX],b[MAX],j,mex,visited[MAX],temp[MAX];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	b[1] = INF;
	mex = INF;
	visited[mex]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) mex = a[i-1];
		b[i] = mex;
		visited[mex]=1;	
	}
	visited[a[n]]=1;
	
	j=0;
	while(visited[j]) j++;
	temp[1]=j;
	visited[j]=1;
	cout<<temp[1]<<" ";
	
	for(i=2;i<=n;i++)
	{
		if(b[i]==b[i-1])
		{
			while(visited[j]) j++;
			visited[j]=1;
			temp[i]=j++;
		}
		else temp[i] = b[i];
		cout<<temp[i]<<" ";
	}	
	return 0;
}