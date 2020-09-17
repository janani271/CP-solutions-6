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

string a,b,c,d;

string minEqual(string x, ll len)
{
	if(len&1) return x;
	string y = minEqual(x.substr(0,len/2),len/2);
	string z = minEqual(x.substr(len/2,len/2),len/2);
	if(y<=z) x = y+z;
	else x = z+y;
	return x;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>a>>b;
	c = minEqual(a,a.length());
	d = minEqual(b,b.length());
	if(c!=d) cout<<"NO";
	else cout<<"YES";
	return 0;
}