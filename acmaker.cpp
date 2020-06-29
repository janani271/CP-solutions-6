#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 152

ll MOD=1e9+7;

ll n,i,c,dp[MAX][MAX],dp2[MAX][MAX],len,n1,n2,k,l,j;
string str,ab,w;
map<string,ll>m;
vector<string>words;


// ll calc(ll x,ll y,ll z)
// {

// 	if(x==nn && y==c) return dp[x][y][z]=1;
// 	if(x>=nn || y>=c) return dp[x][y][z]=0;
// 	if(z >= words[y].length()) return dp[x][y][z]=0;
// 	if(dp[x][y][z]!=-1) return dp[x][y][z];

// 	cout<<"x : "<<x<<"\ty : "<<y<<"\tz : "<<z<<"\n";
// 	ll val=0,res;
// 	res = calc(x,y,z+1) * calc(x,y+1,0);
// 	if(tolower(ab[x])==words[y][z])
// 	{
// 		val = calc(x+1,y,z+1) + calc(x+1,y+1,0);
// 		res = res + val;
// 	}
// 	cout<<"x : "<<x<<"\ty : "<<y<<"\tz : "<<z<<"\n";
// 	cout<<"res : "<<res<<"\n";
	
// 	return dp[x][y][z] = res;
// }

// ll check()
// {
// 	ll val,res;
// 	res = calc(0,0,1) + calc(0,1,0);
// 	if(tolower(ab[0])==words[0][0])
// 	{
// 		val = calc(1,0,1) + calc(1,1,0);
// 		cout<<"res : "<<res<<"\tval : "<<val<<"\n";
// 		res = res+val;
// 	}
// 	return res;
// }

ll check()
{
	memset(dp,0,sizeof dp);
	memset(dp2,0,sizeof dp2);
	dp[0][0]=1;
	for(i=0;i<c;i++)
	{
		for(j=0;j<len;j++)
		{
			n1=words[i].length();
			n2 = min(n1,len-j);
			for(k=0;k<=n1;k++) dp2[k][0] = 1;
			for(k=1;k<=n2;k++) dp2[0][k] = 0;
			
			for(k=0;k<n1;k++)
			{
				for(l=0;l<n2;l++)
				{
					dp2[k+1][l+1] = dp2[k][l+1];
					if(tolower(ab[j+l])==words[i][k])
						dp2[k+1][l+1] += dp2[k][l];
				}
			}
			for(k=1;k<=n2;k++)
			{
				dp[i+1][j+k] += dp[i][j] * dp2[n1][k];
			}
		}
	}
	return dp[c][len];
}
int main()
{
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	// fastread;

	cin>>n;
	while(n!=0)
	{
		m.clear();
		for(i=0;i<n;i++)
		{
			cin>>str;
			m[str]=1;
		}
		while(1)
		{
			getline(cin,str);
			if(str=="LAST CASE") break;
			if(str=="") continue;

			words.clear();
			stringstream ss(str);
			c=0;
			while(ss>>w)
			{
				if(c==0)
				{
					ab = w;
					c++;
				}
				else
				{
					if(m[w]==0)
					{
						words.pb(w);
						c++;
					}
				}
			}
			c--; len=ab.length();
			ll ans = check();
			// cout<<"ans: "<<ans<<"\n";
			if(ans==0)
				cout<<ab<<" is not a valid abbreviation\n";
			else
				cout<<ab<<" can be formed in "<<ans<<" ways\n";
		}
		cin>>n;
	}

	return 0;
}