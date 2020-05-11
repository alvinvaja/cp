/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[10010];
map<ll,int> mp;
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
	int inc = 1;
    cin >> tc;
    while(tc--)
    {
        int d;
        cin >> n >> d;
        mp.clear();
        int maxi = 1;
        for(i=1;i<=n;i++) cin >> arr[i];
        for(i=1;i<=n;i++) {
            mp[arr[i]]++;
            maxi = max(maxi, mp[arr[i]]);
        }
        int chaeng = d - 1;
        if(maxi >= d) {
            chaeng = min(chaeng, 0);
        }
        if(d > 2) {
            for(auto x : mp) {
                if(x.second == 1) {
                    if(mp[x.first*2] > 0) {
                        chaeng = min(chaeng, 1);
                    }
                }
                if(x.second == 2) {
                    for(auto y : mp) {
                        if(y.first > x.first && y.second > 0) {
                            chaeng = min(chaeng, 1);
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", inc++);
        if(chaeng < 0) chaeng = 0;
        cout << chaeng << endl;
    }
	return 0;
}
