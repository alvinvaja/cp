/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[105];
int sana[105];
int butuh[105];
vector<char> vi[105];
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
	int inc = 1;
	cin >> tc;
	while(tc--)
    {
        cin >> n;
        for(i=1;i<=n;i++) cin >> arr[i];
        memset(sana, 0, sizeof(sana));
        for(i=1;i<=100;i++) vi[i].clear();

        for(i=1;i<=n;i++) {
            butuh[i] = arr[i] - 1;
        }

        printf("Case #%d: ", inc++);
        if(min(arr[1], arr[n]) == 0) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        bool can = 1;
        int carry = 0;
        for(i=1;i<=n;i++) {
            if(butuh[i] > 0) {
                sana[i+1] = -butuh[i];
            } else if(butuh[i] < 0) {
                sana[i] = -butuh[i];
            }
            butuh[i+1] += butuh[i];
        }
        if(sana[1] != 0 ||  sana[n] != 0) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=1;;i++) {
            can = 0;
            for(j=1;j<=n;j++) {
                if(sana[j] == 0) vi[i].push_back('.');
                else {
                    if(sana[j] < 0) {
                        vi[i].push_back('/');
                        sana[j]++;
                        can = 1;
                    } else {
                        vi[i].push_back('\\');
                        sana[j]--;
                        can = 1;
                    }
                }
            }
            if(!can) break;
        }
        printf("%d\n", i);
        for(j=1;j<=i;j++) {
            for(auto x : vi[j]) cout << x;
            cout << endl;
        }
    }
	return 0;
}
