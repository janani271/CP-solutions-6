#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 1003

ll MOD=1e9+7;

ll k , n1 , n2 , dp[MAX][MAX] , val[MAX][MAX] , j , i , p;
string a , b;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>k;
	while(k!=0)
	{
		cin>>a>>b;
		n1 = a.length();
		n2 = b.length();
		memset(dp,0,sizeof dp);
		memset(val,0,sizeof val);
		for(i=0;i<=n1;i++) dp[i][0]=0;
		for(i=0;i<=n2;i++) dp[0][i]=0;
		val[0][0]=0;
		for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n2;j++)
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
				if(a[i-1]==b[j-1])
					val[i][j] = val[i-1][j-1] + 1;
				else val[i][j] = 0;
				if(val[i][j]>=k) //checking for just i-1 j-1 is not valid bc min k chars need to match continuously
				{				 //so from k chars to the no.of matching chars so far we go back and check the max sum of lcs and no.of continuous chars						
					for(p=k;p<=val[i][j];p++)
					{
						dp[i][j] = max(dp[i-p][j-p] + p,dp[i][j]);
					}
				}
			}
		}
		cout<<dp[n1][n2]<<"\n";
		cin>>k;
	}
	return 0;
}