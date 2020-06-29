#include<bits/stdc++.h>
using namespace std;

long long t , sum, cur_sum , n , i , cnt[10][10],ts;
char ch;

void calc_profit(int p[], int sz)
{
	vector<long long>show;
	long long res,mul;
	res = 0;
	// cout<<"-------------------------------------------------------------\n";
	for(int k=0;k<sz;k++)
	{
		show.push_back(cnt[k][p[k]]);
		// cout<<(char)('A'+k)<<" : "<<(p[k]+1)*3<<"count : "<<cnt[k][p[k]]<<"\n";
	}
	mul=100;
	sort(show.begin(),show.end(),greater<long long>());
	for(auto it:show)
	{
		// cout<<it<<"hello"<<"\n";
		if(it!=0)
		{
			res += it*mul;
			mul -= 25;
		}
		else
			res -= 100;
	}
	// cout<<"res : "<<res<<"\n";
	// cout<<"-------------------------------------------------\n";
	cur_sum = max(cur_sum,res);
}

void calc_max_profit(int p[] , int s, int e)
{
	if(s==e)
	{
		calc_profit(p,e+1);
		return;
	}
	int j;
	for(j=s;j<=e;j++)
	{
		swap(p[j],p[s]);
		calc_max_profit(p,s+1,e);
		swap(p[j],p[s]);
	}
}

int main()
{
	int p[4] = {0,1,2,3};
	cin>>ts;
	sum = 0;
	while(ts--)
	{
		cin>>n;
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++)
		{
			cin>>ch>>t;
			cnt[ch-'A'][(t/3)-1]++;
		}
		cur_sum = -1000000;
		calc_max_profit(p,0,3);
		cout<<cur_sum<<"\n";
		sum += cur_sum;
	}

	cout<<sum;
	return 0;
}