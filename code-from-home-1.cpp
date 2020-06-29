#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll n , sum , i , a[MAX], h , x , k;
int main()
{
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	// fastread;

	cin>>n;
	sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
	cin>>h;
	cin>>x>>k;
	h = h + (x*k);
	if(h>=sum) cout<<"Fight";
	else cout<<"Retire";

	return 0;
}