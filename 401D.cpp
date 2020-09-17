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

ll dp[300000][105];

ll getCount(ll n, ll m)
{
	//get digits
	ll nod=0;
	int digits[20];
	while(n!=0)
	{
		digits[nod++] = n%10;
		n /= 10;
	}
	sort(digits,digits+nod);
	
	//no.of masks
	ll mx = (1<<nod);

	dp[0][0]=1;
	
	for(ll i=0;i<mx;i++) //mask
	{
		for(ll j=0;j<m;j++) //remainder
		{
			if(!dp[i][j]) continue;
			ll pre = -1;
			for(ll k=nod-1;k>=0;k--) //mod value
			{
				if((i&(1<<k))==0)
				{
					if(digits[k]==pre) continue;
					if(i==0 && digits[k]==0) break;	
					dp[i|(1<<k)][((10*j)+digits[k])%m] += dp[i][j];
					pre = digits[k];
				}
			}
		}
	}

	// for(ll i=0;i<mx;i++)
	// {
	// 	for(ll k=0;k<m;k++)
	// 	{
	// 		cout<<"mask : "<<i<<"\tremainder: "<<k<<"\tdp : "<<dp[i][k]<<"\n";
	// 	}
	// }
	return dp[mx-1][0];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll n,m,res;
	cin>>n>>m;
	res = getCount(n,m);
	cout<<res;
	return 0;
}