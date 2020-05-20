#include<bits/stdc++.h>
using namespace std;
string arr[100100];
map<int,int> mp;
set<int> s[500500];
set<int>::iterator it;
int done[500500];
int main()
{
    int n,i,j,k,x,y,curr,temp,len,sum,can;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
        len = arr[i].length();
        sum = 0;
        can = 1;
        for(j=0;j<len;j++)
        {
            if(arr[i][j] == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
            {
                can = 0;
                break;
            }
        }
        if(can == 1)
        {
            s[sum].insert(i);
        }
    }
    int ans = 0;
    for(i=0;i<n;i++)
    {
        len = arr[i].length();
        can = 1;
        sum = 0;
        for(j=len-1;j>=0;j--)
        {
            if(arr[i][j] == ')')
                sum++;
            else
                sum--;
            if(sum < 0)
            {
                can = 0;
                break;
            }
        }
        if(can == 1)
        {
            if(done[i] == 0)
            {
                for(it=s[sum].begin();it!=s[sum].end();it++)
                {
                    if(i == *it)
                        continue;
                    if(done[*it] == 0)
                    {
                        ans++;
                        done[i] = done[*it] = 1;
                        s[sum].erase(*it);
                        s[sum].erase(i);
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
