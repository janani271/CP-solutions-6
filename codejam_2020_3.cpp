#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1003
#define INF 1000000000000000005

using namespace std;

ll tests,t,n,i,s,e,c,j,cnt,pos;
char ans[MAX];
vector<pair<pairs,ll>>v;

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
		cin>>n;
		v.clear();
		for(i=1;i<=n;i++)
		{
			cin>>s>>e;
			v.pb({{s,e},i});
		}
		sort(v.begin(),v.end());
		c=0;j=0;cnt=0;
		for(auto it:v)
		{
			s=it.first.first;
			e=it.first.second;
			pos=it.second;
			if(s>=c)
			{
				c = e;
				ans[pos]='C';
				cnt++;
			}
			else if(s>=j)
			{
				j = e;
				ans[pos]='J';
				cnt++;
			}
			else break; 
		}

		cout<<"Case #"<<t<<": ";
		if(cnt!=n) cout<<"IMPOSSIBLE";
		else for(i=1;i<=n;i++) cout<<ans[i];
		cout<<"\n";
	}
	return 0;
}