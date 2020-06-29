#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 103
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}
ll t,tests,n,i,j,row[MAX][MAX],col[MAX][MAX];
ll sum,r,c,tot,x,flag;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>tests;
	for(t=1;t<=tests;t++)
	{
		cin>>n;
		sum=0; r=0; c=0; tot=0;
		memset(row,0,sizeof row);
		memset(col,0,sizeof col);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cin>>x;
				if(i==j) sum+=x;
				row[i][x]=1;
				col[j][x]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			flag=1;
			for(j=1;j<=n;j++)
			{
				if(row[i][j]==0)
				{
					flag=0;
					break;
				}
			}
			if(!flag) r++;
		}

		for(i=1;i<=n;i++)
		{
			flag=1;
			for(j=1;j<=n;j++)
			{
				if(col[i][j]==0)
				{
					flag=0;
					break;
				}
			}
			if(!flag) c++;
		}
		cout<<"Case #"<<t<<": "<<sum<<" "<<r<<" "<<c<<"\n";
	}
	return 0;
}