#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1001

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,i,j,a[MAX][MAX],cur,mid,l,r,res;
vll ans;
unordered_map<ll,ll>mp;

bool check(ll val)
{
	bitset<1001>b[MAX];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]>=val)
				b[i].set(j);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((b[i]&b[j]).count()>=2) return true;
		}
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			ans.pb(a[i][j]);
		}
	}
	sort(ans.begin(),ans.end());
	l = 0; r = ((n*m)-1); res=0;
	while(l<=r)
	{
		mid = (l+r)/2;
		cur = ans[mid];
		if(check(cur))
		{
			res = max(res,cur);
			l = mid+1;
		}
		else r = mid-1;
	}
	cout<<res;
	return 0;
}