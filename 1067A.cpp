#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long int
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=998244353;
// ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,a[MAX],i,x,j,dp[MAX][201][3],pre[MAX][201][3],mx=200;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];

	if(a[1]!=-1) dp[1][a[1]][2] = 1;
	else for(i=1;i<=mx;i++) dp[1][i][2] = 1;
	
	for(i=1;i<=mx;i++)
	{
		x=1;
		pre[x][i][0] = dp[x][i][0]; pre[x][i][1] = dp[x][i][1]; pre[x][i][2] = dp[x][i][2];
		if(i>1)
		{
			pre[x][i][0] = add(pre[x][i][0],pre[x][i-1][0]);
			pre[x][i][1] = add(pre[x][i][1],pre[x][i-1][1]);
			pre[x][i][2] = add(pre[x][i][2],pre[x][i-1][2]);
		}
		// cout<<"x : "<<x<<"\t i : "<<i<<"\n";
		// cout<<"\tdp0: "<<dp[x][i][0]<<"\tdp1: "<<dp[x][i][1]<<"\tdp2: "<<dp[x][i][2]<<"\n";
		// cout<<"\tpre0: "<<pre[x][i][0]<<"\tpre1: "<<pre[x][i][1]<<"\tpre2: "<<pre[x][i][2]<<"\n";
		// cout<<"\n-------------\n";
	}

	for(x=2;x<=n;x++)
	{
		if(a[x]==-1)
		{
			for(i=1;i<=mx;i++)
			{	
				dp[x][i][0] = add(sub(pre[x-1][mx][0],pre[x-1][i][0]), sub(pre[x-1][mx][1],pre[x-1][i][1]));

				dp[x][i][1] = add(dp[x-1][i][0],add(dp[x-1][i][1],dp[x-1][i][2])); 
				
				dp[x][i][2] = add(pre[x-1][i-1][0],add(pre[x-1][i-1][1],pre[x-1][i-1][2]));
				
				pre[x][i][0] = dp[x][i][0]; pre[x][i][1] = dp[x][i][1]; pre[x][i][2] = dp[x][i][2];
				if(i>1)
				{
					pre[x][i][0] = add(pre[x][i][0],pre[x][i-1][0]);
					pre[x][i][1] = add(pre[x][i][1],pre[x][i-1][1]);
					pre[x][i][2] = add(pre[x][i][2],pre[x][i-1][2]);
				}
				// cout<<"x : "<<x<<"\t i : "<<i<<"\n";
				// cout<<"\tdp0: "<<dp[x][i][0]<<"\tdp1: "<<dp[x][i][1]<<"\tdp2: "<<dp[x][i][2]<<"\n";
				// cout<<"\tpre0: "<<pre[x][i][0]<<"\tpre1: "<<pre[x][i][1]<<"\tpre2: "<<pre[x][i][2]<<"\n";
				// cout<<"\n-------------\n";
			}
		}
		else
		{
			i = a[x];
			dp[x][i][0] = add(sub(pre[x-1][mx][0],pre[x-1][i][0]), sub(pre[x-1][mx][1],pre[x-1][i][1]));

			dp[x][i][1] = add(dp[x-1][i][0],add(dp[x-1][i][1],dp[x-1][i][2])); 
			
			dp[x][i][2] = add(pre[x-1][i-1][0],add(pre[x-1][i-1][1],pre[x-1][i-1][2]));

			for(i=1;i<=200;i++)
			{
				pre[x][i][0] = dp[x][i][0]; pre[x][i][1] = dp[x][i][1]; pre[x][i][2] = dp[x][i][2];
				if(i>1)
				{
					pre[x][i][0] = add(pre[x][i][0],pre[x][i-1][0]);
					pre[x][i][1] = add(pre[x][i][1],pre[x][i-1][1]);
					pre[x][i][2] = add(pre[x][i][2],pre[x][i-1][2]);
				}
				// cout<<"x : "<<x<<"\t i : "<<i<<"\n";
				// cout<<"\tdp0: "<<dp[x][i][0]<<"\tdp1: "<<dp[x][i][1]<<"\tdp2: "<<dp[x][i][2]<<"\n";
				// cout<<"\tpre0: "<<pre[x][i][0]<<"\tpre1: "<<pre[x][i][1]<<"\tpre2: "<<pre[x][i][2]<<"\n";
				// cout<<"\n-------------\n";
			} 
		}
	}

	cout<<add(pre[n][mx][0],pre[n][mx][1]);
	return 0;
}