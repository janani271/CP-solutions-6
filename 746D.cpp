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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll t,n,k,g,bcnt,ac,bc,i,diff,j;
	char a,b;
	string res="";

	cin>>n>>k>>g>>bcnt;
	//a smaller, b greater
	ac = g; bc = bcnt;
	a = 'G'; b = 'B';
	if(g>bcnt)
	{
		swap(a,b);
		swap(ac,bc);
	}
	if(bc > (ac+1)*k)
	{
		cout<<"NO";
		return 0;
	}

	diff = bc-ac-1;
	// cout<<diff;

	for(i=0;i<=ac;i++)
	{
		if(diff>=0) cout<<b;
		t = min(diff,k-1);
		diff = diff - t;
		for(j=0;j<t;j++) cout<<b;
		if(i<ac) cout<<a;
	}
	return 0;
}