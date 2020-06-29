#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll t , n , m , cost[60] , cnt[60], i , a[60] , p , ans;

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
		memset(cost,0,sizeof cost);
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		for(i=0;i<n;i++)
		{
			cin>>p;
			cost[a[i]] += p;
		}
		ans = cost[1];
		for(i=2;i<=m;i++)
		{
			if(cnt[i]!=0)
				ans = min(ans,cost[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}