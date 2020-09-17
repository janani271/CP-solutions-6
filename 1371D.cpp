#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 305

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,t,i,j,k;
ll r[MAX],c[MAX],a[MAX][MAX];

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
		cin>>n>>k;
	 
		for(i=0;i<n;i++)
		{
			r[i]=0;
			for(j=0;j<n;j++)
			{
				a[i][j] = 0;
				c[j]=0;
			}
		}

		j=0;
		while(k)
		{
			//check
			for(i=0;i<n&&k>0;i++,k--,j=(j+1)%n) a[i][j] = 1;
			j++;
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
		sort(r,r+n); sort(c,c+n);
		cout<<pow(r[n-1]-r[0],2) + pow(c[n-1]-c[0],2)<<"\n";
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++) cout<<a[i][j];
			cout<<"\n";
		}
	}
	return 0;
}