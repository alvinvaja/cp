/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int arr[200200], cnt[200200], dp[200200], c[200200];
vector<int> vi[200200];
bool desc(int a, int b)
{
    return a > b;
}
int main()
{
	int n,i,j,k,x,y,ans,curr,temp,m;
	int tc;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+n+1, desc);
    int now = 0;
    for(i=1;i<=m;i++)
    {
        scanf("%d", &c[i]);
    }
    for(i=1;i<=n;i++)
    {
        now++;
        cnt[arr[i]] = now;
    }
    cnt[1] = n;
    for(i=m;i>0;i--)
    {
        if(cnt[i] == 0) cnt[i] = cnt[i+1];
    }
    int chaeng = n;
    int low = 1;
    int high = n;
    int mid = (low + high) / 2;
    while(low <= high)
    {
        bool can = 1;
        for(i=1;i<=n;i++)
        {
            curr = cnt[arr[i]] / mid;
            if(cnt[arr[i]] % mid) curr++;
            if(curr > c[arr[i]]) can = 0;
        }
        if(can) {
            chaeng = min(chaeng, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    cout << chaeng << endl;
    now = 0;
    for(i=1;i<=n;i++)
    {
        vi[now++].push_back(arr[i]);
        if(now == chaeng) now = 0;
    }
    for(i=0;i<chaeng;i++) {
        printf("%d ", vi[i].size());
        for(auto x : vi[i]) printf("%d ", x);
        printf("\n");
    }
	return 0;
}
