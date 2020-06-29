#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
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

string s,res;
ll tests,t,c,len,i,cur,diff;
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
		cin>>s;
		c=0;
		len=s.length();
		res="";
		for(i=0;i<len;i++)
		{
			cur = s[i]-'0';
			diff = cur-c;
			c += diff;
			while(diff<0)
			{
				res+=')';
				diff++;
			}
			while(diff>0)
			{
				res+='(';
				diff--;
			}	
			res+=s[i];
		}
		while(c>0)
		{
			res += ')';
			c--;
		}
		cout<<"case #"<<t<<": "<<res<<"\n";
	}
	return 0;
}