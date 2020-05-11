/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,temp,curr,m;
    int tc;
    cin >> tc;
    int inc = 1;
    while(tc--)
    {
        cin >> n >> k;
        int last;
        priority_queue<pair<int, pair<int,int> > > pq;
        for(i=1;i<=n;i++)
        {
            cin >> curr;
            if(i > 1)
            {
                pq.push({curr-last, {curr-last,1}});
            }
            last = curr;
        }
        while(k--)
        {
            curr = pq.top().second.second;
            temp = pq.top().second.first;
            if(pq.top().first == 1) break;
            pq.pop();
            curr++;
            int res = temp/curr;
            if(temp%curr) res++;
            pq.push({res, {temp, curr}});
        }
        int chaeng = pq.top().first;
        printf("Case #%d: %d\n", inc++, chaeng);
    }
    return 0;
}

