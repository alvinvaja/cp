/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int dist[2020][2020];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
	int inc = 1;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> x >> y >> s;
        int chaeng = 1;
        bool can = 0;
        for(auto a : s) {
            if(a == 'N') y++;
            if(a == 'E') x++;
            if(a == 'S') y--;
            if(a == 'W') x--;
            if(abs(x) + abs(y) <= chaeng)
            {
                can = 1;
                ans = chaeng;
                break;
            }
            chaeng++;
        }
        printf("Case #%d: ", inc++);
        if(can) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
	return 0;
}
