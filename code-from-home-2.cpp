#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 1000007

ll MOD=1e9+7;
ll n , sum , i , a[MAX], m , l , r , min_c,c,mid;
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
	cin>>m;

	l=1;r=sum+5;min_c=sum+5;
	while(l<=r)
	{
		mid = (l+r)/2;
		// cout<<"mid : "<<mid<<"\n";
		c=0;
		for(i=0;i<n;i++)
		{
			c += (a[i]/mid);
			if(a[i]%mid!=0) c++;
			// cout<<"c : "<<c<<"\n";
		}
		if(c<=m && mid<=min_c)
		{
			min_c=mid;
			r = mid-1;
		}
		else l=mid+1;
	}
	cout<<min_c;
	return 0;
}