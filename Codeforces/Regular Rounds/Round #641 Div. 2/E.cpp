/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
char arr[1010][1010];
int dp[1010][1010];
int r,c;
bool visited[1010][1010];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int q;
	cin >> r >> c >> q;
	getchar();
	for(i=1;i<=r;i++) {
        for(j=1;j<=c;j++) {
            scanf("%c",&arr[i][j]);
            dp[i][j] = 1e9;
        }
        getchar();
	}
  int cnt = 1;
  set<pair<int, pair<int,int> > > s;
	for(i=1;i<=r;i++) {
        for(j=1;j<=c;j++) {
            if(arr[i][j] == arr[i+1][j]) dp[i][j] = 0;
            if(arr[i][j] == arr[i-1][j]) dp[i][j] = 0;
            if(arr[i][j] == arr[i][j+1]) dp[i][j] = 0;
            if(arr[i][j] == arr[i][j-1]) dp[i][j] = 0;
            if(dp[i][j] == 0) {
                s.insert({0, {i, j}});
            }
        }
	}
	while(!s.empty())
  {
      x = (*s.begin()).second.first;
      y = (*s.begin()).second.second;
      s.erase(s.begin());
      if(visited[x][y]) continue;
      visited[x][y] = 1;

      if(x + 1 <= r) {
          if(arr[x][y] != arr[x+1][y]) {
              if(dp[x+1][y] > dp[x][y] + 1) {
                  dp[x+1][y] = dp[x][y] + 1;
                  s.insert({dp[x+1][y], {x+1, y}});
              }
          }
      }

      if(x - 1 > 0) {
          if(arr[x][y] != arr[x-1][y]) {
              if(dp[x-1][y] > dp[x][y] + 1) {
                  dp[x-1][y] = dp[x][y] + 1;
                  s.insert({dp[x-1][y], {x-1, y}});
              }
          }
      }

      if(y + 1 <= c) {
          if(arr[x][y] != arr[x][y+1]) {
              if(dp[x][y+1] > dp[x][y] + 1) {
                  dp[x][y+1] = dp[x][y] + 1;
                  s.insert({dp[x][y+1], {x, y+1}});
              }
          }
      }

      if(y - 1 > 0) {
          if(arr[x][y] != arr[x][y-1]) {
              if(dp[x][y-1] > dp[x][y] + 1) {
                  dp[x][y-1] = dp[x][y] + 1;
                  s.insert({dp[x][y-1], {x, y-1}});
              }
          }
      }
  }
	while(q--) {
        ll sana;
        scanf("%d %d %lld",&x,&y,&sana);
        int chaeng = arr[x][y] - '0';
        if(dp[x][y] == 1e9) {
            printf("%d\n", chaeng);
            continue;
        }
        if(sana < dp[x][y]) {
            // nothing
        }
        else {
            sana -= dp[x][y];
            if(sana % 2 == 1) chaeng = 1 - chaeng;
 
        }
        printf("%d\n", chaeng);
	}
	return 0;
}