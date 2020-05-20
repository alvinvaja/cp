#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[200200];
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(i=1;i<=n;i++) cnt[i] = 0;
        for(i=1;i<=n;i++) {
            cin >> curr;
            cnt[curr]++;
        }
        int chaeng = 0;
        int carry = 0;
        for(i=1;i<=n;i++) {
            int now = cnt[i] + carry;
            chaeng += now / i;
            carry = now % i;
        }
        cout << chaeng << endl;
    }
    return 0;
}