/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc = 1;
    ll a,b;
    cin >> a >> b;
    if(a*2 > b) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        int chaeng = 0;
        for(i=1;i<a;i++) {
            chaeng += 2;
            cout << 2 << " ";
        }
        cout << b - chaeng << endl;
        cout << "1" << endl;
    }
    return 0;
}
