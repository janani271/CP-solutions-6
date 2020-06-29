#include<bits/stdc++.h>
using namespace std;
long long t , n , k , p[100009] , a[100009] , ans , l , r , need , rem , i;
bool flag;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		p[0] = 0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			p[i] = p[i-1] + a[i];
		}
		flag=false;
		for(i=0;i<=n;i++)
		{
			l = p[i];
			r = p[n] - p[i];
			need = ((((r/k) + 1)*k) - r)%k;
			if(l-need>=0)
			{
				rem = ((l-need)%k) + need;
				if((l-rem)%k==0)
				{
					if(flag)
						ans = min(ans,rem-need);
					else
					{
						flag = true;
						ans = rem-need;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}