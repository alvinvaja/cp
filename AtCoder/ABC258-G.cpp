#include<bits/stdc++.h>
#define ll long long
using namespace std;

char c[3030][3030];
bitset<3030> bs[3030];

int main() {
    int n,i,j,k,x,y,ans,curr,temp,m;
    cin >> n;

    getchar();
    for(i=1;i<=n;i++) {
        for(j=1;j<=n;j++) {
            scanf("%c",&c[i][j]);
            if(c[i][j] == '1') bs[i].set(j);
        }
        getchar();
    }

    ll luda = 0;
    for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
            if(c[i][j] == '1') {
                luda += (bs[i] & bs[j]).count();
            }
        }
    }

    cout << luda / 3 << endl;

    return 0;
}
