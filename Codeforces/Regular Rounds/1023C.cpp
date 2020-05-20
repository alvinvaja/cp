#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > vi;
int main()
{
    int i,j,k,x,y,ans,curr,len,temp,n;
    scanf("%d %d",&n,&k);
    char arr[n+5];
    scanf("%s",arr);
    int can[n+5];
    for(i=0;i<n;i++)
    {
        if(arr[i] == '(')
            can[i] = 1;
        else
            can[i] = 0;
    }
    stack<int> s;
    stack<int> idx;
    s.push(can[0]);
    idx.push(0);
    if(s.top() == 0)
    {
        idx.pop();
        s.pop();
    }
    for(i=1;i<n;i++)
    {
        if(s.empty())
        {
            if(can[i] == 0)
                continue;
            s.push(can[i]);
        }
        if(s.top() == 1 && can[i] == 0)
        {
            vi.push_back(make_pair(idx.top(), i));
            s.pop();
            idx.pop();
        }
        else if(can[i] == 1)
        {
            s.push(can[i]);
            idx.push(i);
        }
    }
    curr = 0;
    char jwb[n+5];
    for(i=0;i<n+5;i++)
        jwb[i] = 'x';
    for(i=0;i<vi.size();i++)
    {
        if(curr == k)
            break;
        jwb[vi[i].first] = '(';
        jwb[vi[i].second] = ')';
        curr += 2;
    }
    for(i=0;i<n;i++)
    {
        if(jwb[i] == 'x')
            continue;
        printf("%c",jwb[i]);
    }
    printf("\n");
    return 0;
}
