#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,k;
    scanf("%lld %lld",&n,&k);
    if(n >= 30)
    {
        printf("%lld\n",k);
    }
    else
    {
        printf("%lld\n",k % (1 << n));
    }
    return 0;
}
