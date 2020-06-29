#include<bits/stdc++.h>
using namespace std;
long long t , n , i , a[10009] , b[10009] , sum;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		sum = 0;
		for(i=0;i<n;i++)
		{
			sum += min(a[i],b[i]);
		}
		cout<<sum<<"\n";
	}
	return 0;
}