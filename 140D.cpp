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

ll n,i,a[105],ans,tim,sum;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ans=0; tim=0; sum=0;
	for(i=0;i<n;i++)
	{
		if(sum + a[i]>710) break;
		if(sum+a[i]<=350)
		{
			sum += a[i];
			continue;
		}
		tim = sum - 350;
		ans += tim + a[i];
		sum += a[i];
	}
	cout<<i<<" "<<ans<<"\n";
	return 0;
}