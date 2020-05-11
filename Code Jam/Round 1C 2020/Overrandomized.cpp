/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
map<ll,int> mp;
ll now;
string s;
int cnt[26], awal[26];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
	int inc = 1;
    cin >> tc;
    n = 10000;
    while(tc--)
    {
        int u;
        cin >> u;
        mp.clear();
        for(i=0;i<26;i++) cnt[i] = 0;
        for(i=0;i<26;i++) awal[i] = 0;
        for(i=1;i<=n;i++)
        {
            cin >> now >> s;
            for(auto x : s) {
                curr = x - 'A';
                cnt[curr]++;
            }
            curr = s[0] - 'A';
            awal[curr]++;
        }
        char c;
        string chaeng = "";
        vector<pair<int,int> > vi;
        for(i=0;i<26;i++) {
            if(cnt[i] > 0 && awal[i] == 0) {
                c = 'A' + i;
                chaeng += c;
                cnt[i] = 0;
            }
            if(cnt[i] > 0) {
                vi.push_back({awal[i], i});
            }
        }
        sort(vi.begin(), vi.end());
        reverse(vi.begin(), vi.end());
        for(i=0;i<9;i++) {
            c = vi[i].second + 'A';
            chaeng += c;
        }
        printf("Case #%d: ", inc++);
        cout << chaeng << endl;
    }
	return 0;
}
