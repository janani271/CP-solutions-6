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

ll t,n,i,a[MAX],turn;
vll ans;

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
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}

		if(a[1]<a[2]) turn=0; //increasing
		else turn = 1;
		i=1;
		ans.pb(a[i]);
		i++;

		while(i<=n)
		{
			if(turn==0)
			{
				if(a[i]>a[i-1])
				{
					i++;
					continue;
				}
				ans.pb(a[i-1]);
				turn = 1;
			}
			else
			{
				if(a[i]<a[i-1])
				{
					i++;
					continue;
				}
				ans.pb(a[i-1]);
				turn = 0;
			}
		}
		ans.pb(a[n]);
		cout<<ans.size()<<"\n";
		for(auto it:ans) cout<<it<<" ";
		cout<<"\n";
		ans.clear();
	}
	return 0;
}