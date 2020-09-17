#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,a[MAX],pre[2*MAX],i,res;
vll ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	ans.push_back(0);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%2) ans.push_back(a[i]);
	}

	for(i=1;i<=n;i++) if(i%2==0) ans.push_back(a[i]);
	for(i=1;i<=n;i++) if(i%2) ans.push_back(a[i]);
	
	pre[0]=0;
	for(i=1;i<=n+(n/2)+1;i++) pre[i] = ans[i] + pre[i-1];

	for(i=(n/2)+1;i<=n+(n/2)+1;i++) res = max(res,pre[i]-pre[i-(n/2)-1]);
	cout<<res;
	return 0;
}