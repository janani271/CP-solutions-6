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

ll t,n,x,sum,flag,i,a[MAX],l,r,cnt;

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
		cin>>n>>x;
		sum=0; flag=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%x!=0) flag=1;
			sum += a[i];
		}
		if(!flag)
		{
			cout<<"-1\n";
			continue;
		}
		l=0; r=n-1; cnt=0;
		while(l<=r && sum%x==0)
		{
			if(a[l]%x!=0)
			{
				sum -= a[l];
				l++;
			}
			else if(a[r]%x!=0)
			{
				sum -= a[r];
				r--;
			}
			else
			{
				cnt++;
				sum -= a[r];
				sum -= a[l];
				l++; r--;
			}
		}
		cout<<r-l+1+cnt<<"\n";
	}
	return 0;
}