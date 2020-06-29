#include<bits/stdc++.h>
using namespace std;
long long t , n , p , i , d[1009] , e[1009] , pos , pre , val1, val2 , temp ;
int main()
{
	cin>>t;
	while(t--)
	{
		pos = -1;
		cin>>n>>p;
		for(i=0;i<n;i++)
		{
			cin>>d[i];
			e[i] = d[i];
			if(p%d[i])
				pos = i;
		}

		if(pos!=-1)
		{
			cout<<"YES ";
			for(i=0;i<n;i++)
			{
				if(pos!=i)
					cout<<"0 ";
				else
				{
					cout<<(p/d[i])+1<<" ";
				}
			}
			cout<<"\n";
		}

		else
		{
			if(n==1)
			{
				cout<<"NO\n";
			}
			else
			{
				val1 = -1;
				sort(d,d+n);
				pre = d[0];	
				for(i=1;i<n;i++)
				{
					if(d[i]%pre!=0)
					{
						val1 = d[i-1];
						val2 = d[i];
						break; 
					}
					pre = d[i];
				}
				if(val1==-1)
					cout<<"NO\n";
				else
				{
					cout<<"YES\n";
					for(i=0;i<n;i++)
					{
						if(e[i]==val1)
						{
							temp = p;
							temp -= val2*((p/val2)-1);
							cout<<(temp/val1)+1<<" ";
						}
						else if(e[i]==val2)
						{
							cout<<(p/val2)-1<<" ";
						}
						else cout<<"0 ";
					}
					cout<<"\n";
				}
			}
		}
	}
	return 0;
}