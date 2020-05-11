#include<bits/stdc++.h>
using namespace std;
vector<int> vi;
int main()
{
    long long int n,i,j,k,x,y,ans,curr,temp;
    scanf("%lld",&n);
    vi.push_back(1);
    vi.push_back(n);
    for(i=2;i<=sqrt(n);i++)
    {
        if(n % i == 0)
        {
            vi.push_back(i);
        }
        else
            continue;
        if(i == n/i) continue;
        vi.push_back(n/i);
    }
    sort(vi.begin(),vi.end());
    int len = vi.size();
    ans = n*(n+1)/2;
    vector<long long int> jwb;
    for(i=0;i<len;i++)
    {
        temp = n/vi[i];
        curr = (temp)*(2+(temp-1)*vi[i])/2;
        jwb.push_back(curr);
    }
    sort(jwb.begin(),jwb.end());
    for(i=0;i<jwb.size();i++)
    {
        printf("%lld ",jwb[i]);
    }
    printf("\n");
    return 0;
}
