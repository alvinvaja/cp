#include<bits/stdc++.h>
using namespace std;
long long int n, idx, i, j, k, ans,curr;
void rec(long long int num)
{
    if(num > n)
        return;
    long long int temp = num;
    int valid = 0;
    int cek[10];
    memset(cek,0,sizeof(cek));
    while(temp > 0)
    {
        cek[temp%10] = 1;
        temp/=10;
    }
    if(cek[3] == 1 && cek[5] == 1 && cek[7] == 1)
        valid = 1;
    if(num <= n && valid == 1)
    {
        ans++;
    }
    rec(num*10+3);
    rec(num*10+5);
    rec(num*10+7);
}
int main()
{
    ans = 0;
    scanf("%lld",&n);;
    rec(3);
    rec(5);
    rec(7);
    printf("%lld\n",ans);
    return 0;
}
