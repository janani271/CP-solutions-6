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

// longest proper prefix which a suffix
ll lps(string p, string t)
{
	ll i,j,f[2*MAX+5];

	string s = p + '#' + t;
	ll n = s.length();
	ll len = p.length(); //len of pattern to check
	ll cnt=0;

	f[0] = 0;
	for(i=1;i<n;i++)
	{
		j = f[i-1]; //char at i should match char at f[i-1]
		while(j>0 && s[i]!=s[j])
		{
			j = f[j-1];
		}
		if(s[i]==s[j]) ++j;
		f[i]=j;
		if(f[i]==len) cnt++;
	}

	return cnt;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	string p,t;

	//p is pattern and t is the text
	cin>>p>>t;

	// no.of occurrences of p in t
	cout<<lps(p,t);
	return 0;
}