#include<bits/stdc++.h>
using namespace std;
long long tes , t , n, ci , cI , cnt, i;
string s;
int main()
{
    cin>>tes;
    for(t=1;t<=tes;t++)
    {
        cin>>s;
        n = s.length();
        cnt = 0; cI = 0; ci = 0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='I')
            cI++;
            else if(s[i]=='i')
            ci++;
            else if(s[i]=='o')
            {
                if(ci>0)
                ci--;
                else cI--;
            }
            else
            {
                if(cI>0)
                {
                    cI--;
                    cnt++;
                }
                else ci--;
            }
        }
        
        cout<<"Case #"<<t<<": "<<cnt<<"\n";
    }
    return 0;
}