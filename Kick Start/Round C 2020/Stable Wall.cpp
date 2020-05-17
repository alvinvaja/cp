/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> vi[26];
char arr[50][50];
int indeg[26];
int main()
{
    int n,i,j,k,x,y,ans,curr,m;
    int tc;
    int inc = 1;
    cin >> tc;
    while(tc--)
    {
        int r,c;
        cin >> r >> c;
        for(i=0;i<26;i++) vi[i].clear(), indeg[i] = 0;
        getchar();
        set<char> s; // available letters
        for(i=1;i<=r;i++) {
            for(j=1;j<=c;j++) {
                scanf("%c",&arr[i][j]);
                s.insert(arr[i][j]);
            }
            getchar();
        }
        for(i=1;i<r;i++) {
            for(j=1;j<=c;j++) {
                int up = arr[i][j] - 'A';
                int down = arr[i+1][j] - 'A';
                if(up == down) continue;
                indeg[up]++;
                vi[down].push_back(up); // must place down first before up
            }
        }
        queue<int> q;
        for(auto x : s) {
            int num = x - 'A';
            if(!indeg[num]) q.push(num);
        }
        printf("Case #%d: ", inc++);
        if(q.empty()) {
            printf("-1\n");
            continue;
        }
        string chaeng = "";
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            char c = curr + 'A';
            chaeng += c;
            for(auto x : vi[curr]) {
                indeg[x]--;
                if(indeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        if(chaeng.size() != s.size()) {
            printf("-1\n");
            continue;
        }
        cout << chaeng << endl;
    }
	return 0;
}
